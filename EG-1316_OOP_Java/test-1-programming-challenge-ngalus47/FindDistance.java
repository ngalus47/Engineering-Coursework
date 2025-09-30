import java.util.Scanner;

/**
 * <h1>Finds AVG Distance between 2 points!</h1> Determins if the distance
 * between 2 points is either short, medium, or long
 *
 * @author Nick Galus
 * @version 1.0
 * @since 02-27-2025
 */

public class FindDistance {
	/**
	 * This method uses the distance formula to calculate the distance between two
	 * points
	 * 
	 * @param double[][] 2d array that contains 1st and 2nd coordinates
	 * @return distance
	 */
	static double getDistance(double[][] coords) {
		return Math.sqrt(Math.pow((coords[1][0] - coords[0][0]), 2) + Math.pow((coords[1][1] - coords[0][1]), 2));
	}

	/**
	 * Classifies the distance based on distance
	 * 
	 * @param distance distance between two points
	 * @return classification
	 */
	static String classifyDistance(double distance) {
		if (distance < 5) {
			return "Short";
		} else if (distance <= 15) {
			return "Medium";
		}

		return "Long";
	}

	/**
	 * This is the main method which makes use of findAvg method.
	 * 
	 * @param args Unused.
	 * @return Nothing.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		double[][] coordinates = new double[2][2];
		double distance;

		System.out.println("Please enter the x and y values for the first point");
		System.out.println("x:");

		coordinates[0][0] = input.nextDouble();

		System.out.println("y: ");

		coordinates[0][1] = input.nextDouble();

		System.out.println("Please enter the x and y values for the second point");
		System.out.println("x:");

		coordinates[1][0] = input.nextDouble();

		System.out.println("y: ");

		coordinates[1][1] = input.nextDouble();

		distance = getDistance(coordinates);

		System.out.printf("The distnace between these two points is %.2f\n", distance);
		System.out.println("Classification: " + classifyDistance(distance));

		input.close();
	}
}
