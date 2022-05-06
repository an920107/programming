package application;

public class Vector2D {
    private double x;
    private double y;

    public Vector2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() { return x; }
    public double getY() { return y; }
    public void setX(double x) { this.x = x; }
    public void setY(double y) { this.y = y; }

    public Vector2D add(Vector2D v) {
        return new Vector2D(x + v.x, y + v.y);
    }

    public Vector2D minus(Vector2D v) {
        return new Vector2D(x - v.x, y - v.y);
    }

    public Vector2D multiply(double m) {
        return new Vector2D(x * m, y * m);
    }

    public boolean equals(Vector2D v) {
        return x == v.x && y == v.y;
    }
}
