/**
 * <h1>Bank Account</h1>
 * Super class that contains balance and account number
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-20
 */
public class BankAccount {
	String accountNumber;
	double balance;
	
	//constructors
	public BankAccount()	{
		accountNumber = null;
		balance = 0;
	}
	
	public BankAccount(String accountNumber, double balance) {
		super();
		this.accountNumber = accountNumber;
		this.balance = balance;
	}

	//getter method
	public double getBalance() {
		return balance;
	}
	
	//modifiers
	public void deposit(double amount) {
		balance += amount;
	}
	
	public void withdraw(double amount) {
		balance -= amount;
	}
}
