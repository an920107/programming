package main;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.sql.Blob;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.LinkedList;

public class MySQL{
    
    // private final String URL = "jdbc:mysql://finalproject.ddns.net:3306/tradersdb";
    // private final String USERNAME = "tradersuser";
    // private final String PASSWORD = "TRADERSuser";

    // private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    private static String url;
    private static String username;
    private static String password;

    private static ArrayList<Trader> top;
    private static ArrayList<Trader> traders;
    

    public static void setConnection(String url, String username, String password) throws Exception {
        MySQL.url = url;
        MySQL.username = username;
        MySQL.password = password;
        top = getTradersByCommand("SELECT * FROM `info`, `top` WHERE `top`.`top_id` = `info`.`info_id`;");
        traders = getTradersByCommand("SELECT * FROM `info` ORDER BY `info_profit`");
    }

    public static ResultSet getResultSet(String sql) throws Exception {
        Connection connection = DriverManager.getConnection(url, username, password);
        Statement statement = connection.createStatement();
        return statement.executeQuery(sql);
    }

    public static ArrayList<Trader> getTop() { return top; }
    public static ArrayList<Trader> getTraders() throws Exception { return traders; }

    public static ArrayList<Trader> getTraders(String regex) throws Exception {
        ArrayList<Trader> newTraders = new ArrayList<>();
        for (var trader : traders) {
            if (trader.getName().contains(regex))
                newTraders.add(trader);
        }
        return newTraders;
    }



    private static ArrayList<Trader> getTradersByCommand(String command) throws Exception {

        final File PHOTO_PATH = new File(System.getenv("APPDATA") + "/HotTrader/photos/");
        if (!PHOTO_PATH.exists()) PHOTO_PATH.mkdirs();

        LinkedList<Trader> traders = new LinkedList<>();
        ResultSet infoResultSet = getResultSet(command);
        
        while (infoResultSet.next()) {

            traders.add(new Trader(
                infoResultSet.getLong("info_id"),
                infoResultSet.getString("info_name"),
                infoResultSet.getDouble("info_profit"),
                new File(PHOTO_PATH, String.valueOf(infoResultSet.getLong("info_id")) + ".jpg")
            ));
            writeBlobFile(traders.getLast().getPhoto(), infoResultSet.getBlob("info_photo"));

            ResultSet pairResultSet = getResultSet(String.format(
                "SELECT `data_pair`, COUNT(*) FROM `data` WHERE `data_id` = %d GROUP BY `data_pair` ORDER BY COUNT(*) DESC LIMIT 4;",
                traders.getLast().getID()
            ));
            while (pairResultSet.next()) {
                String str = pairResultSet.getString("data_pair");
                traders.getLast().getPairs().add(str.substring(0, str.indexOf("/")));
            }


            // ResultSet dataResultSet = getResultSet(String.format(
            //     "SELECT * FROM `data` WHERE `data_id` = %d", traders.getLast().getID()));
            // while (dataResultSet.next()) {
            //     traders.getLast().getData().add(new TradingData(
            //         dataResultSet.getString("data_pair"),
            //         dataResultSet.getInt("data_multiply"),
            //         dataResultSet.getBoolean("data_isLong"),
            //         dataResultSet.getDouble("data_openPrice"),
            //         dataResultSet.getDouble("data_closePrice"),
            //         DATE_FORMAT.parse(dataResultSet.getString("data_openTime")),
            //         DATE_FORMAT.parse(dataResultSet.getString("data_closeTime")),
            //         dataResultSet.getDouble("data_profit")
            //     ));
            // }
        }

        return new ArrayList<>(traders);
    }

    private static void writeBlobFile(File file, Blob blob) throws Exception {

        InputStream in = blob.getBinaryStream();
        OutputStream out = new FileOutputStream(file);
        byte[] buff = new byte[4096];
        int len = 0;

        while ((len = in.read(buff)) != -1) {
            out.write(buff, 0, len);
        }

        out.close();
    }
}
