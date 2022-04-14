package A9_110502557.application;

public class Currency {

    private String name;
    private double rate;

    public Currency(String name, double rate) {
        this.name = name;
        this.rate = rate;
    }

    public String getName() { return name; }
    public double getRate() { return rate; }
}
