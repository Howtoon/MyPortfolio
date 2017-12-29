package trivia_game;

/**
 * @author Cole Peaden
 *
 */

public class Client
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Storage storage = new Storage();
        GameController controller = new GameController(storage);
        controller.menu();
    }
    
}
