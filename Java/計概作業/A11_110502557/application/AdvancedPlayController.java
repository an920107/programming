package A11_110502557.application;

import java.util.LinkedList;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class AdvancedPlayController {
    
    @FXML private Label statusLabel = new Label();
    @FXML private Button returnButton;
    @FXML private Pane gamePane;
    @FXML private Rectangle head;

    private LinkedList<Rectangle> snake = new LinkedList<>();

    @FXML
    public void initialize() {
        
    }

    public void reset() {

    }

    @FXML
    private void onReturnButton(ActionEvent event) {
        
    }

    public void keyPressed(KeyEvent event) {
        
    }
}
