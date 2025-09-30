/**
* <h1>Prints numbers from 1-1000</h1>
* Simply prints out all numbers from 1-1000
*
* @author  Nick Galus
* @version 1.0
* @since   2025-02-09
*/

public class ThousandNumbers 
{
	/**
	* This is the main method which prints out numbers 1-1000.
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args) 
	{
		int count = 1;
		
		while(count <= 1000)
		{
			if(count % 10 == 0)
			{
				System.out.println(count);
			}
			else
			{
				System.out.print(count + " ");
			}
			
			count++;
		}
	}

}
