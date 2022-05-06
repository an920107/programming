package A11_110502557.application.Functions;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class SnakeBody {
    
    private Rectangle rectangle;
    private Vector2D location;
    private Pane gamePane;

    public SnakeBody(Rectangle rectangle, Vector2D location, Pane gamePane) {
        this.rectangle = rectangle;
        this.location = location;
        this.gamePane = gamePane;

        this.rectangle.setFill(Color.GREENYELLOW);
        this.rectangle.setStroke(Color.BLACK);
        this.gamePane.getChildren().add(this.rectangle);
        this.rectangle.relocate(this.location.getX(), this.location.getY());
    }

    public Rectangle getRectangle() { return rectangle; }
    public Vector2D getLocation() { return location; }
}
