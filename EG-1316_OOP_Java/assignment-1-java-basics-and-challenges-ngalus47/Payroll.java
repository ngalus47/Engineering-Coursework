import java.util.Scanner;

public class Payroll 
{
	public static void main(String[] args) 
	{
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Please enter your name");
        String name = scanner.nextLine();
        System.out.println("Your name is " + name);
        
        System.out.println("How many hours did you work last week?");
        int hours = scanner.nextInt();
        System.out.println("You worked " + hours + " hours");
        
        System.out.println("What is your hourly pay rate?");
        float payRate = scanner.nextFloat();
        System.out.printf("Your hourly payrate is %.1f dollars\n", payRate);
        
        System.out.printf("Hello Mike, your weekly gross payment is $%.1f", (hours * payRate));
	}

}
