package A11_110502557.application;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Food {
    
    private Rectangle rectangle;
    private Vector2D location;
    private Pane gamePane;

    public Food(Rectangle rectangle, Vector2D range, Pane gamePane) {
        this.rectangle = rectangle;
        this.gamePane = gamePane;
        this.location = new Vector2D(
            (int)((int)(Math.random() * range.getX()) * rectangle.getWidth()),
            (int)((int)(Math.random() * range.getY()) * rectangle.getHeight())
        );
        
        this.rectangle.setFill(Color.RED);
        this.rectangle.setStroke(Color.BLACK);
        this.gamePane.getChildren().add(this.rectangle);
        this.rectangle.relocate(this.location.getX(), this.location.getY());
    }

    public Rectangle getRectangle() { return rectangle; }
    public Vector2D getLocation() { return location; }
}
