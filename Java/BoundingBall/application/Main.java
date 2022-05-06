package application;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();
        Scene scene = new Scene(root, 1280, 720);

        Circle circle = new Circle(10);
        root.getChildren().addAll(circle);

        stage.setScene(scene);
        stage.setTitle("BoundingBall");
        stage.setResizable(false);
        stage.show();
    }
}
