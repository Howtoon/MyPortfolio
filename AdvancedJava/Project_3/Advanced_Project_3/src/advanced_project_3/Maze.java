/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_3;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Howtoon
 */
public class Maze 
{
    private int sizeOfGrid;
    private Room[][] maze;
    private GameController controller;

    public Maze()
    {
        createMaze();
        placeOrb();
    }
    
    private void createMaze()
    {
        this.sizeOfGrid = this.randInt(10, 15);
        this.maze = new Room[this.sizeOfGrid][this.sizeOfGrid];
        int roomNumber = 1;
        for(int i=0 ; i<this.sizeOfGrid ; i++)  //xPos
        {
            for (int j=0 ; j<this.sizeOfGrid ; j++) //yPos
            {
                int doors;
                if (i==0 || i==this.sizeOfGrid-1 || j==0 || j==this.sizeOfGrid-1)
                {
                    do 
                    {
                        doors  = this.randInt(7, 15);
                        if (doors==7 || doors==11 || doors==13 || doors==14 || doors==15)
                        {
                            break;
                        }
                    }
                    while(true);
                }
                else
                {
                    do 
                    {
                        doors  = this.randInt(1, 15);
                        if (doors==7 || doors==11 || doors==13 || doors==14 || doors==15)
                        {
                            break;
                        }
                    }
                    while(true);
                }
                this.maze[i][j] = new Room(roomNumber, doors, this.sizeOfGrid , i, j);
                roomNumber++;
            }
        }
    }
    
    private void placeOrb()
    {
        maze[this.randInt(0, this.sizeOfGrid-1)][this.randInt(0, this.sizeOfGrid-1)].setOrb(true);
    }
    
    public synchronized boolean canMove(Player player, int direction)
    {
        Room playerPosition = player.getPlayerPosition();
        switch (direction) {
            case 0:
                if (playerPosition.getUp())
                {
                    if(maze[playerPosition.getxPos()][playerPosition.getyPos()+1].roomIsOccupied())
                    {
                        fight(maze[playerPosition.getxPos()][playerPosition.getyPos()+1].getPlayers().get(0), player);
                        if (player.isInterrupted())
                        {
                            return true;
                        }
                    }
                    player.getPlayerPosition().playerExit(player);
                    player.setPlayerPosition(maze[playerPosition.getxPos()][playerPosition.getyPos()+1]);
                    player.getPlayerPosition().playerEntered(player);
                    return true;
                }   break;
            case 1:
                if (playerPosition.getDown())
                {
                    if(maze[playerPosition.getxPos()][playerPosition.getyPos()-1].roomIsOccupied())
                    {
                        fight(maze[playerPosition.getxPos()][playerPosition.getyPos()-1].getPlayers().get(0), player);
                        if (player.isInterrupted())
                        {
                            return true;
                        }
                    }
                    player.getPlayerPosition().playerExit(player);
                    player.setPlayerPosition(maze[playerPosition.getxPos()][playerPosition.getyPos()-1]);
                    player.getPlayerPosition().playerEntered(player);
                    return true;
                }   break;
            case 2:
                if (playerPosition.getLeft())
                {
                    if(maze[playerPosition.getxPos()-1][playerPosition.getyPos()].roomIsOccupied())
                    {
                        fight(maze[playerPosition.getxPos()-1][playerPosition.getyPos()].getPlayers().get(0), player);
                        if (player.isInterrupted())
                        {
                            return true;
                        }
                    }
                    player.getPlayerPosition().playerExit(player);
                    player.setPlayerPosition(maze[playerPosition.getxPos()-1][playerPosition.getyPos()]);
                    player.getPlayerPosition().playerEntered(player);
                    return true;
                }   break;
            case 3:
                if (playerPosition.getRight())
                {
                    if(maze[playerPosition.getxPos()+1][playerPosition.getyPos()].roomIsOccupied())
                    {
                        fight(maze[playerPosition.getxPos()+1][playerPosition.getyPos()].getPlayers().get(0), player);
                        if (player.isInterrupted())
                        {
                            return true;
                        }
                    }
                    player.getPlayerPosition().playerExit(player);
                    player.setPlayerPosition(maze[playerPosition.getxPos()+1][playerPosition.getyPos()]);
                    player.getPlayerPosition().playerEntered(player);
                    return true;
                }   break;
            default:
                break;
        }
        return false;
    }
    
