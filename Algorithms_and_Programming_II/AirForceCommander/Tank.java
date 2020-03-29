/*
 * author: Kerem Ayöz
 * Tank class that extends EnemyVehicle abstract class
 * 
 * Created: 30.10.2016
 */
 
public class Tank extends EnemyVehicle {
	
	/*
	 *Tank constructor that is inherited from EnemyVehicle
	 *@param minX ,minimum x coordinate
	 *@param maxX ,maximum x coordinate 
	 *@param y ,y coordinate
	 */
	public Tank(int minX, int maxX, int y) {
		super(minX, maxX, y);
	}
	
	/*
	 *Method that decreases health of the Tank less than other vehicles
	 *@param damage, damage amount to the vehicle 
	 */
	public void takeDamage(double damage) {
		health -= 2*damage/3;
	}
	
	/*
	 *toString method for Tank
	 *@return String
	 */
	public String toString() {
		return "Tank\nCoordinate: (" +x+", "+y+")\nHealth: "+health;
	}
	
	/*
	 *Method that gives the type of the vehicle
	 *@return String
	 */
	public String getType() {
		return "Tank";
	}
	
}
