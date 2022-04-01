package A7_110502557.application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Controller{

    Formula formula = new Formula();

    @FXML private TextField textField = new TextField();
    @FXML private Button zeroButton;
    @FXML private Button oneButton;
    @FXML private Button twoButton;
    @FXML private Button threeButton;
    @FXML private Button fourButton;
    @FXML private Button fiveButton;
    @FXML private Button sixButton;
    @FXML private Button sevenButton;
    @FXML private Button eightButton;
    @FXML private Button nineButton;
    @FXML private Button tenButton;
    @FXML private Button pointButton;
    @FXML private Button plusButton;
    @FXML private Button minusButton;
    @FXML private Button mutiplyButton;
    @FXML private Button divideButton;
    @FXML private Button modButton;
    @FXML private Button powerButton;
    @FXML private Button equalButton;
    @FXML private Button clearButton;
    @FXML private Button backspaceButton;

    public void onNumberButton(ActionEvent event) {
        formula.addLast(new Operand(
            Operand.Type.NUMBER, 
            ((Button)event.getSource()).getText()
        ));
        textField.setText(formula.toString());
    }

    public void onOperatorButton(ActionEvent event) {
        formula.addLast(new Operand(
            Operand.Type.OPERATOR,
            ((Button)event.getSource()).getText()
        ));
        textField.setText(formula.toString());
    }

    public void onMinusButton(ActionEvent event) {
        formula.addLast(new Operand(
            Operand.Type.NEGTIVE,
            ((Button)event.getSource()).getText()
        ));
        textField.setText(formula.toString());
    }

    public void onPointButton(ActionEvent event) {
        formula.addLast(new Operand(
            Operand.Type.POINT,
            ((Button)event.getSource()).getText()
        ));
        textField.setText(formula.toString());
    }

    public void onClearButton(ActionEvent event) {
        formula.clear();
        textField.setText(formula.toString());
    }

    public void onBackspaceButton(ActionEvent event) {
        formula.removeLast();
        textField.setText(formula.toString());
    }

    public void onEqualButton(ActionEvent event) {
        
    }
}
