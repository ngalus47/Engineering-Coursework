import java.util.Scanner;

/**
 * <h1>TestFan</h1> This program tests the Fan class by reading fan attributes
 * from the user, creating a Fan object, and displaying its state.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class TestFan {

	/**
	 * The main method prompts the user for the fan's speed, status, radius, and
	 * color, then creates a Fan object with these values and prints its details.
	 *
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		// Create a Scanner object to read user input
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter the fan speed and parse the input as an integer
		System.out.print("Enter the fan speed : ");
		int speed = Integer.parseInt(input.nextLine());

		// Prompt the user to enter the fan status ("on" or "off") and convert it to a
		// boolean
		System.out.print("Enter the fan status (on/off): ");
		boolean fanStatus = input.nextLine().equalsIgnoreCase("on") ? true : false;

		// Prompt the user to enter the fan radius and parse the input as a double
		System.out.print("Enter the fan radius: ");
		double radius = Double.parseDouble(input.nextLine());

		// Prompt the user to enter the color of the fan
		System.out.print("Enter the color of the fan: ");
		String color = input.nextLine();

		// Create a Fan object with the provided attributes
		Fan fan = new Fan(speed, fanStatus, radius, color);

		// Display the fan's details using its toString() method
		System.out.println(fan.toString());

		// Close the scanner to free resources
		input.close();
	}
}
