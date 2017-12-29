/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_2;

/**
 *
 * @author Howtoon
 * 
 */
public class Client 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        GameController gameController = new GameController(new Dictionary());  //create the game pass it the dictionary.
    }
}
