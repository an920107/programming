package A11_110502557.application;

import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

public class SceneController implements AutoCloseable {
    
    private String fxmlPath;
    private Scene scene;
    private Parent root;

    @Override
    public void close() throws Exception {}

    public SceneController(String fxmlPath) {
        this.fxmlPath = fxmlPath;
    }

    public void show(Stage stage) throws IOException {
        root = FXMLLoader.load(getClass().getResource(fxmlPath));
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();

        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
               
            }
        });
    }

    public void show(ActionEvent event) throws IOException {
        show((Stage)((Node)event.getSource()).getScene().getWindow());
    }


    final public class FXMLFiles {
        
        final private static String PREFIX = "../resources/";

        final public static String TITLE_SCREEN = PREFIX + "TitleScreen.fxml";
        final public static String SIMPLE_PLAY = PREFIX + "SimplePlay.fxml";
        final public static String ADVANCED_PLAY = PREFIX + "AdvancedPlay.fxml";
    }
}
