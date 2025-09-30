import java.util.Scanner;

/**
 * <h1>PasswordValidator</h1>
 * This program validates a password based on the following rules:
 * it must be at least 8 characters long, contain at least one digit,
 * and contain at least one uppercase letter.
 * 
 * If the password does not meet the criteria, an InvalidPasswordException is thrown.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class PasswordValidator {

	/**
	 * The main method that prompts the user for a password
	 * and checks its validity.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Enter your password: ");
		String password = input.nextLine();

		try {
			validatePassword(password);
			System.out.println("Password accepted.");
		} catch (InvalidPasswordException e) {
			System.out.println("InvalidPasswordException: " + e.getMessage());
		}

		input.close();
	}

	/**
	 * Validates the password based on length, digit, and uppercase letter rules.
	 * 
	 * @param password the password string to validate
	 * @throws InvalidPasswordException if the password is invalid
	 */
	public static void validatePassword(String password) throws InvalidPasswordException {
		boolean hasDigit = false;
		boolean hasUpper = false;

		if (password.length() < 8) {
			throw new InvalidPasswordException();
		}

		for (int i = 0; i < password.length(); i++) {
			char c = password.charAt(i);
			if (Character.isDigit(c)) {
				hasDigit = true;
			}
			if (Character.isUpperCase(c)) {
				hasUpper = true;
			}
		}

		if (!hasDigit || !hasUpper) {
			throw new InvalidPasswordException();
		}
	}
}
