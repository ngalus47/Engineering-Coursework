import java.util.Scanner;

public class FindAverage 
{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);

		System.out.println("Please enter a number");
		int num1 = scanner.nextInt();
		
		System.out.println("Please enter another number");
		int num2 = scanner.nextInt();
		
		System.out.println("Please enter another number");
		int num3 = scanner.nextInt();
		
		double avg = ((num1 + num2 + num3) / 3.0);
		System.out.println("The average of " + num1 + " and " + num2 + " and " + num3 + " is " + avg);
	}
}
