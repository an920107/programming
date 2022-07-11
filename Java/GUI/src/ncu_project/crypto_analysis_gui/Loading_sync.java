package ncu_project.crypto_analysis_gui;

import javafx.concurrent.Task;

public class Loading_sync extends Task<Void> {
    @Override
    protected Void call() throws Exception {
        final String URL = "jdbc:mysql://finalproject.ddns.net:3306/tradersdb";
        final String USERNAME = "tradersuser";
        final String PASSWORD = "TRADERSuser";
        try {
            MySQL.setConnection(URL, USERNAME, PASSWORD);
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void succeeded() {
        super.succeeded();
    }
}
