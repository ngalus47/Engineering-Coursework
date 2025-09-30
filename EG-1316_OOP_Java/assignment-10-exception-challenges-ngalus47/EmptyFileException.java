/**
 * <h1>EmptyFileException</h1>
 * Custom checked exception that is thrown when a file is found
 * to be empty during file processing operations.
 * 
 * This exception is used to alert the user or program that 
 * the file contains no readable content.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class EmptyFileException extends Exception {

	private static final long serialVersionUID = 1L;

	/**
	 * Constructs an EmptyFileException with a default message.
	 */
	public EmptyFileException() {
		super("Empty file detected.");
	}
}
