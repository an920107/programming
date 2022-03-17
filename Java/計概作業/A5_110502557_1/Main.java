/**
 * Assignment 05-1
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

package A5_110502557_1;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();
        Scene scene = new Scene(root, 1280, 720, Color.PINK);

        ImageView imageView = new ImageView();
        imageView.setImage(new Image(new FileInputStream("A5_110502557_1/chino.jpg")));
        imageView.setFitHeight(620);
        imageView.setPreserveRatio(true);
        
        Label titleLabel = new Label("ご注文はうさぎですか？");
        titleLabel.setFont(Font.font("UD Digi Kyokasho N-B", 36));

        CheckBox checkBox = new CheckBox("チノちゃんがかわいいね");
        checkBox.setFont(Font.font("UD Digi Kyokasho N-R", 24));

        Label questionLabel = new Label("カフェラテと　カフェモカと　カプチノと\nどちらがいいですか");
        questionLabel.setFont(Font.font("UD Digi Kyokasho N-B", 24));

        final ToggleGroup radioGroup = new ToggleGroup();
        RadioButton radioButton1 = new RadioButton("カフェラテをお願いします。");
        radioButton1.setFont(Font.font("UD Digi Kyokasho N-R", 24));
        radioButton1.setToggleGroup(radioGroup);
        RadioButton radioButton2 = new RadioButton("カフェモカを一杯ください。");
        radioButton2.setFont(Font.font("UD Digi Kyokasho N-R", 24));
        radioButton2.setToggleGroup(radioGroup);
        RadioButton radioButton3 = new RadioButton("やっぱりチノが一番すきだよ。");
        radioButton3.setFont(Font.font("UD Digi Kyokasho N-R", 24));
        radioButton3.setToggleGroup(radioGroup);
        radioButton3.setSelected(true);

        Button button = new Button("送りる");
        button.setFont(Font.font("UD Digi Kyokasho N-R", 24));

        VBox vBox = new VBox();
        vBox.setSpacing(50);

        HBox hBox = new HBox();
        hBox.setPadding(new Insets(50, 50, 50, 50));
        hBox.setSpacing(80);

        vBox.getChildren().addAll(titleLabel, checkBox, questionLabel, radioButton1, radioButton2, radioButton3, button);
        hBox.getChildren().addAll(imageView, vBox);
        root.getChildren().addAll(hBox);

        stage.setTitle("Hello World");
        stage.setResizable(false);
        stage.setScene(scene);
        stage.show();
    }
}
