/**
 * Created by Halil on 28.10.2016.
 * This class provides a simple UI to visualize Game objects on the console.
 */
public class GamePlotter {

    private Game game;

    /**
     * A constructor to set the Game object to be plotted.
     * @param game Game object to be plotted
     */
    public GamePlotter(Game game)
    {
        this.game = game;
    }

    /**
     * This method draws the current state of the game on the console.
     */
    public void plot()
    {
        int height = game.STARTING_DISTANCE;
        int width = 5 * game.getDifficulty();

        System.out.print("   ");
        for (int j = 0; j < width; j++)
            System.out.printf("%3d ", j);
        System.out.println();

        System.out.print("   ");
        for (int j = 0; j < width; j++)
            System.out.print(" ___");
        System.out.println();
        for (int i = height; i >= 0; i--)
        {
            System.out.printf("%2d ", i);
            for (int j = 0; j < width; j++)
            {
                System.out.print("|");
                int enemyCountOnThisPosition = 0;
                for (EnemyVehicle e :
                        game.getEnemies()) {
                    if (e.getLocation().x == j && e.getLocation().y == i)
                        enemyCountOnThisPosition++;
                }
                System.out.print(enemyCountOnThisPosition == 0 ? "___" : "_" + enemyCountOnThisPosition + "_");
            }
            System.out.println("|");
        }
    }
}
