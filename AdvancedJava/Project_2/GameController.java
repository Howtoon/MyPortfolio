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
    boolean isFinished = true;
    String word;
    Dictionary dictionary;
    Scanner keyboard = new Scanner(System.in);
    public GameController(Dictionary dict)
    {
        dictionary = dict;
        dictionary.readFile("engmix.txt");
        do
        {
            String guess = "";
            boolean foundWord = false;
            Character ch;
            while (!foundWord)          
            {
                if (guess.compareTo("") == 0)
                {
                    ch = (char)((int)(Math.random()*(26-1))+'a');
                }
                else
                {
                    ch = dictionary.dictionary.getNextRandom(guess);
                }
                if (ch == null)
                {
                    System.out.println("There is no word that can be made with these characters");
                    System.out.println("Game Over, You Lose");
                    foundWord = true;
                    continue;
                }
                else
                {
                    System.out.println("Computer picks "+ch);
                    guess += ch;
                    System.out.println("Word so far "+guess);
                    if (dictionary.dictionary.search(guess))
                    {
                        System.out.println("Found the word: "+guess);
                        System.out.println("Game Over, You Lose");
                        foundWord = true;
                        continue;
                    }
                    else
                    {
                        System.out.print("Character?> ");
                        String nextGuess = keyboard.nextLine();
                        guess += nextGuess.charAt(0);
                        System.out.println("Word so far "+guess);
                        if (dictionary.dictionary.search(guess))
                        {
                            System.out.println("Found the word: "+guess);
                            System.out.println("Game Over, You Win");
                            foundWord = true;
                            continue;
                        }
                    }
                }
            }
            boolean inputGood = false;
            do
            {
                System.out.println("Would you like to play again?");
                String again = keyboard.nextLine();
                if (again.compareToIgnoreCase("no")==0)
                {
                    isFinished = true;
                    inputGood = true;
                }
                else if (again.compareToIgnoreCase("yes")!=0)
                {
                    isFinished = false;
                    inputGood = false;
                }
                else if (again.compareToIgnoreCase("yes")==0)
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
