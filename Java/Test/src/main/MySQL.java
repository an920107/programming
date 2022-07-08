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
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.LinkedList;

public class MySQL{
    
    // private final String URL = "jdbc:mysql://finalproject.ddns.net:3306/tradersdb";
    // private final String USERNAME = "tradersuser";
    // private final String PASSWORD = "TRADERSuser";

    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    private static String url;
    private static String username;
    private static String password;
    

    public static void setConnection(String url, String username, String password) {
        MySQL.url = url;
        MySQL.username = username;
        MySQL.password = password;
    }

    public static ResultSet getResultSet(String sql) throws Exception {
        Connection connection = DriverManager.getConnection(url, username, password);
        Statement statement = connection.createStatement();
        return statement.executeQuery(sql);
    }

    public static ArrayList<Long> getTop() throws Exception {
        ArrayList<Long> list = new ArrayList<>();
        ResultSet resultSet = getResultSet("SELECT * FROM `top`");
        while (resultSet.next()) {
            list.add(resultSet.getLong(1));
        }
        return list;
    }

    public static ArrayList<Trader> getTraders() throws Exception {

        final File PHOTO_PATH = new File(System.getenv("APPDATA") + "/HotTrader/photos/");
        if (!PHOTO_PATH.exists()) PHOTO_PATH.mkdirs();

        LinkedList<Trader> traders = new LinkedList<>();
        ResultSet infoResultSet = getResultSet("SELECT * FROM `info` ORDER BY `info_profit`");
        
        while (infoResultSet.next()) {

            traders.add(new Trader(
                infoResultSet.getLong("info_id"),
                infoResultSet.getString("info_name"),
                infoResultSet.getDouble("info_profit"),
                new File(PHOTO_PATH, String.valueOf(infoResultSet.getLong("info_id")) + ".jpg"),
                new ArrayList<TradingData>()
            ));
            writeBlobFile(traders.getLast().getPhoto(), infoResultSet.getBlob("info_photo"));

            ResultSet dataResultSet = getResultSet(String.format(
                "SELECT * FROM `data` WHERE `data_id` = %d", traders.getLast().getID()));
            while (dataResultSet.next()) {
                traders.getLast().getData().add(new TradingData(
                    dataResultSet.getString("data_pair"),
                    dataResultSet.getInt("data_multiply"),
                    dataResultSet.getBoolean("data_isLong"),
                    dataResultSet.getDouble("data_openPrice"),
                    dataResultSet.getDouble("data_closePrice"),
                    DATE_FORMAT.parse(dataResultSet.getString("data_openTime")),
                    DATE_FORMAT.parse(dataResultSet.getString("data_closeTime")),
                    dataResultSet.getDouble("data_profit")
                ));
            }
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
