package ncu_project.crypto_analysis_gui;

import java.io.File;
import java.util.ArrayList;

public class Trader {

    private long id;
    private String name;
    private double profit;
    private File photo;
    private ArrayList<String> pairs;

    public Trader(long id, String name, double profit, File photo) {
        this.id = id;
        this.name = name;
        this.profit = profit;
        this.photo = photo;
        this.pairs = new ArrayList<>();
    }

    public long getID() { return id; }
    public String getName() { return name; }
    public double getProfit() { return profit; }
    public File getPhoto() { return photo; }
    public ArrayList<String> getPairs() { return pairs; }
}