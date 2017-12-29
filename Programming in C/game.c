/**
@author  William Tennis
@since   09/26/2015
@version 1.0
Purpose: game.c Project 2  
-Reads input from the keyboard to facilitate a guessing game  
-Generates a random number between a 0 and 100 for the user to guess
-Tells the user whether their guess is too high or too low
-Narrows the field of possibilities based on previous guesses
-Counts the number of guesses taken
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>


//Function Declarations
void newGame(int yesNoCode);
char startGuess(int startGuessing);
bool isGameOver();


//Global Variable Declarations
int answer=0;
int guess=0;
int differential=0;
int max=0;
int min=0;
int numGuessesTaken=1;
bool gameOver=0;
char yesNoResponse=0;
int yesNoCode=3;
bool moreGames=1;

//Main Function
int main( void )
{
      do{
      if ((yesNoCode!=0)&&(yesNoCode!=1))
      {
         printf("Welcome to the Guessing Game.\n");
         printf("Would you like to play? y/n: ");
         scanf(" %c",&yesNoResponse);
         if (yesNoResponse=='y')
         {
             yesNoCode=1;
         }
         else if (yesNoResponse=='n')
            {
              yesNoCode=0;
            }
          }
      }while ((yesNoCode!=0)&&(yesNoCode!=1));
      if (yesNoCode==0)
      {
         printf("Maybe you would like to play some other time.\n");
         printf("Goodbye.\n");
      }
      if (yesNoCode==1)
      {
         newGame(yesNoCode);
      }
      else
      {
         return 0;
      }
      startGuess(1);
      do{  
         do{
            printf("Would you like to play another game? y/n: ");
            scanf(" %c",&yesNoResponse);
            if (yesNoResponse=='y')
            {
               yesNoCode=1;
               printf("Sure! You are about to begin a new game.\n");
            }
            else if (yesNoResponse=='n')
            {
               yesNoCode=0;
            }
         }while ((yesNoCode!=0)&&(yesNoCode!=1));
         if (yesNoCode==0)
         {
            printf("Maybe you would like to play again some other time.\n");
            printf("Goodbye.\n");
            return 0;
         }
         if (yesNoCode==1)
         {
            newGame(yesNoCode);
            moreGames=1;
         }
      }while (startGuess(1)==0);

}  
// Reset game y/n
void newGame(int yesNoCode)
{
         if (yesNoCode==1)
         {
            max=100;
            srand(time(NULL));

            do
            { 
               
               answer=rand();
            }
            while ((answer<0)||answer>(max+1));
            
            gameOver=0;
            differential=max;
            numGuessesTaken=1;
            min=0;
            printf("Your new game has been set-up. Let's play!\n");
            printf("Enter -1 to end the current game at anytime.\n");
            return;
         }
         else
         {
            printf("Thank you for playing. Let's play again sometime.\n");
            return;
         }
}
    
// Test guess

char startGuess(int startGuessing)
{
      do
      {

         printf("Enter your guess from %i and %i (inclusive) : ", min, max);
         scanf(" %i", &guess);
         if (guess==-1)
         {
            numGuessesTaken--;
            printf("You have decided to quit and have made %i attempts in your game.\n",numGuessesTaken);
            return (0);
         }
         if ((guess<min)||(guess>max))
         {
            do 
            {
               printf("I'm sorry, but your response is not within the range. Please try again.\n");
               printf("Enter your guess from %i and %i (inclusive) : ", min, max);
               scanf(" %i", &guess);
            }
            while ((guess<min)||(guess>max));
         }
         
         
         if (guess>answer)
         {
            max=guess-1;
            printf("Too High. ");
            if (numGuessesTaken==1)
            {
               numGuessesTaken++;
               differential=(guess-answer);
               printf("Keep trying! You are getting warm.\n");

            }
            else if (differential>(guess-answer))
            {
               numGuessesTaken++;
               differential=(guess-answer);
               printf("Keep trying! You are getting warmer.\n");
            }
            else if (differential<(guess-answer))
            {
               numGuessesTaken++;
               differential=(guess-answer);
               printf("Oh No! You are getting colder.\n");
            }
            else if (differential==(guess-answer))
            {
               numGuessesTaken++;
               differential=(guess-answer);
               printf("Hmmm that's strange... You aren't getting any hotter or colder. Keep trying.\n");
            }
         }
         else if (guess<answer)
         {
            min=guess+1;
            printf("Too Low. ");
            if (numGuessesTaken==1)
            {
               numGuessesTaken++;
               differential=(answer-guess);
               printf("Keep trying! You are getting warm.\n");
            }
            else if (differential>(answer-guess))
            {
               numGuessesTaken++;
               differential=(answer-guess);
               printf("Keep trying! You are getting warmer.\n");
            }
            else if (differential<(answer-guess))
            {
               numGuessesTaken++;
               differential=(answer-guess);
               printf("Oh No! You are getting colder.\n");
            }
            else if (differential==(answer-guess))
            {
               numGuessesTaken++;
               differential=(answer-guess);
               printf("Hmmm that's strange... You aren't getting any hotter or colder.\nKeep trying.\n");
            }
         }
         else if (guess==answer)
         {
            differential=(answer-guess);
            if (isGameOver()==1)
            {
               differential=0;
               printf("That's it! You guessed the number correctly\n");
               printf("Congratulations!\nYou have won the game after making %i attempts\n",numGuessesTaken);
               return(0);
            }
            else   
            {
               printf("There seems to be an error #1...\n");
               return (0);
            }
          }  
       }
       while (isGameOver()==0);
       
       if (isGameOver()==1)
       {
         printf("Thank you for playing.");
         return (0);
       }
       else
       {
         printf("There seems to be an error #2...\n");
         return (0);
       }
}
//Check for game over Parameters    
bool isGameOver()
{
         if (gameOver==1)
         {
            gameOver=1;
            return (1);
         }
         else if (answer==guess)
         {
            gameOver=1;
            return (1);
         }
         else if (answer!=guess)
         {
            gameOver=0;
            return (0);
         }
         printf("There seems to be an error #4...\n");
         return (1);
}



