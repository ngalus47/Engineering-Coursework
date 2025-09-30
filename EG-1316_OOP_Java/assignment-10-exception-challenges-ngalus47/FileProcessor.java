import java.io.*;
import java.util.*;

/**
 * <h1>FileProcessor</h1>
 * Processes a text file and reports the number of lines and words.
 * If the file is empty, an EmptyFileException is thrown.
 * 
 * The program prompts the user for a filename, reads the contents,
 * counts non-empty lines and words, and displays the results.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-04-15
 */
public class FileProcessor {

	/**
	 * The main method that initiates the file processing sequence.
	 * 
	 * @param args Unused.
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the file name: ");
		String filename = input.nextLine();

		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			String line;
			int lineCount = 0;
			int wordCount = 0;

			while ((line = reader.readLine()) != null) {
				if (!line.trim().isEmpty()) {
					lineCount++;
					String[] words = line.trim().split("\\s+");
					wordCount += words.length;
				}
			}

			if (lineCount == 0) {
				throw new EmptyFileException();
			}

			System.out.println("Total lines: " + lineCount);
			System.out.println("Total words: " + wordCount);

		} catch (FileNotFoundException e) {
			System.out.println("File not found: " + filename);
		} catch (IOException e) {
			System.out.println("Error reading the file.");
		} catch (EmptyFileException e) {
			System.out.println("The file is empty.");
		} finally {
			input.close();
		}
	}
}
