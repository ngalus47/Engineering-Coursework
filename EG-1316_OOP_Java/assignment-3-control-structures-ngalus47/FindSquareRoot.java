/**
 * <h1>Find the square root of a number!</h1>
 * The FindSquareRoot program implements an application that
 * calculates the square root of a number iteratively using Newton's method
 * and prints the output on the screen.
 *
 * @author  Nick Galus
 * @version 1.0
 * @since   2024-02-13
 */

import java.util.Scanner;

public class FindSquareRoot {

    /**
     * This is the main method which calculates the square root iteratively.
     * @param args Unused.
     */
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("The program will find the square root of a number");
        System.out.println("Enter a positive integer: ");
        double number = scanner.nextDouble();

        double lastGuess = 1.0;
        double nextGuess;
        int iterations = 0;

        do {
            nextGuess = (lastGuess + number / lastGuess) / 2;
            iterations++;
            if (Math.abs(nextGuess - lastGuess) < 0.000001) {
                break;
            }
            lastGuess = nextGuess;
        } while (true);

        System.out.println("The square root of " + number + " is " + nextGuess);
        System.out.println("The program found the result in " + iterations + " iterations");

        scanner.close();
    }
}
