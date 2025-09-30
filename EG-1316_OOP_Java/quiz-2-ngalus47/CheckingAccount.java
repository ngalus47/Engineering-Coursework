/**
 * <h1>Checking Account</h1>
 * Checking Account class which is a subclass of BankAccount
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-20
 */
public class CheckingAccount extends BankAccount {
	double overdraftLimit; //sets an overdraft limit

	//constructors below
	public CheckingAccount() {
		super();
		// TODO Auto-generated constructor stub
	}

	public CheckingAccount(String accountNumber, double balance, double overdraftLimit) {
		super(accountNumber, balance); //uses super class
		this.overdraftLimit = overdraftLimit;
	}

	//overrides the super class withdraw method to prevent overdraft
	@Override
	public void withdraw(double amount) {
		// TODO Auto-generated method stub
		System.out.printf("Attempting to withdraw $%.2f...\n", amount);
		
		if(amount <= balance + overdraftLimit) {
			super.withdraw(amount);
			System.out.println("Withdrawl Successful!");
		}
		else {
			System.out.println("Error: You went over your Overdraft Limit");
		}
		
	}
	
	
}
