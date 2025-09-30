import java.io.*;

/**
* <h1>Decryption</h1>
* Decrypts a file encoded with a repeating shift pattern.
* Restores the original file and writes to decrypted.txt.
* 
* @version 1.0
* @since   2025-04-29
*/
public class Decryption {

    public static void main(String[] args) {
        int[] key = {3, 7, 1, 4};

        try {
            FileInputStream input = new FileInputStream("encrypted.dat");
            FileOutputStream output = new FileOutputStream("decrypted.txt");

            int data;
            int i = 0;
            StringBuilder result = new StringBuilder(); 

            while ((data = input.read()) != -1) {
                int shift = key[i % key.length];
                int decrypted = (data - shift + 256) % 256;
                output.write(decrypted);
                result.append((char) decrypted);
                i++;
            }

            input.close();
            output.close();

            System.out.println("Decryption complete: " + result.toString());

        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }
}
