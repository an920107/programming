package A10_110502557_2.application;

public class Point {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() { return x; }
    public double getY() { return y; }
    public void setX(double x) { this.x = x; }
    public void setY(double y) { this.y = y; }

    public double getDistance(Point p) { 
        double dx = p.x - x;
        double dy = p.y - y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public void applyMultiply(double multiply) {
        x *= multiply;
        y *= multiply;
    }
}
