/**
 * @(#)PiCalculator.java
 *
 *
 * @author Kerem Ayöz
 * PiCalculator class
 * Aim to calculate pi number by Monte Carlo method
 * It uses Point.java, Rectangle.java, Circle.java files
 *
 * @version 1.00 2016/9/29
 */

import java.util.Scanner; //Importing Scanner

public class PiCalculator {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); //Scanner object

//Creating points for rectangle corner(rc) and circle center(cc)
        Point rc = new Point(-1, 1);
        Point cc = new Point(0, 0);

//Creating rectangle and circle objects
//Circle is origin centered and its center at (0,0) and radius equals 1, rectangle covers all circle at edges and its both width and height equals 2
        Rectangle r = new Rectangle(rc, 2, 2);
        Circle c = new Circle(cc, 1);

//User prompt for trial number
		System.out.print("Enter the trials that you want to make: ");
        double trials = in.nextDouble();
//Creating hit variable and making trials
        double hit = 0;
        for (int i = 0; i < trials; i++) {
        	Point newPoint = r.getRandomPoint();

        	if (c.contains(newPoint))
        		hit++;
        }
//Printing the estimated result
        System.out.println("After " + (int)trials + " trials, pi is calculated as " + 4 * (hit / trials));
    }
}
