package P11_110502557.application;

import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class SceneController implements AutoCloseable {
    
    private String fxmlPath;
    private FXMLLoader loader;
    private Scene scene;

    public SceneController(String fxmlPath) {
        this.fxmlPath = fxmlPath;
    }

    public void show(Stage stage) throws IOException {
        loader = new FXMLLoader(getClass().getResource(fxmlPath));
        scene = new Scene((Parent)loader.load());
        stage.setScene(scene);
        stage.show();

        scene.setOnKeyPressed(keyEvent -> {
            Object controller = loader.getController();
            if (controller instanceof KeyPressed)
                ((KeyPressed)controller).keyPressed(keyEvent);
        });
    }

    public void show(ActionEvent event) throws IOException {
        show((Stage)((Node)event.getSource()).getScene().getWindow());
    }

    @Override
    public void close() throws Exception {
        System.gc();
    }
}
