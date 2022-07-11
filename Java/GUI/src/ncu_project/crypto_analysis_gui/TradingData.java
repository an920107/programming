package ncu_project.crypto_analysis_gui;

import java.util.Date;

public class TradingData {
    
    private String pair;
    private int multiply;
    private boolean isLong;
    private double openPrice;
    private double closePrice;
    private Date openTime;
    private Date closeTime;
    private double profit;

    public TradingData(String pair, int multiply, boolean isLong, double openPrice,
            double closePrice, Date openTime, Date closeTime, double profit) {
        
        this.pair = pair;
        this.multiply = multiply;
        this.isLong = isLong;
        this.openPrice = openPrice;
        this.closePrice = closePrice;
        this.openTime = openTime;
        this.closeTime = closeTime;
        this.profit = profit;
    }

    public String getPair() { return pair; }
    public int getMultiply() { return multiply; }
    public boolean getIsLong() { return isLong; }
    public double getOpenPrice() { return openPrice; }
    public double getClosePrice() { return closePrice; }
    public Date getOpenTime() { return openTime; }
    public Date getCloseTime() { return closeTime; }
    public double getProfit() { return profit; }
}
