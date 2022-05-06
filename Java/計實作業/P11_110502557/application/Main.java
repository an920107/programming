package P11_110502557.application;

import javafx.application.Application;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("Walk to Exit");
        stage.setResizable(false);

        try (SceneController sceneController = new SceneController(FXMLFiles.TITLE_SCREEN)) {
            sceneController.show(stage);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
