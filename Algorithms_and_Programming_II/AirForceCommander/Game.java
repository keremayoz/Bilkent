/*
 * author: Kerem Ayöz
 * Game class that implements Difficulty 
 * 
 * Created: 30.10.2016
 */
 
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class Game implements Difficulty {
	private int difficulty;
	private int score;
	private int passedElements;
	private boolean signal = false;
	private ArrayList<EnemyVehicle> hostile;
	private Player gamer;
	public final int STARTING_DISTANCE = 20;
	private final int MAX_NO_OF_PASSING_ELEMENTS = 3;
	
	/*
	 *Game constructor that initializes the variables and take difficulty as a paramater
	 *It fills the ArrayList with random EnemyVehicles
	 *@param difficulty, difficulty level of the game
	 */
	public Game(int difficulty) {
		this.difficulty = difficulty;
		gamer = new Player();
		score = 0;
		passedElements = 0;
		hostile = new ArrayList();
		for (int i = 0; i < difficulty*2; i++)
			hostile.add(getNewRandomVehicle());
	}
	
	/*
	 *Play method that plays the actual game
	 *First it attacks the given coordinate
	 *After that it removes the death ones, places new Enemies to the field
	 */
	GamePlotter gplot = new GamePlotter(this);
	public void play() {
		Scanner in = new Scanner(System.in);
		while (passedElements <= MAX_NO_OF_PASSING_ELEMENTS) {
			gplot.plot();
			printGameState(); signal = false;
			System.out.print("-------------------------\nEnter the x and y coordinates to bomb: ");
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			gamer.attack(x1, y1, hostile);
			enemiesTurn();
		}
		System.out.println("The final score is " + score);
	}
	
	/*
	 *Returns %50 Tank %50 Helicopter to the random x and y = 20 position
	 *@return EnemyVehicle, Tank or Helicopter
	 */
	public EnemyVehicle getNewRandomVehicle() {
		Random rand = new Random();
		int  i = rand.nextInt(2) + 1;
		if (i == 1)
			return new Tank(0, 5*difficulty, STARTING_DISTANCE);
		else
			return new Helicopter(0, 5*difficulty, STARTING_DISTANCE);
	}
	
	/*
	 *Returns enemyvehicle arraylist
	 *@return hostile, EnemyVehicle ArrayList
	 */
	public ArrayList<EnemyVehicle> getEnemies() {
		return hostile;
	}
	
	/*
	 *Prints the current game status, every enemy seperately
	 */
	public void printGameState() {
		if (signal)
			System.out.println("Enemies destroyed!!!");
		System.out.println("Current score: " + score);
		System.out.println("Number of passed elements: " + passedElements);
		System.out.println("Number of the remaining enemy: " + hostile.size() + "\n********************");
		for (int i = 0; i < hostile.size(); i++)
			System.out.println(hostile.get(i) + "\n********************");
	}
	
	/*
	 *Removes death enemies and moves them. After that counts passed elements
	 */
	public void enemiesTurn() {
		for (int i = 0; i < hostile.size(); i++) {
			if (hostile.get(i).isDestroyed()) {
				hostile.set(i, getNewRandomVehicle());
				score++;
				signal = true;
			}
			hostile.get(i).move();
			if (hostile.get(i).y < 0) {
				hostile.set(i, getNewRandomVehicle());
				passedElements++;
			}
		}
	}
	
	/*
	 *Sets the difficulty
	 *@param difficulty, difficulty level
	 */
	public void setDifficulty(int difficulty) {
		this.difficulty = difficulty;
	}
	
	/*
	 *Gets the difficulty
	 *@return difficulty, difficulty level
	 */
	public int getDifficulty() {
		return difficulty;
	}

}
