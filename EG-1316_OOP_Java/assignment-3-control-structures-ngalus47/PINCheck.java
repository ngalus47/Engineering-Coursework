/**
* <h1>Verifies correct PIN input</h1>
* Verifies PIN is inputed correctly through iteration
*
* @author  Nick Galus
* @version 1.0
* @since   
*/

import java.util.Scanner;

public class PINCheck 
{
	/**
	* This is the main method which keeps looking until 
	* correct pin is inputed
	* @param args Unused.
	* @return Nothing.
	*/
	
	public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Please enter your PIN");
        int pin = input.nextInt();

        System.out.println("Please confirm your PIN");
        int confirmPin = input.nextInt();

        while (confirmPin != pin) {
            System.out.println("Incorrect PIN. Try again");
            System.out.println("Enter your PIN");
            confirmPin = input.nextInt();
        }

        System.out.println("PIN accepted. You can access your account");
    
        input.close();
	}
}
