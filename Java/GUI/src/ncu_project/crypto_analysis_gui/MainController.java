package ncu_project.crypto_analysis_gui;

import javafx.application.Application;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class MainController extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        //stage.initStyle(StageStyle.TRANSPARENT);

        SceneController.stage = stage;
        SceneController.show(SceneController.Scenes.LOADING,true);
        stage.getIcons().add(new Image(MainController.class.getResource("/resources/hot-face.png").toExternalForm()));
        stage.setTitle("HotTrader");

        stage.show();

        //MySQL.setConnection("jdbc:mysql://finalproject.ddns.net:3306/tradersdb", "tradersuser", "TRADERSuser");
    }

    public static void main(String[] args) {
        launch();
    }
}
