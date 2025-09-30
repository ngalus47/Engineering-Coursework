import java.util.Scanner;

/**
 * <h1>StudentRegistration</h1>
 * Simulates the process of registering a student for a course.
 * 
 * The program prompts the user to enter a course code and then
 * attempts to register the student using the Student class.
 * If the course code is not among the allowed values,
 * a CourseNotFoundException is thrown.
 * 
 * This serves as a single-use driver for course registration testing.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class StudentRegistration {

	/**
	 * The main method that prompts the user for a course code and
	 * attempts to register the student.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Student student = new Student("Nick");

		System.out.print("Enter course code to register: ");
		String code = input.nextLine();

		try {
			student.registerCourse(code);
		} catch (CourseNotFoundException e) {
			System.out.println("CourseNotFoundException: " + e.getMessage());
		} finally {
			input.close();
		}
	}
}
