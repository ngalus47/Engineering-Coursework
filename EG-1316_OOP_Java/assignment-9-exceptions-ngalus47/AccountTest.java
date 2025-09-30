import java.util.Scanner;

/**
 * <h1>Account Test</h1>
 * This class tests the BankAccount class with valid and invalid input,
 * catching any exceptions related to starting balances.
 * 
 * It prompts the user for an initial balance and performs deposit
 * and withdrawal operations.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class AccountTest 
{
	/**
	 * Main method that runs the test.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);

		try 
		{
			System.out.print("Enter starting balance: ");
			double start = input.nextDouble();

			BankAccount account = new BankAccount(start);

			System.out.print("Enter amount to deposit: ");
			account.deposit(input.nextDouble());

			System.out.print("Enter amount to withdraw: ");
			account.withdraw(input.nextDouble());

			System.out.printf("Final balance: $%.2f%n", account.getBalance());
		} 
		catch (NegativeStartingBalance e) 
		{
			System.out.println("Error: " + e.getMessage());
		}
		finally 
		{
			input.close();
		}
	}
}
