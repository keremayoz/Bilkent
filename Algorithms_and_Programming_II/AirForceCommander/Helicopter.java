/*
 * author: Kerem Ayöz
 * Helicopter class that extends abstract EnemyVehicle
 * 
 * Created: 30.10.2016
 * */
 
public class Helicopter extends EnemyVehicle {
	
	private int speed = BASE_SPEED;
	
	/*
	 *Helicopter constructor that is inherited from EnemyVehicle
	 *@param minX ,minimum x coordinate
	 *@param maxX ,maximum x coordinate 
	 *@param y ,y coordinate
	 *
	 */
	public Helicopter(int minX, int maxX, int y) {
		super(minX, maxX, y);
	}
	
	/*
	 *Method for Helicopter that increases its speed at every turn
	 */
	public void move() {
		y -= speed;
		speed += 1;
	}
	
	/*
	 *toString method for Helicopter
	 *@return String
	 */
	public String toString() {
		return "Helicopter\nCoordinate: (" + x + ", "+ y +")\nSpeed: " + speed + "\nHealth: " + health;
	}
	
	/*
	 *Method that gives the type of the vehicle
	 *@return String
	 */
	public String getType() {
		return "Helicopter";
	}
	
	/* 
	 *Returns the speed of the vehicle
	 *@return speed, speed of the Helicopter
	 */
	public int getSpeed() {
		return speed;
	}
	
}
