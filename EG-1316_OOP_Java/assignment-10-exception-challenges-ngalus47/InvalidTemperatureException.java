/**
 * <h1>InvalidTemperatureException</h1>
 * Custom checked exception that is thrown when a user enters 
 * a temperature value below absolute zero in Celsius.
 * 
 * This exception is used to prevent invalid scientific input.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class InvalidTemperatureException extends Exception {

	private static final long serialVersionUID = 1L;

	/**
	 * Constructs an InvalidTemperatureException with a default message.
	 */
	public InvalidTemperatureException() {
		super("Temperature cannot be below absolute zero.");
	}
}
