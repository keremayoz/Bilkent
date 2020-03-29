/*
 * author: Kerem Ayöz
 * GameTester class 
 * A class that allows user to play game
 * 
 * Created: 1.11.2016
 */
import java.util.Scanner;

public class GameTester {

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Enter the difficulty level(1,2 or 3): ");
		int dif = keyboard.nextInt();
		
		Game newGame = new Game(dif);	
		newGame.play();
		
		

	}

}
