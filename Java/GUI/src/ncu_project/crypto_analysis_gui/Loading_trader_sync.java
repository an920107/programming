package ncu_project.crypto_analysis_gui;

import javafx.concurrent.Task;


public class Loading_trader_sync extends Task<Void> {
    static String html="";
    static String request_id_pair="";
    @Override
    protected Void call() throws Exception {
        try (loading_chart_client client = new loading_chart_client("finalproject.ddns.net", 9217)) {
            if (!client.send(request_id_pair).equals("BEGIN"))
                throw new Exception();
            while (true) {
                String line = client.receive();
                if (line.equals("END")) break;
                html=html+line+"\n";
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void succeeded() {
        super.succeeded();
    }
}
