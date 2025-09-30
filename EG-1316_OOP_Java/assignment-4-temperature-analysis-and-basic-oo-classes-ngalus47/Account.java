import java.util.Date;

/**
 * <h1>Account</h1>
 * Represents a bank account with an id, balance, annual interest rate, and the date the account was created.
 * Provides methods to perform deposits, withdrawals, and to calculate the monthly interest rate.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class Account {
    int id;
    double balance;
    double annualInterestRate;
    Date dateCreated;
    
    /**
     * Default constructor that initializes an account with default values.
     */
    public Account() {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
        dateCreated = new Date();
    }
    
    /**
     * Constructs an Account with a specified id, balance, annual interest rate, and creation date.
     * 
     * @param id the account id.
     * @param balance the initial balance.
     * @param annualInterestRate the annual interest rate.
     * @param dateCreated the date the account was created.
     */
    public Account(int id, double balance, double annualInterestRate, Date dateCreated) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        this.dateCreated = dateCreated;
    }
    
    /**
     * Returns the account id.
     * 
     * @return the id.
     */
    public int getId() {
        return id;
    }
    
    /**
     * Sets the account id.
     * 
     * @param id the new id.
     */
    public void setId(int id) {
        this.id = id;
    }
    
    /**
     * Returns the current balance of the account.
     * 
     * @return the balance.
     */
    public double getBalance() {
        return balance;
    }
    
    /**
     * Sets the balance of the account.
     * 
     * @param balance the new balance.
     */
    public void setBalance(double balance) {
        this.balance = balance;
    }
    
    /**
     * Returns the annual interest rate of the account.
     * 
     * @return the annual interest rate.
     */
    public double getAnnualInterestRate() {
        return annualInterestRate;
    }
    
    /**
     * Sets the annual interest rate of the account.
     * 
     * @param annualInterestRate the new annual interest rate.
     */
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }
    
    /**
     * Returns the date when the account was created.
     * 
     * @return the dateCreated.
     */
    public Date getDateCreated() {
        return dateCreated;
    }
    
    /**
     * Calculates and returns the monthly interest rate.
     * Computed by dividing the annual interest rate by 12.
     * 
     * @return the monthly interest rate.
     */
    public double getMonthlyInterestRate() {
        return annualInterestRate / 12;
    }
    
    /**
     * Withdraws a specified amount from the account.
     * 
     * @param amount the amount to withdraw.
     */
    public void withdraw(double amount) {
        balance -= amount;
    }
    
    /**
     * Deposits a specified amount into the account.
     * 
     * @param amount the amount to deposit.
     */
    public void deposit(double amount) {
        balance += amount;
    }
}
