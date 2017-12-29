// Instructor: Bilal Gonen
// Spring 2016
// Project 4
public class Tester {

	
	public static void main(String[] args) {
		System.out.println("Programmed by William Tennis.\n");
		// Update the line above for YOUR name. DO NOT MODIFY BELOW THIS LINE.
		Plane p1 = new Plane(30);
		Plane p2 = new Plane(40);
		Vehicle v1 = new Vehicle(50);
		Vehicle v2 = new Vehicle(60);
		
		v1.compareRaceSpeeds(p1);
		v1.compareRaceSpeeds(p2);
		p1.compareRaceSpeeds(v1);
		v2.compareRaceSpeeds(v1);
		p2.compareRaceSpeeds(p1);

	}
}