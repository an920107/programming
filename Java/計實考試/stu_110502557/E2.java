package stu_110502557;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;

public class E2 {
    public static void main(String[] args) {
        int sum;
        String pointsStr, circlesStr, lineStr;
        ArrayList<Point> points = new ArrayList<>();
        ArrayList<Circle> circles = new ArrayList<>();
        ArrayList<Double> line = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(new File("e2-2.txt")))) {
            pointsStr = reader.readLine();
            circlesStr = reader.readLine();
            lineStr = reader.readLine();
        }
        catch (Exception exception) {
            exception.printStackTrace();
            return;
        }

        for (String point : pointsStr.substring(2, pointsStr.length() - 2).split("\\],\\[")) {
            String[] _point = point.split(",");
            points.add(new Point(Double.parseDouble(_point[0]), Double.parseDouble(_point[1])));
        }
        for (String circle : circlesStr.substring(2, circlesStr.length() - 2).split("\\],\\[")) {
            String[] _circle = circle.split(",");
            circles.add(new Circle(
                new Point(Double.parseDouble(_circle[0]), Double.parseDouble(_circle[1])),
                Double.parseDouble(_circle[2])
            ));
        }
        for (String arg : lineStr.substring(2, lineStr.length() - 2).split(",")) {
            line.add(Double.parseDouble(arg));
        }

        for (Circle circle : circles) {
            sum = 0;
            for (Point point : points) {
                if (point.isInCircle(circle)) sum ++;
            }
            System.out.println(sum);
        }

        for (Circle circle : circles) {
            System.out.println(circle.relationWithLine(line));
        }
    }
}

class Point {
    private double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() { return x; }
    public double getY() { return y; }

    public boolean isInCircle(Circle circle) {
        return Math.pow(x - circle.getCenter().getX(), 2) + Math.pow(y - circle.getCenter().getY(), 2)
            <= Math.pow(circle.getRadius(), 2);
    }
}

class Circle {
    private Point center;
    private double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() { return center; }
    public double getRadius() { return radius; }

    public String relationWithLine(ArrayList<Double> line) {
        Double distance = Math.abs(line.get(0) * center.getX() + line.get(1) * center.getY() + line.get(2))
            / Math.sqrt(Math.pow(line.get(0), 2) + Math.pow(line.get(1), 2));
        if (distance - radius > 0.001d) // distance > radius
            return "disjoint";
        if (radius - distance > 0.001d) // distance < radius
            return "intersect";
        return "tangency";
    }
}
