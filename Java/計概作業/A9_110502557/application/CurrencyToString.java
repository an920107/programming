package A9_110502557.application;

import javafx.util.StringConverter;

public class CurrencyToString extends StringConverter<Currency> {
    @Override
    public String toString(Currency curr) {
        return curr.getName();
    }

    @Override
    public Currency fromString(String str) {
        return new Currency(str, 1d);
    }
}
