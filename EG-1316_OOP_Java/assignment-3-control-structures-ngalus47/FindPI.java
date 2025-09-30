/**
 * <h1>Calculate PI using the Leibniz formula!</h1>
 * The FindPI program implements an application that
 * calculates the value of PI iteratively using the Leibniz formula
 * and prints the output on the screen.
 *
 * @author  Nick Galus
 * @version 1.0
 * @since   2025-02-13
 */

import java.util.Scanner;

public class FindPI {

    /**
     * This is the main method which calculates PI using the Leibniz formula.
     * @param args Unused.
     */
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("This program will iteratively find the digits of PI using the Leibniz formula");
        System.out.print("How many iterations should we use? Please enter an integer: ");
        
        int iterations = scanner.nextInt();

        long startTime = System.currentTimeMillis();

        double pi = 0.0;
        
        for (int i = 0; i < iterations; i++) 
        {
            pi += Math.pow(-1, i) / (2 * i + 1);
        }
        pi *= 4;

        long endTime = System.currentTimeMillis();

        System.out.printf("PI = %.15f%n", pi);
        System.out.println("After " + iterations + " iterations.");
        System.out.printf("This operation took %.2f seconds.%n", (endTime - startTime) / 1000.0);

        scanner.close();
    }
}
