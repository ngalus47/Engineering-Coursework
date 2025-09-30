/**
* <h1>Prints multiples of 10 from 1-1000</h1>
* Simply prints out all multiples of 10 from 1-1000
*
* @author  Nick Galus
* @version 2.0
* @since   2025-02-09
*/

public class MultiplesOfTen 
{
	/**
	* This is the main method which prints out multiples of 10
	* @param args Unused.
	* @return Nothing.
	*/
	public static void main(String[] args) 
	{
		int count = 1;
		
		while(count <= 1000)
		{
			if(count % 100 == 0)
			{
				System.out.println(count);
			}
			else if(count % 10 == 0)
			{
				System.out.print(count + " ");
			}
			
			count++;
		}
	}

}
