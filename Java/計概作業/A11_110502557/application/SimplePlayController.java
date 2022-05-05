package A11_110502557.application;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;

public class SimplePlayController implements Initializable {
    
    @FXML private Button returnButton;
    @FXML private Button advancedButton;
    @FXML private GridPane gridPane;

    private Pane[][] gridsBackground;

    @Override
    public void initialize(URL url, ResourceBundle resource) {
        gridsBackground = new Pane[gridPane.getColumnCount()][gridPane.getRowCount()];
        for (int i = 0; i < gridPane.getColumnCount(); i ++) {
            for (int j = 0; j < gridPane.getRowCount(); j ++) {
                gridsBackground[i][j] = new Pane();
                gridPane.add(gridsBackground[i][j], i, j);
            } 
        }
        gridsBackground[0][0].setBackground(new Background(new BackgroundFill(Color.web("#000000"), CornerRadii.EMPTY, Insets.EMPTY)));
        gridsBackground[4][4].setBackground(new Background(new BackgroundFill(Color.web("#FF0000"), CornerRadii.EMPTY, Insets.EMPTY)));
    }

    @FXML
    private void onReturnButton(ActionEvent event) {
        try (SceneController sc = new SceneController(SceneController.FXMLFiles.TITLE_SCREEN)) {
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    @FXML
    private void onAdvancedButton(ActionEvent event) {
        try (SceneController sc = new SceneController(SceneController.FXMLFiles.ADVANCED_PLAY)) {
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
