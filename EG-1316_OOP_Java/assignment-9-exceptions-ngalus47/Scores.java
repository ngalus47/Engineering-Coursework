/**
 * <h1>Scores</h1>
 * This class processes an array of test scores. It calculates
 * the average score and validates that each score is within 0–100.
 * If a score is invalid, it throws an IllegalArgumentException.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class Scores 
{
	private double[] scores;

	/**
	 * Constructor that accepts an array of test scores.
	 * 
	 * @param scores The array of scores to process.
	 * @throws IllegalArgumentException if any score is less than 0 or greater than 100.
	 */
	public Scores(double[] scores) 
	{
		for (double score : scores) 
		{
			if (score < 0 || score > 100) 
			{
				throw new IllegalArgumentException("Scores must be between 0 and 100");
			}
		}
		this.scores = scores;
	}

	/**
	 * Calculates and returns the average of the scores.
	 * 
	 * @return The average score.
	 */
	public double getAverage() 
	{
		double total = 0;
		for (double score : scores) 
		{
			total += score;
		}
		return total / scores.length;
	}
}
