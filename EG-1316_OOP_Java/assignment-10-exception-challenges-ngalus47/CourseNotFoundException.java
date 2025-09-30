/**
 * <h1>CourseNotFoundException</h1>
 * Custom checked exception that is thrown when a user tries 
 * to register for a course that is not in the allowed course list.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class CourseNotFoundException extends Exception {

	private static final long serialVersionUID = 1L;

	/**
	 * Constructs a new CourseNotFoundException with a detailed message.
	 * 
	 * @param message the detail message explaining the invalid course
	 */
	public CourseNotFoundException(String message) {
		super(message);
	}
}
