import java.util.*;

public class Tester{
	private static double readSalary() throws SalaryException{
		double salary=0;
		Scanner kb = new Scanner(System.in);
		try {
			salary=kb.nextDouble();
		}
		catch(InputMismatchException e){
			System.out.println("You did not enter a number");
		}
		return salary;
	}
	public static void main(String[] args){
		double salary;	
		boolean loop=false;				
		while (!loop){
			System.out.print("Enter salary: $");
			try {
				salary=readSalary();
				if (salary<0){
					throw new SalaryException();
				}
				else if (salary<7.5){
					throw new SalaryException(salary);
				}
				loop=true;
				System.out.println("You entered: $"+ salary);		
			}
			catch(SalaryException se){
				System.out.println(se.getMessage());
			}
		}
	}
}