import java.util.*;

public class P5 {
	public static void main(String[] args) {
		int age;
		Scanner kb = new Scanner(System.in);
		System.out.println("Written by Bilal Gonen\n"); // CHANGE FOR YOUR NAME
		for (int i = 1; i <= 3; i++) {
			try {
				kb = new Scanner(System.in);
				System.out.print("Enter an age: ");
				age = kb.nextInt();

				COMPLETE



			} // end try block
			catch (AgeException e1) {
				System.out.println("In catch clause: " + COMPLETE  );
			}
			catch ( // complete for Non-integer entries  ) {
				COMPLETE
			}
		}
	}
}
