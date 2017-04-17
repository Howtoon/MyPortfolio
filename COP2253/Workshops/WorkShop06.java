/**
 @author  William Tennis
@since   02/19/2015
@version 1.0
Purpose: WorkShop06
-
-  
-
*/
import java.util.Scanner;
public class WorkShop06
{
   public static void main (String[] args)
   {
   Scanner input = new Scanner(System.in);
   
   /* Input variables */
   System.out.print("What is your body's temperature in degrees Farenheit?: ");
   double temp=input.nextDouble();
   System.out.print("Do you have a rash? Y/N: ");
   String rash=input.next();
   System.out.print("How many days have you felt bad?: ");
   int days=input.nextInt();
   
   /* If statements */
   
   if ((temp<=98.6)&&(rash.equalsIgnoreCase("y")))
   {
      System.out.print("You might be having an allergic reaction");
   }
   else if ((temp>98.6)&&(rash.equalsIgnoreCase("y"))&&(days>5))
   {
      System.out.print("You might have the measles");
   }
   else if ((temp>98.6)&&(rash.equalsIgnoreCase("n"))&&(days>5))
   {
      System.out.print("You might have a bacterial infection");
   }
   else if ((temp>98.6)&&(rash.equalsIgnoreCase("n"))&&(days<=5))
   {
      System.out.print("You might have a viral infection");
   }
   else
   {
      System.out.print("I'm sorry, but I'm not not actually a Doctor. I only play one on TV");
   }

      


   
   
   }
}

