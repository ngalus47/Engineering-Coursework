/**
 * <h1>TestRectangle</h1>
 * This program calculates the area and perimeter of a rectangle using the Rectangle class.
 * It prompts the user to enter the rectangle's dimensions and displays the results.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
import java.util.Scanner;

public class TestRectangle {
    
    /**
     * The main method reads input from the user for the length and width of a rectangle,
     * creates a Rectangle object, and then prints out the calculated area and perimeter.
     *
     * @param args Unused.
     */
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Inform the user about the purpose of the program
        System.out.println("The program will calculate the perimeter and area of a rectangle");
        
        // Prompt the user to enter the length of the rectangle
        System.out.println("Enter the length of the rectangle");
        int length = scanner.nextInt();
        
        // Prompt the user to enter the width of the rectangle
        System.out.println("Enter the width of the rectangle");
        int width = scanner.nextInt();
        
        // Create a Rectangle object with the provided length and width
        Rectangle rec = new Rectangle(length, width);
        
        // Display the calculated area of the rectangle
        System.out.println("The area of the rectangle is " + rec.getArea());
        
        // Display the calculated perimeter of the rectangle
        System.out.println("The perimeter of the rectangle is " + rec.getPerimeter());
        
        // Close the Scanner to free system resources
        scanner.close();
    }
}
