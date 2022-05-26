package main;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class MySQL{
    
    // private final String URL = "jdbc:mysql://finalproject.ddns.net:3306/tradersdb";
    // private final String USERNAME = "tradersuser";
    // private final String PASSWORD = "TRADERSuser";

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

    public static ArrayList<String> getColumn(String table, String column) throws Exception {
        ArrayList<String> list = new ArrayList<>();
        ResultSet resultSet = getResultSet(String.format("SELECT `%s` FROM `%s`", column, table));
        while (resultSet.next()) {
            String str = resultSet.getString(0);
            list.add(str);
        }
        return null;
    }
}
