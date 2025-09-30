/**
 * <h1>Student</h1>
 * Represents a student who can register for predefined course codes.
 * 
 * The student is allowed to register only for courses listed in the allowedCourses array.
 * If an invalid course is entered, a CourseNotFoundException is thrown.
 * 
 * This class is part of a course registration simulation.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class Student {

	private String name;

	/**
	 * Constructs a Student with the specified name.
	 * 
	 * @param name the student's name
	 */
	public Student(String name) {
		this.setName(name);
	}

	/**
	 * Attempts to register the student for a given course.
	 * 
	 * @param courseCode the code of the course to register for
	 * @throws CourseNotFoundException if the course code is not in the allowed list
	 */
	public void registerCourse(String courseCode) throws CourseNotFoundException {
		String[] allowedCourses = { "CS101", "MATH201", "BIO301" };
		boolean found = false;

		for (String course : allowedCourses) {
			if (course.equalsIgnoreCase(courseCode)) {
				found = true;
				break;
			}
		}

		if (!found) {
			throw new CourseNotFoundException(courseCode + " is not a valid course.");
		}

		System.out.println("Successfully registered for " + courseCode.toUpperCase());
	}

	/**
	 * Returns the student's name.
	 * 
	 * @return the name of the student
	 */
	public String getName() {
		return name;
	}

	/**
	 * Sets the student's name.
	 * 
	 * @param name the new name of the student
	 */
	public void setName(String name) {
		this.name = name;
	}
}
