import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
* <h1>FileSum</h1>
* Prompts the user to enter numbers and writes them to a file,
* then reads the numbers back and prints their sum.
* Numbers are written to the file separated by spaces.
* Sentinel value -1 ends input and is not written to the file.
* 
* @author  Nick Galus
* @version 1.0
* @since   2025-04-29
*/
public class FileSum {

    /**
    * This is the main method that drives the program.
    * It collects user input, writes it to a file, then reads and sums the data.
    * 
    * @param args Unused.
    */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        try {
            // Writing numbers to the file
            FileWriter writer = new FileWriter("data.txt");
            System.out.println("Enter numbers, -1 to stop:");

            while (true) {
                float number = input.nextFloat();
                if (number == -1)
                    break;
                writer.write(number + " ");
            }

            writer.close();

            // Reading numbers from the file and calculating the sum
            Scanner reader = new Scanner(new File("data.txt"));
            float sum = 0;

            while (reader.hasNextFloat()) {
                sum += reader.nextFloat();
            }

            System.out.printf("Sum: %.2f%n", sum);

            reader.close();
        } catch (Exception e) {
            System.out.println("An error occurred.");
        }

        input.close();
    }
}
