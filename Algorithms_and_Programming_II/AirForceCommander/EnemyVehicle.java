/*
 * author: Kerem Ayöz
 * EnemyVehicle abstract class that implements Movable and Destructible
 * 
 * Created: 30.10.2016
 * */

import java.awt.Point;

public abstract class EnemyVehicle implements Movable, Destructible {
	protected int x,y;
	protected double health = 100.0;
	protected final int BASE_SPEED = 3;
	
	/*
	 *EnemyVehicle constructor that takes minX, maxX and y as parameters
	 *@param minX ,minimum x coordinate
	 *@param maxX ,maximum x coordinate 
	 *@param y ,y coordinate
	 *
	 */
	public EnemyVehicle(int minX, int maxX, int y) {
		this.x = (int)(Math.random()*(maxX-minX)+ minX);
		this.y = y;
	}
	
	/*
	 *Method that returns distance to the border
	 *@return y; y coordinate actually distance
	 *
	 */
	public int getDistanceToBorder() {
		return y;
	}
	
	/*
	 *Abstract method getType, overridden in subclasses seperately
	 *
	 */
	public abstract String getType();

	/*
	 *Determines whether EnemyVehicle is destroyed or not
	 *@return boolean
	 * 
	 */
	public boolean isDestroyed() {
		return health <= 0;
		
	}

	/*
	 *Method that decreases health of the EnemyVehicle
	 *@param damage, damage amount to the vehicle 
	 *
	 */
	public void takeDamage(double damage) {
		health -= damage;
	}

	/*
	 *Method that changes EnemyVehicle's coodinates
	 *
	 */
	public void move() {
		y -= BASE_SPEED;
	}
	
	/*
	 *Returns coordinate of the EnemyVehicle as a Point object
	 *@return Point
	 *
	 */
	public Point getLocation() {
		return new Point(x, y);
	}

}
