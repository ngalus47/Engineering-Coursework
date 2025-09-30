import java.io.*;

/**
 * <h1>Encryption</h1>
 * Encrypts a file using a repeating shift pattern from a key array.
 * Writes the encrypted result to encrypted.dat.
 * Also prints the encrypted characters to the console.
 * 
 * @version 1.0
 * @since 2025-04-29
 */
public class Encryption {

    public static void main(String[] args) {
        int[] key = {3, 7, 1, 4};

        try {
            FileInputStream input = new FileInputStream("original.txt");
            FileOutputStream output = new FileOutputStream("encrypted.dat");

            int data;
            int i = 0;
            StringBuilder encryptedText = new StringBuilder(); // for displaying result

            while ((data = input.read()) != -1) {
                int shift = key[i % key.length];
                int encrypted = (data + shift) % 256;
                output.write(encrypted);
                encryptedText.append((char) encrypted);
                i++;
            }

            input.close();
            output.close();

            System.out.println("Encryption complete: " + encryptedText.toString());

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
