/**
* <h1>Numeric Password Generator!</h1>
* Generates a numeric password based on input
* 
* @author  Nick Galus
* @version 1.0
* @since   02-09-2025
*/

import java.util.Scanner;

public class PasswordGenerator 
{
	/**
	* This is the main method which generates the random password
	* @param args Unused.
	* @return Nothing.
	*/
		
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("How many digits do you want to use for a numeric password?");
		
		int digiLen = input.nextInt();
		
		System.out.println("Your password is");
		
		for(int i = 0; i < digiLen; i++)
		{
			int random = (int)(Math.random() * 10);
			
			System.out.print(random + " ");
		}
		
		input.close();
	}

}
