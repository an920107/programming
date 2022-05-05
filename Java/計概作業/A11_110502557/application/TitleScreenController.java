package A11_110502557.application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class TitleScreenController {
    
    @FXML private Button startButton;
    @FXML private Button exitButton;

    @FXML private void onStartButton(ActionEvent event) {
        try (SceneController sc = new SceneController(FXMLFiles.SIMPLE_PLAY)) {
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    @FXML private void onExitButton(ActionEvent event) {
        Stage stage = (Stage)exitButton.getScene().getWindow();
        stage.close();
    }
}
