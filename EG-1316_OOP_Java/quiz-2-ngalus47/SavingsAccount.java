/**
 * <h1>Savings Account</h1>
 * Savings Account class which is a subclass of BankAccount
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-20
 */
public class SavingsAccount extends BankAccount {
	double interestRate; //interest rate of savings account

	//constructors
	public SavingsAccount() {
		super();
		// TODO Auto-generated constructor stub
	}

	public SavingsAccount(String accountNumber, double balance, double interestRate) {
		super(accountNumber, balance);
		this.interestRate = interestRate;
	}
	
	//modifies the balance by applying interest
	public void applyInterest() {
		System.out.println("Applying Interest...");
		super.balance += super.balance * interestRate;
	}
}
