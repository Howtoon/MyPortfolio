/**
@author  William Tennis
@since   02/03/2015
@version 1.0
Purpose: Workshop5
Purpose: This program reads data from a file regarding miles driven and gallons of gas used and calculates the miles per gallon
*/
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
public class Workshop5
{
   
   public static void main (String[] args)
   {
   Scanner input=new Scanner(System.in);
   System.out.print("Enter the name of where the data is stored: ");
/*   String fileName=input.nextLine();
   Scanner fileIn = new Scanner(new FileInputStream(fileName));
   String name=fileIn.nextLine();
   int miles=fileIn.nextInt();
   double gallons=fileIn.nextDouble();
*/
      String fileName=input.next();
      Scanner fileIn = null ; // initializes fileIn to empty
      try
      {
	      // Attempt to open the file
	      fileIn = new Scanner( new FileInputStream(fileName));
      }
      catch (FileNotFoundException e)
      {
   	   // If the file could not be found, this code is executed
	      // and then the program exits
	      System.out.printf("File [" + fileName +"] not found.%n");
	      System.exit(0);
      }
      //... Code continues here if the file was opened successfully
	     

      String name=fileIn.nextLine();
      int miles=fileIn.nextInt();
      String junk=fileIn.nextLine();
      double gallons=fileIn.nextDouble();
      

      fileIn.close();   
      
      double mpg=miles/gallons;

      System.out.printf("%n%s drove %3d miles, used %2.2f gallons of gas resulting in gas milage of %2.1f mpg%n%n",name,miles,gallons,mpg); 
      System.out.println("+--------------+-------+---------+------+");
      System.out.println("|     Name     | Miles | Gallons |  MPG |");
      System.out.println("+--------------+-------+---------+------+");
      System.out.printf ("|  %-12s|%6d |%8.2f |%5.1f |%n",name,miles,gallons,mpg);
      System.out.println("+--------------+-------+---------+------+");
      }
}