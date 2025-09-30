/**
 * <h1>Bank Test</h1>
 * Tests out basic inheritance banking system
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-20
 */
public class BankTest {

	/**
	 * 
	    * This is the main method which creates the checking and savings objects,
	    * modifys them
	    * 
	    * @param args Unused.
	    * @return Nothing.
	 */
	public static void main(String[] args) {
		SavingsAccount savings = new SavingsAccount("Savings Account: 1234", 1000, .05);
		CheckingAccount checking = new CheckingAccount("Checking Account: 4321", 500, 100);
		
		System.out.printf("Savings Account Balance: $%.2f\n", savings.getBalance());
		
		savings.applyInterest();
		
		System.out.printf("New Savings Account Balance: $%.2f\n", savings.getBalance());
		
		System.out.printf("Checking Account Balance: $%.2f\n", checking.getBalance());
		
		checking.withdraw(600);
		
		System.out.printf("New Chekcing Account Balance: $%.2f", checking.getBalance());
	}

}
