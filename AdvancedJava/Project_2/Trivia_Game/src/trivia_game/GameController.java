/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trivia_game;

import java.util.Scanner;

/**
 * @author Cole Peaden
 *
 */

public class GameController 
{
    private final Scanner in = new Scanner(System.in);
    private Player player;
    private Storage storage;
    private QuestionList questionList;
    private Question question;

    
    public GameController(Storage storage)
    {
        this.storage = storage;
        questionList = storage.getQuestionList();
    }
    
    public void menu()
    {
        boolean isNotDone = true;
        do
        {
            System.out.println("Welcome to the Trivia Game");
            System.out.println("Are you a new User? (Y/N): ");
            String input = in.nextLine();
            if (input.compareToIgnoreCase("Y")==0)
            {
                player = storage.createNewPlayer();
                isNotDone = false;
            }
            else if (input.compareToIgnoreCase("N")==0)
            {
                System.out.println("Enter your name: ");
                input = in.nextLine();
                if (input.compareToIgnoreCase("admin")==0)
                {
                    this.storage.menu();
                }
                else
                {
                    player = storage.getPlayer(input);
                    if (player == null)
                    {
                        System.out.println("The name you entered was not found.\n");
                        isNotDone = true;
                        continue;
                    }
                    System.out.println(player.toString());
                    isNotDone = false;
                }
            }

        }
        while(isNotDone);
        startGame();
    }
    
    public void startGame()
    {
        if (!this.questionList.hasNextQuestion())
        {
            System.out.println("There are no questions in the Question List.");
            return;
        }
        else
        {
            boolean gameNotOver = true;
            int playerScore = 0;
            int questionCount = 1;
            String input;
            while(gameNotOver)
            {
                while(questionCount<6)
                {
                    this.question = this.questionList.getNextQuestion();
                    System.out.println("Question "+questionCount+":");
                    System.out.println(question.getQuestion());
                    System.out.print("Answer: ");
                    input = in.nextLine();
                    if (input.compareToIgnoreCase(question.getAnswer())==0)
                    {
                        System.out.println("That is correct!");
                        playerScore += question.getValue();
                    }
                    else
                    {
                        System.out.println("Wrong. The correct answer is "+question.getAnswer());
                    }
                    System.out.println("Your score is "+playerScore+"\n");
                    questionCount++;
                }
                boolean notSatisfactoryResponse = true;
                this.player.setTotalPoints(this.player.getTotalPoints()+playerScore);
                this.storage.writePlayerFile();
                while(notSatisfactoryResponse)
                {
                    System.out.println("Would you like to play again? (Y/N)");
                    input = in.nextLine();
                    if (input.compareToIgnoreCase("Y")==0)
                    {
                        notSatisfactoryResponse = false;
                        this.questionList.createWorkingList();
                        playerScore = 0;
                        questionCount = 1;
                    }
                    else if (input.compareToIgnoreCase("N")==0)
                    {
                        System.out.println("Thank You for Playing!");
                        return;
                    }
                }
            }
        }
    }
}
