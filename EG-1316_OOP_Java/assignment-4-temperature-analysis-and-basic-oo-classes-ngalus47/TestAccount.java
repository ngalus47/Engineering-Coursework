import java.util.Date;

/**
 * <h1>TestAccount</h1>
 * This program tests the Account class by performing deposit and withdrawal operations,
 * then prints the updated balance, monthly interest rate, and the account creation date.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class TestAccount {
    
    /**
     * The main method creates an Account object, performs transactions, and displays the account details.
     *
     * @param args Unused.
     */
    public static void main(String[] args) {
        // Create an Account with account number, initial balance, annual interest rate, and creation date.
        Account account = new Account(123, 10000, 2.5, new Date());
        
        // Perform a withdrawal and deposit.
        account.withdraw(1500);
        account.deposit(2500);
        
        // Display the account balance.
        System.out.println("Your balance is $" + account.getBalance());
        
        // Display the monthly interest rate. Note: '%%' is used to print a literal '%' symbol.
        System.out.printf("Your monthly interest is %.2f%%\n", account.getMonthlyInterestRate());
        
        // Display the date when the account was created.
        System.out.println("This account was created on " + account.getDateCreated());
    }
}
