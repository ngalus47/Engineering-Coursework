import java.util.Scanner;

public class ComputeFutureValue 
{

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Please enter the principal (initial investment): ");
        double principal = scanner.nextDouble();
        
        System.out.print("Please enter the annual interest rate (e.g., 4.5 for 4.5%): ");
        double annualInterestRate = scanner.nextDouble();
        
        System.out.print("Please enter the number of years: ");
        int years = scanner.nextInt();
        
        double monthlyInterestRate = annualInterestRate / 1200;
        double investment = principal * Math.pow(1 + monthlyInterestRate, years * 12);
        
        System.out.printf("Your future investment value is: %.2f%n", investment);
    }
}
