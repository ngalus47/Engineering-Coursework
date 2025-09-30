/**
 * <h1>InvalidPasswordException</h1>
 * Custom checked exception that is thrown when a password 
 * does not meet the specified validation criteria.
 * 
 * The password must be at least 8 characters long and contain 
 * at least one digit and one uppercase letter.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class InvalidPasswordException extends Exception {

	private static final long serialVersionUID = 1L;

	/**
	 * Constructs an InvalidPasswordException with a default message.
	 */
	public InvalidPasswordException() {
		super("Password must be at least 8 characters, contain one digit and one uppercase letter.");
	}
}
