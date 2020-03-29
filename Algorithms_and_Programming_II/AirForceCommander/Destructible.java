/*
 * author: Kerem Ayöz
 * Destructible Interface
 * 
 * Created: 30.10.2016
 * */
 
public interface Destructible {
	
	public boolean isDestroyed();
	public void takeDamage(double damage);
	
}
