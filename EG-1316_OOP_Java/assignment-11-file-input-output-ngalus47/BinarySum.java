import java.io.*;
import java.util.Scanner;

/**
* <h1>BinarySum</h1>
* Prompts the user to enter numbers and writes them to a binary file.
* Then reads the numbers back and prints their sum.
* Uses writeInt and readInt on a file named numbers.dat.
* Sentinel value -1 ends input and is not stored in the file.
* 
* @author  Nick Galus
* @version 1.0
* @since   2025-04-29
*/
public class BinarySum {

    /**
    * This is the main method that writes integers to a binary file
    * and reads them back to calculate the total sum.
    * 
    * @param args Unused.
    */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        try {
            // Writing numbers to a binary file
            DataOutputStream out = new DataOutputStream(new FileOutputStream("numbers.dat"));
            System.out.println("Enter numbers, -1 to stop:");

            while (true) {
                int number = input.nextInt();

                if (number == -1)
                    break;

                out.writeInt(number);
            }

            out.close();

            // Reading numbers from the binary file and summing them
            DataInputStream in = new DataInputStream(new FileInputStream("numbers.dat"));
            int sum = 0;

            while (in.available() > 0) {
                sum += in.readInt();
            }

            in.close();
            System.out.println("Sum: " + sum);

        } catch (IOException e) {
            System.out.println("An error occurred.");
        }

        input.close();
    }
}
