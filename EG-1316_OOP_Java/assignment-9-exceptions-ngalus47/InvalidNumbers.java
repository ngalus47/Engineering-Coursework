import java.util.Scanner;
import java.util.InputMismatchException;

/**
 * <h1>Invalid Numbers</h1>
 * This program prompts the user to enter a positive integer. It handles invalid inputs
 * such as non-integer values, negative numbers, and values that exceed integer limits.
 * 
 * The program continues to prompt the user until a valid positive integer is entered.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class InvalidNumbers 
{
	/**
	 * This is the main method that checks for valid positive integer input.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int number = 0;
		boolean valid = false;
		
		while (!valid) 
		{
			System.out.println("Enter a positive integer: ");
			try 
			{
				int longInput = input.nextInt();
				
				if (longInput <= 0)
				{
					throw new IllegalArgumentException("A positive integer is required");
				}
				
				number = (int) longInput;
				valid = true;
			} 
			catch (InputMismatchException e) 
			{
				System.out.println("Try again. (Incorrect input: A positive integer is required)");
				input.next(); 
			} 
			catch (IllegalArgumentException e) 
			{
				System.out.println("Try again. (Incorrect input: " + e.getMessage() + ")");
			}
		}
		
		System.out.println("The number entered is " + number);
		System.out.println("Thank you");
		
		input.close();
	}
}
