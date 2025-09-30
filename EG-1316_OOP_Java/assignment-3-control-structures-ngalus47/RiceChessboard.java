/**
* <h1>Powers of 2</h1>
* Finds solves each power of 2 from 1 to 64
*
* @author  Nick Galus
* @version 1.0
* @since   
*/

public class RiceChessboard {

	/**
	* This is the main method which computes the powers
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args) 
	{
		for(int i = 0; i < 64; i++)
		{
			System.out.println(((long)(Math.pow(2, i)) + " rice on square " + (i + 1)));
		}
	}

}
