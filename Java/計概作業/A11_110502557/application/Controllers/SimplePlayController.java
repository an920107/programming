package A11_110502557.application.Controllers;

import A11_110502557.application.Constants.FXMLFiles;
import A11_110502557.application.Constants.Status;
import A11_110502557.application.Functions.Vector2D;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;

public class SimplePlayController implements KeyPressed{
    
    @FXML private Label statusLabel = new Label();
    @FXML private Button returnButton;
    @FXML private Button advancedButton;
    @FXML private GridPane gridPane;

    private Pane[][] gridsBackground;
    private Vector2D lastDirection;
    private Vector2D headLocation;
    private Vector2D tailLocation;
    private boolean isPlayable;

    @FXML
    private void initialize() {
        gridsBackground = new Pane[gridPane.getColumnCount()][gridPane.getRowCount()];
        for (int i = 0; i < gridPane.getColumnCount(); i ++) {
            for (int j = 0; j < gridPane.getRowCount(); j ++) {
                gridsBackground[i][j] = new Pane();
                gridPane.add(gridsBackground[i][j], i, j);
            } 
        }
        reset();
    }

    @FXML
    private void onReturnButton(ActionEvent event) {
        try (SceneController sc = new SceneController(FXMLFiles.TITLE_SCREEN)) {
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    @FXML
    private void onAdvancedButton(ActionEvent event) {
        try (SceneController sc = new SceneController(FXMLFiles.ADVANCED_PLAY)) {
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void reset() {
        isPlayable = true;
        lastDirection = new Vector2D(0, 0);
        headLocation = new Vector2D(0, 0);
        tailLocation = new Vector2D(0, 0);
        statusLabel.setText(Status.PLAYING);
        for (int i = 0; i < gridPane.getColumnCount(); i ++) {
            for (int j = 0; j < gridPane.getRowCount(); j ++) {
                gridsBackground[i][j].setBackground(new Background(new BackgroundFill(Color.TRANSPARENT, CornerRadii.EMPTY, Insets.EMPTY)));
            } 
        }
        gridsBackground[0][0].setBackground(new Background(new BackgroundFill(Color.BLACK, CornerRadii.EMPTY, Insets.EMPTY)));
        gridsBackground[4][4].setBackground(new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY)));
    }

    @Override
    public void keyPressed(KeyEvent event) {
        if (event.getCode() == KeyCode.SPACE) reset();
        if (!isPlayable) return;
        switch (event.getCode()) {
            case W: case UP:
                if (lastDirection.getY() == 1) return;
                headLocation.setY(headLocation.getY() - 1);
                lastDirection = new Vector2D(0, -1);
                break;
            case S: case DOWN:
                if (lastDirection.getY() == -1) return;
                headLocation.setY(headLocation.getY() + 1);
                lastDirection = new Vector2D(0, 1);
                break;
            case A: case LEFT:
                if (lastDirection.getX() == 1) return;
                headLocation.setX(headLocation.getX() - 1);
                lastDirection = new Vector2D(-1, 0);
                break;
            case D: case RIGHT:
                if (lastDirection.getX() == -1) return;
                headLocation.setX(headLocation.getX() + 1);
                lastDirection = new Vector2D(1, 0);
                break;
            default: return;
        }
        if (headLocation.getX() < 0 || headLocation.getX() >= gridPane.getColumnCount()
                || headLocation.getY() < 0 || headLocation.getY() >= gridPane.getRowCount()) {
            statusLabel.setText(Status.DIED);
            isPlayable = false;
            return;
        }
        gridsBackground[tailLocation.getX()][tailLocation.getY()].setBackground(
            new Background(new BackgroundFill(Color.TRANSPARENT, CornerRadii.EMPTY, Insets.EMPTY))
        );
        gridsBackground[headLocation.getX()][headLocation.getY()].setBackground(
            new Background(new BackgroundFill(Color.BLACK, CornerRadii.EMPTY, Insets.EMPTY))
        );
        tailLocation = headLocation.minus(lastDirection);
        gridsBackground[tailLocation.getX()][tailLocation.getY()].setBackground(
            new Background(new BackgroundFill(Color.BLACK, CornerRadii.EMPTY, Insets.EMPTY))
        );
        if (headLocation.equals(new Vector2D(4, 4))) {
            statusLabel.setText(Status.WINNED);
            isPlayable = false;
            return;
        }
    }
}
