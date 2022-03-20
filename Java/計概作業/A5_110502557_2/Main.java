/**
 * Assignment 05-2
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

package A5_110502557_2;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class Main extends Application implements EventHandler<ActionEvent> {

    TextField textField = new TextField();
    RadioButton radioButton1 = new RadioButton("A");
    RadioButton radioButton2 = new RadioButton("B");
    CheckBox checkBox = new CheckBox("CheckBox");
    Button textFieldButton = new Button("press1");
    Button radioBtnButton = new Button("press2");
    Button checkBoxButton = new Button("press3");

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();
        Scene scene = new Scene(root, 290, 160);

        final ToggleGroup radioGroup = new ToggleGroup();
        radioButton1.setToggleGroup(radioGroup);
        radioButton2.setToggleGroup(radioGroup);
        radioButton1.setSelected(true);

        textFieldButton.setOnAction(this);
        radioBtnButton.setOnAction(this);
        checkBoxButton.setOnAction(this);

        HBox hBox = new HBox();
        hBox.setSpacing(10);
        hBox.setAlignment(Pos.CENTER_LEFT);

        GridPane gridPane = new GridPane();
        gridPane.setVgap(10);
        gridPane.setHgap(20);
        gridPane.setPadding(new Insets(30, 30, 30, 30));
        gridPane.setAlignment(Pos.CENTER_LEFT);

        hBox.getChildren().addAll(radioButton1, radioButton2);
        gridPane.add(textField, 0, 0);
        gridPane.add(hBox, 0, 1);
        gridPane.add(checkBox, 0, 2);
        gridPane.add(textFieldButton, 1, 0);
        gridPane.add(radioBtnButton, 1, 1);
        gridPane.add(checkBoxButton, 1, 2);
        root.getChildren().addAll(gridPane);

        stage.setTitle("Hello World");
        stage.setResizable(false);
        stage.setScene(scene);
        stage.show();
    }

    @Override
    public void handle(ActionEvent event) {
        if (event.getSource() == textFieldButton) {
            System.out.println(textField.getText());
        }
        if (event.getSource() == radioBtnButton) {
            System.out.println(radioButton1.selectedProperty().getValue() ? "A" : "B");
        }
        if (event.getSource() == checkBoxButton) {
            System.out.println(checkBox.selectedProperty().getValue() ? "true" : "false");
        }
    }
}
