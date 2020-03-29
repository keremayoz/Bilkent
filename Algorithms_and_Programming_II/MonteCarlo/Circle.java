/**
 * @(#)Circle.java
 *
 *
 * @author Kerem Ayöz
 * Circle Class
 * @version 1.00 2016/9/29
 */


public class Circle {

//Creating members center point, radius
	private Point center;
	private double radius;

//Creating constructor that takes member variables
    public Circle(Point center, double radius) {
    	this.center = center;
    	this.radius = radius;
    }

//get() methods for member variables
    public Point getCenter() {
    	return center;
    }
    public double getRadius() {
    	return radius;
    }

//set() methods for member variables
    public void setCenter(double newX, double newY) {
		center.setX(newX);
		center.setY(newY);
	}
	public void setRadius(double newRadius) {
		radius = newRadius;
	}

//contains(Point p) method checks the point whether it is in inside or outside
	public boolean contains(Point p) {
		//Finding distance between center point and given point p
		double distance = Math.sqrt(Math.pow(p.getX()-center.getX(),2) + Math.pow(p.getY()-center.getY(),2));

		if (distance <= radius)
			return true;
		else
			return false;
	}

//toString() method shows circle like center= (x, y), radius= r
	public String toString() {
		return "center=("+center.getX()+", "+center.getY()+"), radius= "+radius;
	}


}