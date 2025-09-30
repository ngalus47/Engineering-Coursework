/**
* <h1>Find the sum of all numbers</h1>
* Gets the sum of all numbers from input
*
* @author  Nick Galus
* @version 1.0
* @since   02-09-2025
*/

import java.util.Scanner;

public class SumOfNumbers 
{
	/**
	* This is the main method which adds all numbers from
	* 1 to the entered number
	* @param args Unused.
	* @return Nothing.
	*/
	
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		
		int sum = 0;
				
		System.out.println("This program will add all the numbers from 1 to the number you enter");
		System.out.println("Please enter a number");
		
		int num = input.nextInt();
		
		for(int i = 1; i <= num; i++)
		{
			sum += i;
		}
			
		System.out.println("You entered " + num);
		System.out.println("The sum of all numbers from 1 to " + num + " is " + sum);	
		
		input.close();
	}

}
