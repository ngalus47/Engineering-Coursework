/**
* <h1>Flips a coin</h1>
* Flips a coin and prints number of times
* it landed on heads and number of times it
* landed on tails
*
* @author  Nick Galus
* @version 1.0
* @since   2025-02-10
*/

import java.util.Scanner;

public class CoinToss
{

	/**
	* This is the main method which flips the coin
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("How many coin tosses do you need?");
		
		int num = input.nextInt();
		int heads = 0;
		int tails = 0;
		
		System.out.println("Now I will toss the coin " + num + " times.");
		
		for(int i = 0; i < num; i++)
		{
			if(((int)(Math.random() * 2)) == 0)
			{
				System.out.println("Toss:\theads");
				heads++;
			}
			else
			{
				System.out.println("Toss:\ttails");
				tails++;
			}
		}
		
		System.out.println("Heads facing up: " + heads);
		System.out.println("Tails facing up: " + tails);
		
		input.close();
	}

}
