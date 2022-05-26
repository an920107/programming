package main;

import java.io.File;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {

        final String HOST = "finalproject.ddns.net";
        final String PATH = "/traders-info/";

        ArrayList<String> fileList = new ArrayList<>();

        try (Client client = new Client(HOST, 9217)) {
            client.send(PATH);
            while (true) {
                String response = client.send("NEXT");
                if (response.equals("DONE")) break;
                fileList.add(response);
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }

        
        for (String file : fileList) {
            File filePath = new File(System.getenv("APPDATA") + "/TradersAnalysis" + PATH);
            if (!filePath.exists()) filePath.mkdirs();
            filePath = new File(filePath, file);
            try (DownloadFile downloadFile =
                    new DownloadFile("http://" + HOST + PATH + file, filePath.getPath())) {
                downloadFile.start();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }
}
