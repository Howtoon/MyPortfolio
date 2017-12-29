public class SalaryException extends Exception {
	
	public SalaryException(){
		super("Salary is negative.");
	}
	public SalaryException(double salary){
		super("$"+salary+" is too low");
	}
}