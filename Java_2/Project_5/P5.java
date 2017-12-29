
import java.util.*;

public class P5 {
	public static void main(String[] args){
		int age=0;
		Scanner kb = new Scanner(System.in);
		System.out.println("Written by William Tennis\n"); 
		for (int i = 1; i <= 3; i++) {
			try {
				kb = new Scanner(System.in);
				System.out.print("Enter an age: ");
				age = kb.nextInt();
				if (age<0){
               throw new AgeException();
            }
            if (age>150){
               throw new AgeException(age);
			   }
         }      
			catch (AgeException ae) {
				System.out.println("In catch clause: "+ae.getMessage());
         }
			catch (InputMismatchException e2 ) {
				System.out.println("Input must be integer..");
			}
		}
	}
}
