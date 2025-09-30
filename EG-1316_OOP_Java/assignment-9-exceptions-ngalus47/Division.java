import java.util.Scanner;

/**
 * <h1>Division Program</h1> 
 * This program takes two numbers from the user and
 * divides the first by the second. It handles invalid input and division by
 * zero.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class Division {
	/**
	 * This is the main method that runs the division operation. It prompts for user
	 * input, handles exceptions, and performs the division.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		try {
			System.out.print("Enter the first number: ");
			double num1 = input.nextDouble();

			System.out.print("Enter the second number: ");
			double num2 = input.nextDouble();

			if (num2 == 0) {
				System.out.println("Cannot divide by zero.");
			} else {
				System.out.println("The result is " + (num1 / num2));
			}
		} catch (java.util.InputMismatchException e) {
			System.out.println("Invalid input. Please enter numeric values.");
		} finally {
			input.close();
		}
	}
}
