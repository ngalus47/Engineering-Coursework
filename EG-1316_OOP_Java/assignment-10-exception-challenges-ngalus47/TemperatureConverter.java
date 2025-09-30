import java.util.Scanner;

/**
 * <h1>TemperatureConverter</h1>
 * Converts a temperature from Celsius to Fahrenheit.
 * 
 * The program prompts the user to enter a Celsius temperature,
 * validates the input, and converts it to Fahrenheit.
 * If the entered value is below absolute zero or not a valid number,
 * an appropriate exception is handled.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class TemperatureConverter {

	/**
	 * The main method that reads user input, validates the temperature,
	 * and prints the Fahrenheit conversion.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Enter Celsius temperature: ");
		String tempInput = input.nextLine();

		try {
			double celsius = Double.parseDouble(tempInput);

			if (celsius < -273.15) {
				throw new InvalidTemperatureException();
			}

			double fahrenheit = (celsius * 9 / 5) + 32;
			System.out.printf("Fahrenheit: %.1f°F%n", fahrenheit);

		} catch (NumberFormatException e) {
			System.out.println("Invalid input. Please enter a valid number.");
		} catch (InvalidTemperatureException e) {
			System.out.println("InvalidTemperatureException: " + e.getMessage());
		} finally {
			input.close();
		}
	}
}
