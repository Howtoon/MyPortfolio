/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_3;

import java.util.ArrayList;

/**
 *
 * @author Howtoon
 */
public class Room
{
    private final int roomNumber;
    private boolean orb;
    private boolean up = false;
    private boolean down = false;
    private boolean left = false;
    private boolean right = false;
    private final int xPos;
    private final int yPos;
    private final int sizeOfGrid;
    private ArrayList<Player> players = new ArrayList<>();
    
    public Room(int roomNumber, int doors,int sizeOfGrid, int xPos, int yPos)
    {
        this.roomNumber = roomNumber;
        this.xPos = xPos;
        this.yPos = yPos;
        this.sizeOfGrid = sizeOfGrid;
        generateDoors(doors);
    }
    
    private void generateDoors(int doors)
    {
        String binDoors = Integer.toBinaryString(doors);
        for (int i=0 ; i<binDoors.length() ; i++)
        {
            char open = binDoors.charAt(i);
            if (open == '1')
            {
                if (i==0 && this.yPos!=this.sizeOfGrid-1)
                {
                    up = true;
                }
                else if (i==1 && this.yPos!=0)
                {
                    down = true;
                }
                else if (i==2 && this.xPos!=0)
                {
                    left = true;
                }
                else if (i==3 && this.xPos!=this.sizeOfGrid-1)
                {
                    right = true;
                }
            }    
        }
    }
    
    public int getRoomNumber() {
        return roomNumber;
    }

    public boolean getOrb() {
        return orb;
    }
    
    public void setOrb(boolean orb) {
        this.orb = orb;
    }

    public boolean getUp() {
        return up;
    }

    public boolean getDown() {
        return down;
    }

    public boolean getLeft() {
        return left;
    }

    public boolean getRight() {
        return right;
    }
    
    public int getxPos() {
        return xPos;
    }

    public int getyPos() {
        return yPos;
    }
    
    public synchronized void playerEntered(Player player)
    {
        players.add(player);
    }
    
    public synchronized void playerExit(Player player)
    {
        players.remove(player);
    }
    
    public synchronized boolean roomIsOccupied()
    {
        return !players.isEmpty();
    }
    
    public synchronized ArrayList<Player> getPlayers()
    {
        return players;
    }
}
