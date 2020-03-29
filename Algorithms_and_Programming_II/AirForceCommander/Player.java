/*
 * author: Kerem Ayöz
 * Player class 
 * A class that will be used to attack EnemyVehicle objects
 * 
 * Created: 30.10.2016
 * */
import java.util.ArrayList;

public class Player {
	
	public final double BOMB_RADIUS = 2.0;
	public final double DAMAGE = 50.0;
	
	/*
	 *Default constructor
	 */
	public Player () {
	}
	
	/*
	 *Method that attacks the enemy vehicles
	 *@param x, x coordinate to attack
	 *@param y, y coordinate to attack
	 *@param enemies, ArrayList of EnemyVehicles
	 */
	public void attack(int x, int y, ArrayList<EnemyVehicle> enemies) {
		for (int i = 0; i < enemies.size(); i++) {
			if (Math.sqrt(Math.pow(x - enemies.get(i).x,2) + Math.pow(y - enemies.get(i).y,2)) <= BOMB_RADIUS)
				enemies.get(i).takeDamage(DAMAGE);
		}
	}
}
