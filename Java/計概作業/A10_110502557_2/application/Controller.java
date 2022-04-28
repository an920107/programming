package A10_110502557_2.application;

import javafx.animation.AnimationTimer;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Cursor;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;

public class Controller {

    @FXML private Circle ball;
    @FXML private Button resetButton;
    @FXML private Pane pane;

    private Point startPoint, endPoint;
    private AnimationTimer animation;
    private boolean isAnimating = false;
	
    @FXML
    private void onResetButton(ActionEvent event) {
        ball.relocate(
            pane.getWidth() / 2 - ball.getRadius(),
            pane.getHeight() / 2 - ball.getRadius()
        );
        ball.setCursor(Cursor.HAND);
        animation.stop();
        isAnimating = false;
    }

    @FXML
    private void onBallDragDetaction(MouseEvent event) {
        if (isAnimating) return;
        startPoint = new Point(event.getX(), event.getY());
        event.consume();
    }

    @FXML
    private void onBallDragDone(MouseEvent event) {
        if (isAnimating) return;
        endPoint = new Point(event.getX(), event.getY());
        animation = new CircleAnimation(
            ball,
            new Point(endPoint.getX() - startPoint.getX(), endPoint.getY() - startPoint.getX()),
            new Point(pane.getWidth(), pane.getHeight())
        );
        animation.start();
        isAnimating = true;
    }
}

class CircleAnimation extends AnimationTimer {
    private Circle ball;
    private Point velocity, boundary, location;
    private final double MULTIPLY = 0.03;

    public CircleAnimation(Circle ball, Point velocity, Point boundary) {
        this.ball = ball;
        this.velocity = velocity;
        this.boundary = boundary;
        this.velocity.applyMultiply(-MULTIPLY);
        this.location = new Point(
            boundary.getX() / 2 - ball.getRadius(),
            boundary.getY() / 2 - ball.getRadius()
        );
    }

    @Override
    public void handle(long now) {
        Point newPoint = new Point(
            location.getX() + velocity.getX(),
            location.getY() + velocity.getY()
        );

        if (newPoint.getX() < 0) // too left
            velocity.setX(-velocity.getX());
        if (newPoint.getX() > boundary.getX() - ball.getRadius() * 2) // too right
            velocity.setX(-velocity.getX());
        if (newPoint.getY() < 0) // too up
            velocity.setY(-velocity.getY());
        if (newPoint.getY() > boundary.getY() - ball.getRadius() * 2) // too down
            velocity.setY(-velocity.getY());

        ball.relocate(newPoint.getX(), newPoint.getY());
        location.setX(newPoint.getX());
        location.setY(newPoint.getY());
    }
}