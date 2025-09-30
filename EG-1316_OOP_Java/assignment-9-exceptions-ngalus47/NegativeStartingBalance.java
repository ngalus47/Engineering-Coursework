/**
 * <h1>Negative Starting Balance Exception</h1>
 * Thrown when a BankAccount is initialized with a negative starting balance.
 * 
 * This class implements Serializable via Exception inheritance and includes a serialVersionUID.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-06
 */
public class NegativeStartingBalance extends Exception 
{
	private static final long serialVersionUID = 1L;

	/**
	 * Default constructor for the exception.
	 */
	public NegativeStartingBalance() 
	{
		super("Starting balance cannot be negative.");
	}

	/**
	 * Constructor that accepts a custom message with balance value.
	 * 
	 * @param amount The negative balance amount.
	 */
	public NegativeStartingBalance(double amount) 
	{
		super("Invalid starting balance: $" + amount);
	}
}
