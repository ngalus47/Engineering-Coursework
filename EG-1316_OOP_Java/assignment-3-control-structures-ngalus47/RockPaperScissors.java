/**
* <h1>Rock Paper Scissors Game</h1>
* Classic game of Rock Paper Scissors
*
* @author  Nick Galus
* @version 1.0
* @since   2025-02-09
*/

import java.util.Scanner;

public class RockPaperScissors 
{
	/**
	* This is the main method which controls the game loop
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args) 
	{
        Scanner input = new Scanner(System.in);

        for (int i = 0; i < 3; i++) 
        {
            System.out.println("Enter 0, 1, or 2");
            System.out.println("scissors (0), rock (1), paper (2):");

            int player = Integer.parseInt(input.nextLine());
            int randNum = (int) (Math.random() * 3);

            if ((player == 0 && randNum == 2))
            {
                System.out.println("You won: Scissors beats Paper");
            } 
            else if ((player == 1 && randNum == 0))
            {
                System.out.println("You won: Rock beats Scissors");
            } 
            else if ((player == 2 && randNum == 1)) 
            {
                System.out.println("You won: Paper beats Rock");
            } 
            else if ((player == 2 && randNum == 0)) 
            {
                System.out.println("You lose: Scissors beats Paper");
            } 
            else if ((player == 0 && randNum == 1))
            {
                System.out.println("You lose: Rock beats Scissors");
            } 
            else if ((player == 1 && randNum == 2))
            {
                System.out.println("You lose: Paper beats Rock");
            } 
            else 
            {
                System.out.println("Tie");
            }
        }
        
        input.close();
	}
}
