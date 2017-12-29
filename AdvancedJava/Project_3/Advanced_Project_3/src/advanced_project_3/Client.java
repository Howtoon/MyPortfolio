/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_3;

/**
 *
 * @author Howtoon
 */
public class Client 
{
    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException 
    {
        // TODO code application logic here
        final Maze maze = new Maze();
        Room room = maze.getRandomRoom();
        final Player player1 = new Player(room, "1");
        room = maze.getRandomRoom();
        final Player player2 = new Player(room, "2");
        room = maze.getRandomRoom();
        final Player player3 = new Player(room, "3");
        room = maze.getRandomRoom();
        final Player player4 = new Player(room, "4");
        room = maze.getRandomRoom();
        final Player player5 = new Player(room, "5");
        room = maze.getRandomRoom();
        final Player player6 = new Player(room, "6");
        
        final GameController controller = new GameController(maze, player1, player2, player3, player4, player5, player6);
        player1.setController(controller);
        player2.setController(controller);
        player3.setController(controller);
        player4.setController(controller);
        player5.setController(controller);
        player6.setController(controller);
        controller.playGame();
    }
    
}
