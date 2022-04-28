/**
 * Assignment 10-2
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

package A10_110502557_2.application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        try {
            Parent root = FXMLLoader.load(getClass().getResource("../resources/Main.fxml"));
            Scene scene = new Scene(root);
            stage.setTitle("Bounding Ball Animation");
            stage.setResizable(false);
            stage.setScene(scene);
            stage.show();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
