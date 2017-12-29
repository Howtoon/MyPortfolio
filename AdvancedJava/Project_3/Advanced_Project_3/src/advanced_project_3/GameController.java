/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_3;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Howtoon
 */
public class GameController 
{
    private final Player player1;
    private final Player player2;
    private final Player player3;
    private final Player player4;
    private final Player player5;
    private final Player player6;
    private final Scanner kb = new Scanner(System.in);
    private final Maze maze;
    private boolean foundOrb = false;
    private int playersInQue;
    private int whosTurn = 1;
    private ArrayList<Player> playerQue = new ArrayList<>();
    
    public GameController(Maze maze, Player player1, Player player2, Player player3, Player player4, Player player5, Player player6)
    {
        this.maze = maze;
        maze.setController(this);
        this.player1 = player1;
        this.player2 = player2;
        this.player3 = player3;
        this.player4 = player4;
        this.player5 = player5;
        this.player6 = player6;
        playerQue.add(player1);
        playerQue.add(player2);
        playerQue.add(player3);
        playerQue.add(player4);
        playerQue.add(player5);
        playerQue.add(player6);
    }
    
    public synchronized void playerDied(Player player)
    {
        playerQue.remove(player);
    }
    
    public synchronized Player whosTurnIsIt()
    {
        return playerQue.get(whosTurn-1);
    }
    
    public synchronized boolean foundOrb()
    {
        return this.foundOrb;
    }
    
    public synchronized void setFoundOrb(boolean foundOrb)
    {
        this.foundOrb = foundOrb;
    }
    
    public synchronized void playGame() throws InterruptedException
    {
        player1.start();
        player2.start();
        player3.start();
        player4.start();
        player5.start();
        player6.start();
    }
    
    private void getNextMove()
    {
        boolean cannotMove = true;
        do
        {
            int direction;
            System.out.println("What is your next Move?");
            System.out.println("N, S, E, W, ORB: ");
            String input = kb.nextLine();
            if (input.compareToIgnoreCase("N") == 0)
            {
                direction = 0;
                this.playerMove(direction);
                return;
            }
            else if (input.compareToIgnoreCase("S") == 0)
            {
                direction = 1;
                this.playerMove(direction);
                return;
            }  
            else if (input.compareToIgnoreCase("W") == 0)
            {
                direction = 2;
                this.playerMove(direction);
                return;
            }
            else if (input.compareToIgnoreCase("E") == 0)
            {
                direction = 3;
                this.playerMove(direction);
                return;
            }
            else if (input.compareToIgnoreCase("orb") == 0)
            {
                if(this.roomHasOrb(player1))
                {
                    this.foundOrb = true;
                    return;
                }
                else
                {
                    System.out.println("This room does not contain the ORB.");
                }
                cannotMove = true;
            }  
        }
        while (cannotMove);
    }
    
    public synchronized boolean roomHasOrb(Player player)
    {
        return player.getPlayerPosition().getOrb();
    }
    
    /**
     *
     * @param player
     * @throws InterruptedException
     */
    public synchronized void computerMove(Player player) throws InterruptedException
    {
        while (this.playerQue.get(this.whosTurn-1) != player)
        {
            if(foundOrb)
            {
                player.interrupt();
                throw new InterruptedException();
            }
            wait();
        }
            
        if(foundOrb)
        {
            player.interrupt();
            throw new InterruptedException();
        }
        System.out.println("_________________");
        System.out.println("I am Thread: " + player.Name() + ". I am in Room " + player.getPlayerPosition().getRoomNumber());
        int direction;
        do
        {
            direction = maze.randInt(0, 3);
        }
        while(!this.maze.canMove(player, direction));
        this.whosTurn+=1;
        if (this.whosTurn>this.playerQue.size())
        {
            this.whosTurn=1;
        }
        System.out.println("I am Thread: " + player.Name() + ". I moved to Room " + player.getPlayerPosition().getRoomNumber());
        if (roomHasOrb(player))
        {
            System.out.println("I found the orb");
            setFoundOrb(true);
        }
        notifyAll();
    }

    private void invalidEntry()
    {
        System.out.println("Invalid Entry. Try Again.");
    }

    private void playerMove(int direction)
    {
        if (this.maze.canMove(this.player1, direction))
        {
        }
        else
        {
            this.invalidEntry();
        }
    }

}
