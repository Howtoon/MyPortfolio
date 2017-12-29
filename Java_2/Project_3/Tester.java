// Instructor: William Tennis
// Spring 2016
// Project 3
public class Tester {
	private static void displayVehicleInfo(Vehicle v){
		v.info();
	}
	
	public static void main(String[] args) {
		System.out.println("Programmed by William Tennis.\n");
		// Update the line above for YOUR name. DO NOT MODIFY BELOW THIS LINE.
		
		Car c1 = new Car("pink");
		Plane p1 = new Plane("purple");
		displayVehicleInfo(c1);
		displayVehicleInfo(p1);

	}
}