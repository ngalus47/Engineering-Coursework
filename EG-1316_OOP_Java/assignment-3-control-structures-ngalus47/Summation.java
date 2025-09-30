/**
* <h1>Adds numbers</h1>
* Adds all numbers inputed by user
*
* @author  Nick Galus
* @version 1.0
* @since   
*/

import java.util.Scanner;

public class Summation 
{
	/**
	* This method adds numbers together
	* @param args Unused.
	* @return Nothing.
	*/
	
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("This program will add all the numbers you enter");
		System.out.println("Enter 0 for me to stop adding");
		
		int num = 1;
		int sum = 0;
		
		while(num != 0)
		{
			num = Integer.parseInt(input.nextLine());
			sum += num;
			
			System.out.println("You entered " + num);
			System.out.println("The sum is " + sum);
		}
		
		System.out.println("The sum of all the numbers you entered is " + sum);
	
		input.close();
	}

}
