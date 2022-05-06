package A11_110502557.application.Controllers;

import java.io.IOException;

import A11_110502557.application.FXMLFiles;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

public class SceneController implements AutoCloseable {
    
    private FXMLLoader loader;
    private String fxmlPath;
    private Scene scene;
    private Parent root;

    @Override
    public void close() throws Exception {}

    public SceneController(String fxmlPath) {
        this.fxmlPath = fxmlPath;
    }

    public void show(Stage stage) throws IOException {
        loader = new FXMLLoader(getClass().getResource(fxmlPath));
        root = loader.load();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();

        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                if (fxmlPath.equals(FXMLFiles.SIMPLE_PLAY)) {
                    SimplePlayController controller = loader.getController();
                    controller.keyPressed(event);
                }
                else if (fxmlPath.equals(FXMLFiles.ADVANCED_PLAY)) {
                    AdvancedPlayController controller = loader.getController();
                    controller.keyPressed(event);
                }
            }
        });
    }

    public void show(ActionEvent event) throws IOException {
        show((Stage)((Node)event.getSource()).getScene().getWindow());
    }
}
