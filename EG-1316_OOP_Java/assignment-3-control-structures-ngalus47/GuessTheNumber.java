/**
* <h1>High Low Game</h1>
* Guess the correct number from 1-100
*
* @author  Nick Galus
* @version 1.0
* @since   2025-02-10
*/

import java.util.Scanner;

public class GuessTheNumber {

	/**
	* This is the main method which holds the game loop
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args)
	{
        Scanner scanner = new Scanner(System.in);
        
        int targetNumber = (int) (Math.random() * 100) + 1;
        int guessCount = 0;
        int guess;
        
        System.out.println("Guess a number between 1 and 100");

        do {
            System.out.print("Enter your guess: ");
            guess = scanner.nextInt();
            guessCount++;

            if (guess > targetNumber) {
                System.out.println("Too high. Try again");
            } else if (guess < targetNumber) {
                System.out.println("Too low. Try again");
            } else {
                System.out.println("Yes, the number is " + targetNumber);
                System.out.println("You guessed the correct number in " + guessCount + " guesses.");
            }
        } while (guess != targetNumber);
        
        scanner.close();
    }
}
