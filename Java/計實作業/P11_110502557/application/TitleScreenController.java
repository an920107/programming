package P11_110502557.application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class TitleScreenController {
    
    @FXML private Button startButton;
    @FXML private Button exitButton;

    @FXML
    private void onStartButton(ActionEvent event) {
        try (SceneController sceneController = new SceneController(FXMLFiles.MAZE)) {
            sceneController.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    @FXML
    private void onExitButton(ActionEvent event) {
        ((Stage)((Node)event.getSource()).getScene().getWindow()).close();
    }
}
