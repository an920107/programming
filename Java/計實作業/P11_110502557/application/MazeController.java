package P11_110502557.application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;

public class MazeController implements KeyPressed {
    
    @FXML private Label statusLabel;
    @FXML private Button returnButton;
    @FXML private GridPane gridPane;
    @FXML private Pane player;

    private Vector2D playerLocation;
    private boolean isPlayable;

    @FXML
    private void initialize() {
        isPlayable = true;
        statusLabel.setVisible(false);
        playerLocation = new Vector2D(0, 0);
        setLocation(playerLocation);
    }

    @FXML
    private void onReturnButton(ActionEvent event) {
        try (SceneController sceneController = new SceneController(FXMLFiles.TITLE_SCREEN)) {
            sceneController.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void setLocation(Vector2D location) {
        gridPane.getChildren().remove(player);
        gridPane.add(player, location.getX(), location.getY());
    }
    
    @Override
    public void keyPressed(KeyEvent keyEvent) {
        System.out.println(keyEvent.getCode());

        if (keyEvent.getCode() == KeyCode.SPACE) {
            initialize();
            return;
        }
        if (!isPlayable) return;

        Vector2D newLocation;
        switch (keyEvent.getCode()) {
            case W: case UP:
            newLocation = playerLocation.add(new Vector2D(0, -1));
            break;
            case S: case DOWN:
            newLocation = playerLocation.add(new Vector2D(0, 1));
            break;
            case A: case LEFT:
            newLocation = playerLocation.add(new Vector2D(-1, 0));
            break;
            case D: case RIGHT:
            newLocation = playerLocation.add(new Vector2D(1, 0));
            break;
            default: return;
        }

        if (newLocation.getX() < 0) return;
        if (newLocation.getY() < 0) return;
        if (newLocation.getX() >= gridPane.getColumnCount()) return;
        if (newLocation.getY() >= gridPane.getRowCount()) return;

        playerLocation = newLocation;
        setLocation(playerLocation);

        if (playerLocation.equals(new Vector2D(4, 4))) {
            statusLabel.setVisible(true);
            isPlayable = false;
            return;
        }
    }
}
