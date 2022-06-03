package main;

import java.io.File;
import java.util.ArrayList;

public class Trader {

    private long id;
    private String name;
    private double profit;
    private File photo;
    private ArrayList<TradingData> data;

    public Trader(long id, String name, double profit, File photo, ArrayList<TradingData> data) {
        this.id = id;
        this.name = name;
        this.profit = profit;
        this.photo = photo;
        this.data = data;
    }

    public long getID() { return id; }
    public String getName() { return name; }
    public double getProfit() { return profit; }
    public File getPhoto() { return photo; }
    public ArrayList<TradingData> getData() { return data; }
}