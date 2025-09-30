/**
 * <h1>Mersenne Prime Finder!</h1>
 * The Mersenne program implements an application that
 * prints all Mersenne primes smaller than a given number
 * and the total count of these primes.
 *
 * @author  Nick Galus
 * @version 1.0
 * @since   2025-02-13
 */

import java.util.Scanner;

public class Mersenne {

    /**
     * This is the main method which prints Mersenne primes smaller than a given number.
     * @param args Unused.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a number. The System will find all the Mersenne prime numbers smaller than this number: ");
        int number = scanner.nextInt();

        int count = 0;
        for (int i = 1; ; i++) {
            int mersenne = (int) Math.pow(2, i) - 1;
            if (mersenne >= number) {
                break;
            }
            if (isPrime(mersenne)) {
                System.out.print(mersenne + "\t");
                count++;
            }
        }

        System.out.println("\nThere are a total of " + count + " Mersenne prime numbers");

        scanner.close();
    }

    /**
     * Method to check if a number is prime.
     * @param num The number to check.
     * @return true if the number is prime, false otherwise.
     */
    public static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
