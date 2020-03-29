/**
 * @(#)Rectangle.java
 *
 *
 * @author Kerem Ayöz
 * Rectangle Class
 * @version 1.00 2016/9/29
 */


public class Rectangle {

//Creating members corner point, width and height
	private Point corner;
	private double width;
	private double height;

//Creating constructor that takes member variables
    public Rectangle(Point corner, double width, double height) {
    	this.corner = corner;
    	this.width = width;
    	this.height = height;
    }

//get() methods for member variables
    public Point getCorner() {
    	return corner;
    }
	public double getWidth() {
		return width;
	}
	public double getHeight() {
		return height;
	}

//set() methods for member variables
	public void setCorner(double newX, double newY) {
		corner.setX(newX);
		corner.setY(newY);
	}
	public void setWidth(double newWidth) {
		width = newWidth;
	}
	public void setHeight(double newHeight) {
		height = newHeight;
	}

//contains(Point p) method which checks whether the point p is in inside or outside of rectangle
	public boolean contains(Point p) {
		//Creating boolean conditions to check coordinates of the point greater or less than corner coordinates

		//Checking x (x coordinate of point p should be in that range: corner's x < x < corner's x + width)
		boolean fc = (p.getX() > corner.getX() && p.getX() < corner.getX() + width);

		//Checking y (y coordinate of point p should be in that range: corner's y - height < y < corner's y)
		boolean sc = (p.getY() > corner.getY() - height && p.getY() < corner.getY());

		if (fc && sc) {
			return true;
		}
		else
			return false;
	}

//Creating getRandomPoint() method that creates random point in rectangle. Same ranges are used in this method
	public Point getRandomPoint() {
		Point randomPoint = new Point((Math.random() * width) + corner.getX(), (Math.random() * height) - corner.getY());
		return randomPoint;
	}

//toString() method. It shows rectangle like corner= (x, y), width= w, height= h
	public String toString() {
		return "corner=("+corner.getX()+", "+corner.getY()+"), width= "+width+", height="+height;
	}
}