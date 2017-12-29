/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_2;

import java.util.Scanner;

/**
 *
 * @author Howtoon
 */
public class GameController {
    boolean isFinished = true;      //the end is not over, just started lol
    Dictionary dictionary;      //declare the dictionary variable
    Scanner keyboard = new Scanner(System.in);      //create the keyboard scanner for input
    public GameController(Dictionary dict)      //accept the dictioary to be used for the game
    {
        dictionary = dict;                  //set the dictionary
        dictionary.readFile("engmix.txt");  //read the file
        do
        {
            String guess = "";      //string to hold the guess
            boolean foundWord = false;      //assume the word is not found lol, it cant be we haven't guessed yet
            Character ch;               //char variable
            while (!foundWord)          //check if the word has been found
            {
                ch = dictionary.dictionary.getNextRandom(guess); //get a possible character based on the current guess
                if (ch == null)     //there is not a word that can be made with these characters, this checks the player's last input is valid
                {
                    System.out.println("There is no word that can be made with these characters");
                    System.out.println("Game Over, You Lose");
                    foundWord = true;       //set to end the current round of the game
                    continue;       //unnecessary, but the loop should return to the beginning
                }
                else        //the game continues
                {
                    System.out.println("Computer picks "+ch);       
                    guess += ch;
                    System.out.println("Word so far "+guess);
                    if (dictionary.dictionary.search(guess))        //checks to see if the computer completed a word
                    {
                        System.out.println("Found the word: "+guess);
                        System.out.println("Game Over, You Lose");
                        foundWord = true;
                        continue;   //unnecessary, but the loop should return to the beginning
                    }
                    else        //get input from the player
                    {
                        System.out.print("Character?> ");
                        String nextGuess = keyboard.nextLine();
                        guess += nextGuess.charAt(0);                   //only accept the first character that was entered
                        System.out.println("Word so far "+guess);
                        if (dictionary.dictionary.search(guess))        //if the player completed a word
                        {
                            System.out.println("Found the word: "+guess);
                            System.out.println("Game Over, You Win");
                            foundWord = true;
                            continue;   //unnecessary, but the loop should return to the beginning
                        }
                    }
                }
            }
            boolean inputGood = false;      //assume the string that the player enters is not valid
            do
            {
                System.out.println("Would you like to play again?");
                String again = keyboard.nextLine();
                if (again.compareToIgnoreCase("no")==0)     //end the game exit the program
                {
                    isFinished = true;
                    inputGood = true;
                }
                else if (again.compareToIgnoreCase("yes")!=0) //not a valid input
                {
                    isFinished = false;
                    inputGood = false;
                }
                else if (again.compareToIgnoreCase("yes")==0)       // the player wants to play again, do not exit, restart from top
                {
                    isFinished = false;
                    inputGood = true;
                }
            }
            while(!inputGood);
        }
        while (!isFinished);
    } 
}
