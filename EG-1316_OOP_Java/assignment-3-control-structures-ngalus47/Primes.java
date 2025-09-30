/**
 * <h1>Prime Numbers Finder!</h1>
 * The Primes program implements an application that
 * prints all prime numbers smaller than a given number
 * and the total count of these prime numbers.
 *
 * @author  Nick Galus
 * @version 1.0
 * @since   2024-02-13
 */

import java.util.Scanner;

public class Primes {

    /**
     * This is the main method which prints prime numbers smaller than a given number.
     * @param args Unused.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a number. The System will find all the prime numbers smaller than this number: ");
        int number = scanner.nextInt();

        int count = 0;
        for (int i = 2; i < number; i++) {
            if (isPrime(i)) {
                System.out.print(i + "\t ");
                count++;
                
                if(count % 10 == 0)
                {
                	System.out.println();
                }
            }
        }

        System.out.println("\nThere are a total of " + count + " prime numbers");

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
