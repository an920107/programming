package A6_110502557;

import java.util.LinkedList;

public class Transactions extends LinkedList<Transaction> {
    private int maxNameLength = 0;
    private int maxIncomeLength = 0;
    private int maxPayLength = 0;

    public Transactions() {}

    @Override
    public void addLast(Transaction transaction) {
        maxNameLength = max(transaction.getName().length(), maxNameLength);
        super.addLast(transaction);
    }

    public void setLastIncome(int income) {
        maxIncomeLength = max(String.valueOf(income).length(), maxIncomeLength);
        super.getLast().setIncome(income);
    }

    public void setLastPay(int pay) {
        maxPayLength = max(String.valueOf(pay).length(), maxPayLength);
        super.getLast().setPay(pay);
    }

    public int getMaxNameLength() { return maxNameLength; }
    public int getMaxIncomeLength() { return maxIncomeLength; }
    public int getMaxPayLength() { return maxPayLength; }

    private int max(int x, int y) {
        return (x > y) ? x : y;
    }
}
