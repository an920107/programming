package main;

public class Main {
    public static void main(String[] args) throws Exception {

        // try (Client client = new Client("finalproject.ddns.net", 9217)) {
        try (Client client = new Client("localhost", 9217)) {

            if (!client.send("1032343722175987716-BTC").equals("BEGIN"))
                throw new Exception();
            while (true) {
                String line = client.receive();
                if (line.equals("END")) break;
            }
        }
        
    }
}
