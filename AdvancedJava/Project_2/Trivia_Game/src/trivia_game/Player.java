package trivia_game;

import java.io.Serializable;

/**
 * This class creates Player objects and extends the parameters of Administrator.
 * A Player object is used to play the game against the computer.
 * 
 * 
 * @author Cole Peaden
 * @date 2/27/17
 * @class COP3022
 * @teacher Prof. Pinto
 *
 */
public class Player implements Serializable
{
	
    private String name;
    private String nickName;
    private int totalPoints;

    public Player(String newName, String newNickname)
    {
        this.name = newName;
        this.nickName = newNickname;
        this.totalPoints = 0;
    }
    /**
     * @return the name
     */
    public String getName() {
        return name;
    }
    /**
     * @param name the name to set
     */
    public void setName(String name) 
    {
        this.name = name;
    }

    /**
     * @return the nickName
     */
    public String getNickName() 
    {
        return nickName;
    }

    /**
     * @param nickName the nickName to set
     */
    public void setNickName(String nickName) 
    {
        this.nickName = nickName;
    }

    /**
     * @return the totalPoints
     */
    public int getTotalPoints() 
    {
        return totalPoints;
    }

    /**
     * @param totalPoints the totalPoints to set
     */
    public void setTotalPoints(int totalPoints) 
    {
        this.totalPoints = totalPoints;
    }

    /**
     * Method takes in the Player class
     * and puts the information to a String.
     */
    @Override
    public String toString()
    {
        return "Name: " + name +"\t Nickname: "+ nickName + " \t Total Points: " + totalPoints;
    }
}

