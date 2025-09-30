/**
 * <h1>Prime Number Checker!</h1>
 * The PrimeCheck program implements an application that
 * checks if a number is prime or not and prints the result.
 * The program continues to ask for new numbers until the user enters 0.
 *
 * @author  Nick Galus
 * @version 1.0
 * @since   2025-02-13
 */

import java.util.Scanner;

public class PrimeCheck {

    /**
     * This is the main method which checks if numbers are prime.
     * @param args Unused.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("This program will tell you if the number you enter is prime or not");
        System.out.println("You can enter 0 anytime to stop the program");

        while (true) {
            System.out.println("Please enter a number: ");
            int number = scanner.nextInt();

            if (number == 0) {
                System.out.println("0 is not prime");
                break;
            }

            if (isPrime(number)) {
                System.out.println(number + " is prime");
            } else {
                System.out.println(number + " is not prime");
            }
        }

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
