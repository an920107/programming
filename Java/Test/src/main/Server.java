package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        
        System.out.println("Server started.");

        final int TIMEOUT = 500;
        final String PATH = "/var/www/html";

        InputStreamReader inputStreamReader = null;
        OutputStreamWriter outputStreamWriter = null;
        BufferedReader reader = null;
        BufferedWriter writer = null;
        Socket socket = null;
        ServerSocket serverSocket = new ServerSocket(9217);

        try {
            while (true) {

                socket = serverSocket.accept();
                socket.setSoTimeout(TIMEOUT);
                inputStreamReader = new InputStreamReader(socket.getInputStream());
                outputStreamWriter = new OutputStreamWriter(socket.getOutputStream());
                reader = new BufferedReader(inputStreamReader);
                writer = new BufferedWriter(outputStreamWriter);

                
                try {
                    String folderPath = readMessage(reader);
                    if (folderPath != null && !folderPath.equals("/") && new File(PATH + folderPath).exists())
                        sendMessage(writer, "ACCEPT");
                    else {
                        sendMessage(writer, "REJECT");
                        throw new Exception();
                    }
                    File[] filesArray = new File(PATH + folderPath).listFiles();
                    for (int i = 0; i < filesArray.length; ) {
                        String command = readMessage(reader);
                        if (command.equals("NEXT")) {
                            sendMessage(writer, filesArray[i].getName());
                            i ++;
                        }
                        else break;
                    }
                    sendMessage(writer, "DONE");
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
                

                socket.close();
                inputStreamReader.close();
                outputStreamWriter.close();
                reader.close();
                writer.close();

            }
        } catch (Exception exception) {
            exception.printStackTrace();

        } finally {

            if (socket != null) socket.close();
            if (inputStreamReader != null) inputStreamReader.close();
            if (outputStreamWriter != null) outputStreamWriter.close();
            if (reader != null) reader.close();
            if (writer != null) writer.close();
            if (serverSocket != null) serverSocket.close();

        }
    }



    private static void sendMessage(BufferedWriter writer, String message) throws IOException {
        System.out.println("[SERVER] " + message);
        writer.write(message);
        writer.newLine();
        writer.flush();
    }

    private static String readMessage(BufferedReader reader) throws IOException {
        String line = reader.readLine();
        System.out.println("[CLIENT] " + line);
        return line;
    }
}
