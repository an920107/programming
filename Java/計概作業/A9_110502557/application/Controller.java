package A9_110502557.application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class Controller {

    @FXML private TextField inputTextField = new TextField();
    @FXML private ChoiceBox<Currency> sourceChoiceBox = new ChoiceBox<>();
    @FXML private ChoiceBox<Currency> objectChoiceBox = new ChoiceBox<>();
    @FXML private Button switchButton;
    @FXML private Button countButton;
    @FXML private Label resultLabel = new Label();

    private int originalSourceIndex;
    private int origibalObjectIndex;

    private final String NUMBERS = "1234567890";
    private final Currency CURRENCIES[] = {
        new Currency("美元", 1d),
        new Currency("台幣", 29.42d),
        new Currency("日圓", 124.819687d),
        new Currency("歐元", 0.913381d),
        new Currency("人民幣", 6.347357d)
    };

    @FXML
    public void initialize() {
        sourceChoiceBox.setConverter(new CurrencyToString());
        objectChoiceBox.setConverter(new CurrencyToString());
        sourceChoiceBox.getItems().addAll(CURRENCIES);
        objectChoiceBox.getItems().addAll(CURRENCIES);
        sourceChoiceBox.getSelectionModel().select(0);
        objectChoiceBox.getSelectionModel().select(1);
        originalSourceIndex = 0;
        origibalObjectIndex = 1;
    }

    /** Listeners */
    public void onSourceChoiceBox(ActionEvent event) {
        if (isSameIndex(sourceChoiceBox, objectChoiceBox)) {
            sourceChoiceBox.getSelectionModel().select(originalSourceIndex);
            switchChoiceBox(sourceChoiceBox, objectChoiceBox);
        }
        originalSourceIndex = sourceChoiceBox.getSelectionModel().getSelectedIndex();
    }

    public void onObjectChoiceBox(ActionEvent event) {
        if (isSameIndex(sourceChoiceBox, objectChoiceBox)) {
            objectChoiceBox.getSelectionModel().select(origibalObjectIndex);
            switchChoiceBox(sourceChoiceBox, objectChoiceBox);
        }
        origibalObjectIndex = objectChoiceBox.getSelectionModel().getSelectedIndex();
    }

    public void onSwitchButton(ActionEvent event) {
        switchChoiceBox(sourceChoiceBox, objectChoiceBox);
    }

    public void onCountButton(ActionEvent event) {
        final String inputStr = inputTextField.getText();
        double input;
        double result;
        if (isFloatNumber(inputStr)) {
            input = Double.parseDouble(inputStr);
            result = input * getRate(sourceChoiceBox, objectChoiceBox);
            result = Math.round(result * 1000d) / 1000d;
            resultLabel.setText(String.format(
                "%.3f %s = %.3f %s",
                input, sourceChoiceBox.getSelectionModel().getSelectedItem().getName(),
                result, objectChoiceBox.getSelectionModel().getSelectedItem().getName()
            ));
        }
    }

    /** Custom Methods */
    private void switchChoiceBox(ChoiceBox<Currency> x, ChoiceBox<Currency> y) {
        int index = x.getSelectionModel().getSelectedIndex();
        x.getSelectionModel().select(y.getSelectionModel().getSelectedIndex());
        y.getSelectionModel().select(index);
    }

    private boolean isSameIndex(ChoiceBox<Currency> x, ChoiceBox<Currency> y) {
        return x.getSelectionModel().getSelectedIndex() == y.getSelectionModel().getSelectedIndex();
    }

    private double getRate(ChoiceBox<Currency> x, ChoiceBox<Currency> y) {
        return (double)(
            y.getSelectionModel().getSelectedItem().getRate() /
            x.getSelectionModel().getSelectedItem().getRate()
        );
    }

    private boolean isFloatNumber(String str) {
        boolean hasPoint = false;
        if (str == null || str.length() == 0) return false;
        for (char ch : str.toCharArray()) {
            if (ch == '.') {
                if (hasPoint) return false;
                hasPoint = true;
                continue;
            }
            if (NUMBERS.indexOf(ch) < 0) return false;
        }
        return true;
    }
}