    private void fight(Player player2, Player player1)
    {
        Scanner kb = new Scanner(System.in);
        System.out.println("Thread: "+player1.Name() + " is fighting with " + "Thread: "+player2.Name());
        if (randInt(1, 10)<5)
        {
            player2.interrupt();
            System.out.println("Thread: "+player1.Name() + " has killed " + "Thread: "+player2.Name());
            this.controller.playerDied(player2);
            this.maze[player2.getPlayerPosition().getxPos()][player2.getPlayerPosition().getyPos()].playerExit(player2);
            System.out.println("Press a key to continue.");
            String t = kb.nextLine();
        }
        else
        {
            player1.interrupt();
            System.out.println("Thread: "+player2.Name() + " has killed " + "Thread: "+player1.Name());
            this.controller.playerDied(player1);
            this.maze[player1.getPlayerPosition().getxPos()][player1.getPlayerPosition().getyPos()].playerExit(player1);
            System.out.println("Press a key to continue.");
            String t = kb.nextLine();
        }
    }
    
    public void displayRoom(Player player)
    {
        ArrayList<Player> occupants = player.getPlayerPosition().getPlayers();
        if (player.Name().compareToIgnoreCase("c")==0)
        {
            return;
        }
        Room position = player.getPlayerPosition();
        System.out.println("\n\nRoom: "+position.getRoomNumber());
        System.out.print("+--");
        if (position.getUp())
        {
            System.out.print("##");
        }
        else
        {
            System.out.print("--");
        }
        System.out.println("--+");
        System.out.println("|      |");
        System.out.print("|  ");
        for (int i = 0; occupants.size()-1 >= i;i++)
        {
            System.out.print(occupants.get(i).Name());
        }
        if (occupants.size()==1)
        {
            System.out.print(" ");
        }
        System.out.println("  |");
        System.out.print("| ");
        if (position.getOrb())
        {
            System.out.println("O    |");
        }
        else
        {
            System.out.println("     |"); 
        }
        if (position.getLeft())
        {
            System.out.print("#      ");
        }
        else
        {
            System.out.print("|      ");
        }
        if (position.getRight())
        {
            System.out.println("#");
        }
        else
        {
            System.out.println("|");
        }
        if (position.getLeft())
        {
            System.out.print("#      ");
        }
        else
        {
            System.out.print("|      ");
        }
        if (position.getRight())
        {
            System.out.println("#");
        }
        else
        {
            System.out.println("|");
        }
        System.out.println("|      |");
        System.out.println("|      |");
        System.out.print("+--");
        if (position.getDown())
        {
            System.out.print("##");
        }
        else
        {
            System.out.print("--");
        }
        System.out.println("--+");
    }
    
    public int randInt(int min, int max) 
    {
        Random rand = new Random();
        int randomNum = rand.nextInt((max - min) + 1) + min;
        return randomNum;
    }
    
    public Room getRandomRoom()
    {
        Room room;
        boolean placedPlayer = false;
        do
        {
            int xPos = this.randInt(0, sizeOfGrid-1);
            int yPos = this.randInt(0, sizeOfGrid-1);
            room = this.maze[xPos][yPos];
            if (!room.getOrb() && !room.roomIsOccupied() && (room.getUp() || room.getDown() || room.getLeft() || room.getRight()))
            {
                placedPlayer = true;
            }
        }
        while (!placedPlayer);
        
        return room;
    }
    
    public void setController(GameController controller)
    {
        this.controller = controller;
    }
}
