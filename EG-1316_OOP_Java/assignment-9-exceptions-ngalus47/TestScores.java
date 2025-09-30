import java.util.Scanner;
import java.util.InputMismatchException;

/**
 * <h1>Test Scores</h1>
 * This class tests the Scores class by allowing the user
 * to input a series of test scores and then computes the average.
 * It catches any exception if a score is out of range.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class TestScores 
{
	/**
	 * This is the main method that drives the program.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);

		try 
		{
			System.out.print("How many test scores will you enter? ");
			int size = input.nextInt();

			if (size <= 0) 
			{
				throw new IllegalArgumentException("Size must be greater than 0. Please restart program");
			}

			double[] userScores = new double[size];

			for (int i = 0; i < size; i++) 
			{
				boolean valid = false;

				while (!valid) 
				{
					System.out.print("Enter score #" + (i + 1) + ": ");
					
					try 
					{
						double score = input.nextDouble();

						if (score < 0 || score > 100) 
						{
							throw new IllegalArgumentException("Scores must be between 0 and 100");
						}

						userScores[i] = score;
						valid = true;
					} 
					catch (InputMismatchException e) 
					{
						System.out.println("Invalid input. Score must be a number.");
						input.next(); // Clear the invalid token
					} 
					catch (IllegalArgumentException e) 
					{
						System.out.println("Invalid score: " + e.getMessage());
					}
				}
			}

			Scores scores = new Scores(userScores);
			System.out.printf("The average score is: %.2f%n", scores.getAverage());
		} 
		catch (InputMismatchException e) 
		{
			System.out.println("Error: Invalid input. Size must be a whole number. Please restart program");
		}
		catch (IllegalArgumentException e) 
		{
			System.out.println("Error: " + e.getMessage());
		}
		finally 
		{
			input.close();
		}
	}
}
