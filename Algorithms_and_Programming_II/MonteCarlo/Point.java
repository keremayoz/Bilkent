/**
 * @(#)Point.java
 *
 *
 * @author Kerem Ayöz
 * Point Class
 * @version 1.00 2016/9/29
 */


public class Point {

//Creating member variables for x and y coordinates
	private double x;
	private double y;

//Creating constructor that contains member variables
    public Point(double x, double y) {
    	this.x = x;
    	this.y = y;
    }

//get() methods for both x and y
    public double getX() {
    	return x;
    }
    public double getY() {
    	return y;
    }

//set() methods for both x and y
    public void setX(double newX) {
    	x = newX;
    }
    public void setY(double newY) {
    	y = newY;
    }

//toString() method to show coordinates of point like (x, y)
    public String toString() {
    	return "(" + x + ", " + y + ")";
    }
}