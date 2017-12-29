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
public class Player extends Thread implements Runnable
{
    private Room playerPosition;
    private String name;
    private GameController controller;
    
    public Player(Room playerPosition, String name)
    {
        this.playerPosition = playerPosition;
        this.playerPosition.playerEntered(this);
        this.name = name;  
    }
    
    @Override
    public void run()
    {
        try
        {
            while(true)
            {
                if (controller.foundOrb() || this.isInterrupted())
                {
                    throw new InterruptedException();
                }
                else
                {
                    controller.computerMove(this);
                    if (controller.roomHasOrb(this) ||this.isInterrupted() )
                    {
                        throw new InterruptedException();
                    }
                } 
            }
        }
        catch (InterruptedException iex) 
        {
        }
    }
    
    public void setController(GameController controller)
    {
        this.controller = controller;
    }
    
    public String Name() {
        return name;
    }
    
    public Room getPlayerPosition() {
        return playerPosition;
    }

    public void setPlayerPosition(Room playerPosition) {
        this.playerPosition = playerPosition;
        
    }
}
