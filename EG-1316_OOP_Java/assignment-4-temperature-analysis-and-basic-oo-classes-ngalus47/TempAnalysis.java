/**
 * <h1>Temperature Analysis</h1>
 * Converts temperatures between Celsius and Fahrenheit and determines if the given
 * temperature is considered freezing.
 *
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
import java.util.Scanner;

public class TempAnalysis {

    /**
     * Converts a temperature from Celsius to Fahrenheit.
     * Formula: (Celsius × 9/5) + 32 = Fahrenheit.
     *
     * @param celsius the temperature in Celsius.
     * @return the converted temperature in Fahrenheit.
     */
    static double celsiusToFahrenheit(double celsius) {
        return celsius * (9.0 / 5) + 32;
    }

    /**
     * Converts a temperature from Fahrenheit to Celsius.
     * Formula: (Fahrenheit - 32) × 5/9 = Celsius.
     *
     * @param fahrenheit the temperature in Fahrenheit.
     * @return the converted temperature in Celsius.
     */
    static double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * (5.0 / 9);
    }

    /**
     * Determines if the given temperature in Celsius is freezing.
     *
     * @param celsius the temperature in Celsius.
     * @return true if the temperature is less than or equal to 0°C, otherwise false.
     */
    static boolean isFreezing(double celsius) {
        return celsius <= 0;
    }

    /**
     * Determines if the temperature is freezing based on the provided scale.
     *
     * @param degrees the temperature value.
     * @param scale   the scale of the temperature ("C" for Celsius or "F" for Fahrenheit).
     * @return true if the temperature is considered freezing (<= 32°F or <= 0°C), otherwise false.
     */
    static boolean isFreezing(double degrees, String scale) {
        if (scale.equalsIgnoreCase("F") && degrees <= 32) {
            return true;
        } else if (scale.equalsIgnoreCase("C") && degrees <= 0) {
            return true;
        }
        return false;
    }

    /**
     * Main method that prompts the user for a temperature with scale, converts it to the
     * opposite scale, and determines if it is freezing.
     *
     * @param args Unused.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the temperature with scale (EX: 212F or 100C): ");
        String input = scanner.nextLine().trim();
        int index = -1;
        
        // Find the index where the scale character starts (non-digit, non-decimal, non-negative sign)
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (!Character.isDigit(c) && c != '.' && c != '-') {
                index = i;
                break;
            }
        }
        
        if (index == -1) {
            System.out.println("Invalid input. No scale provided.");
            scanner.close();
            return;
        }
        
        // Separate the numeric part from the scale part
        String numberPart = input.substring(0, index);
        String scale = input.substring(index).trim();
        double temp = Double.parseDouble(numberPart);
        
        // Convert temperature to the opposite scale and display
        if (scale.equalsIgnoreCase("F")) {
            System.out.println("Temperature in Celsius: " + fahrenheitToCelsius(temp) + "°C");
        } else if (scale.equalsIgnoreCase("C")) {
            System.out.println("Temperature in Fahrenheit: " + celsiusToFahrenheit(temp) + "°F");
        } else {
            System.out.println("Invalid scale. Please use C or F.");
            scanner.close();
            return;
        }
        
        // Determine if the original temperature is considered freezing
        String freezing;
        if (isFreezing(temp, scale)) {
            freezing = "It is freezing outside";
        } else {
            freezing = "It is not freezing outside";
        }
        System.out.println(freezing);
        scanner.close();
    }
}
