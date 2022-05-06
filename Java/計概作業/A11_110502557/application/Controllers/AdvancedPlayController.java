package A11_110502557.application.Controllers;

import java.util.LinkedList;

import A11_110502557.application.Constants.FXMLFiles;
import A11_110502557.application.Constants.Status;
import A11_110502557.application.Functions.Food;
import A11_110502557.application.Functions.SnakeBody;
import A11_110502557.application.Functions.Vector2D;
import javafx.animation.AnimationTimer;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Rectangle;

public class AdvancedPlayController implements KeyPressed {

    final private int PANE_SIZE = 500;
    final private int RECT_SIZE = 25;
    final private long PER_SEC = (long)1E9;
    final private long COOL_TIME = (long)(0.25 * PER_SEC); // 1 sec
    
    private LinkedList<SnakeBody> snake = new LinkedList<>();
    private Vector2D direction;
    private Food food;
    private boolean isPlaying;
    private boolean isPlayable;
    
    @FXML private Label statusLabel = new Label();
    @FXML private Button returnButton;
    @FXML private Pane gamePane;
    
    @FXML
    private void initialize() {
        direction = new Vector2D(0, 0);
        isPlayable = true;
        isPlaying = false;
        snake.add(new SnakeBody(
            new Rectangle(RECT_SIZE, RECT_SIZE),
            new Vector2D(PANE_SIZE / 2, PANE_SIZE / 2),
            gamePane
        ));
        food = new Food(
            new Rectangle(RECT_SIZE, RECT_SIZE), 
            new Vector2D(PANE_SIZE / RECT_SIZE, PANE_SIZE / RECT_SIZE),
            gamePane
        );
        statusLabel.setText(Status.PLAYING);
    }

    private void reset() {
        timer.stop();
        for (SnakeBody body : snake)
            gamePane.getChildren().remove(body.getRectangle());
        snake.clear();
        gamePane.getChildren().remove(food.getRectangle());
        initialize();
    }

    @FXML
    private void onReturnButton(ActionEvent event) {
        try (SceneController sc = new SceneController(FXMLFiles.TITLE_SCREEN)) {
            reset();
            sc.show(event);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private boolean bumpIntoBody(LinkedList<SnakeBody> snake) {
        Vector2D headLocation = snake.getFirst().getLocation();
        boolean flag = true;
        for (SnakeBody body : snake) {
            if (flag) {
                flag = false;
                continue;
            }
            if (headLocation.equals(body.getLocation()))
                return true;
        }
        return false;
    }

    private boolean isTurningBack(LinkedList<SnakeBody> snake, Vector2D direction) {
        if (snake.size() <= 1) return false;
        if (snake.getFirst().getLocation().add(direction.multiply(RECT_SIZE)).equals(snake.get(1).getLocation()))
            return true;
        return false;
    }

    @Override
    public void keyPressed(KeyEvent event) {
        if (event.getCode() == KeyCode.SPACE) {
            reset();
            return;
        }
        if (!isPlayable) return;

        Vector2D newDirection;
        switch (event.getCode()) {
            case W: case UP:
                newDirection = new Vector2D(0, -1);
                break;
            case S: case DOWN:
                newDirection = new Vector2D(0, 1);
                break;
            case A: case LEFT:
                newDirection = new Vector2D(-1, 0);
                break;
            case D: case RIGHT:
                newDirection = new Vector2D(1, 0);
                break;
            default: return;
        }
        if (isTurningBack(snake, newDirection)) {
            System.out.println("R");
            return;
        }
        direction = newDirection;
        if (!isPlaying) {
            isPlaying = true;
            timer.start();
        }
    }

    private AnimationTimer timer = new AnimationTimer() {
        static long last = 0;

        public void handle(long now) {
            if (now - last >= COOL_TIME) {
                Vector2D newLocation = snake.getFirst().getLocation().add(direction.multiply(RECT_SIZE));
                
                if (bumpIntoBody(snake)
                        || newLocation.getX() < 0 || newLocation.getX() >= PANE_SIZE
                        || newLocation.getY() < 0 || newLocation.getY() >= PANE_SIZE) {
                    isPlayable = false;
                    isPlaying = false;
                    statusLabel.setText(Status.DIED);
                    timer.stop();
                    return;
                }

                snake.addFirst(new SnakeBody(
                    new Rectangle(RECT_SIZE, RECT_SIZE),
                    snake.getFirst().getLocation().add(direction.multiply(RECT_SIZE)),
                    gamePane
                ));

                if (snake.getFirst().getLocation().equals(food.getLocation())) {
                    gamePane.getChildren().remove(food.getRectangle());
                    while (true) {
                        food = new Food(
                            new Rectangle(RECT_SIZE, RECT_SIZE),
                            new Vector2D(PANE_SIZE / RECT_SIZE, PANE_SIZE / RECT_SIZE),
                            gamePane
                        );
                        for (SnakeBody body : snake)
                            if (food.getLocation().equals(body.getLocation()))
                                continue;
                        break;
                    }
                }
                else {
                    gamePane.getChildren().remove(snake.getLast().getRectangle());
                    snake.removeLast();
                }
                
                // System.out.println((double)(now - last) / PER_SEC);
                last = now;
            }
        };
    };
}
