package main;

import java.text.SimpleDateFormat;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {

        final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH-mm-ss");

        final String URL = "jdbc:mysql://finalproject.ddns.net:3306/tradersdb";
        final String USERNAME = "tradersuser";
        final String PASSWORD = "TRADERSuser";

        MySQL.setConnection(URL, USERNAME, PASSWORD);
        
        ArrayList<Long> topIDs = MySQL.getTop();
        ArrayList<Trader> traders = MySQL.getTraders();

        for (Trader trader : traders) {

            System.out.printf("%-20d %s %f%%\n",
                trader.getID(),
                trader.getName(),
                trader.getProfit()
            );

            int i = 0; // 避免洗屏
            for (TradingData data : trader.getData()) {
                System.out.printf("> %10s %3dx %5s %011.5f %011.5f %s %s %7.2f%%\n",
                    data.getPair(),
                    data.getMultiply(),
                    data.getIsLong() ? "Long" : "Short",
                    data.getOpenPrice(),
                    data.getClosePrice(),
                    DATE_FORMAT.format(data.getOpenTime()),
                    DATE_FORMAT.format(data.getCloseTime()),
                    data.getProfit()
                );
                if (++ i > 2) break; // 避免洗屏
            }

            // trader.getPhoto()
        }
    }
}
