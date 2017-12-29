//import java.util.Scanner;
//import java.util.InputMismatchException;
import java.util.*;
public class Feb15{
	public static void main(String[] args){
		double num=0;
		boolean loop=false;
		Scanner kb=new Scanner(System.in);
		while (!loop){
			System.out.print("Enter a numerical value:");
			try {
				num=kb.nextDouble();
				loop=true;
				System.out.println("You entered "+ num);
				
			}
			catch(InputMismatchException e){
				kb.nextLine();//Clears the Buffer
				System.out.println("You must be a Banana because you did not enter a numerical value.");
		
			}
		}
	System.out.println("Sweet Home Alabama");s
	}
}