/**
 * <h1>Bank Account</h1>
 * A class representing a simple bank account with balance,
 * deposit, and withdrawal functionality. Throws an exception
 * if the starting balance is negative.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class BankAccount 
{
	private double balance;

	/**
	 * Default constructor that sets balance to 0.
	 */
	public BankAccount() 
	{
		balance = 0;
	}

	/**
	 * Constructor that sets a starting balance if it's non-negative.
	 * 
	 * @param startBalance The initial balance.
	 * @throws NegativeStartingBalance If startBalance is negative.
	 */
	public BankAccount(double startBalance) throws NegativeStartingBalance 
	{
		if (startBalance < 0) 
		{
			throw new NegativeStartingBalance(startBalance);
		}
		balance = startBalance;
	}

	/**
	 * Deposits money into the account.
	 * 
	 * @param amount The amount to deposit.
	 */
	public void deposit(double amount) 
	{
		balance += amount;
	}

	/**
	 * Withdraws money from the account.
	 * 
	 * @param amount The amount to withdraw.
	 */
	public void withdraw(double amount) 
	{
		if (amount > balance)
		{
			System.out.println("Withdrawal exceeds balance. Transaction canceled.");
			return;
		}
		balance -= amount;
	}


	/**
	 * Sets the account balance directly.
	 * 
	 * @param amount The new balance.
	 */
	public void setBalance(double amount) 
	{
		balance = amount;
	}

	/**
	 * Returns the current account balance.
	 * 
	 * @return The current balance.
	 */
	public double getBalance() 
	{
		return balance;
	}
	
	@Override
	public String toString() 
	{
		return String.format("BankAccount{balance=$%.2f}", balance);
	}

}
