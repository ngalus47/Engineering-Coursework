/**
 * <h1>Fan</h1>
 * This class represents a fan with attributes such as speed, power status, radius, and color.
 * It provides constructors for creating a fan and a method to obtain a string representation of the fan's state.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class Fan {
    // The speed of the fan.
    int speed;
    // The power status of the fan (true for on, false for off).
    boolean fanStatus;
    // The radius of the fan.
    double radius;
    // The color of the fan, default is "blue".
    String color = "blue";

    /**
     * Default constructor that creates a fan with default values.
     */
    public Fan() {
    }

    /**
	 * Constructs a fan with the specified speed, status, radius, and color.
	 *
	 * @param speed     the speed of the fan.
	 * @param fanStatus the power status of the fan (true for on, false for off).
	 * @param radius    the radius of the fan.
	 * @param color     the color of the fan.
	 */
    public Fan(int speed, boolean fanStatus, double radius, String color) {
        this.speed = speed;
        this.fanStatus = fanStatus;
        this.radius = radius;
        this.color = color;
    }

    /**
     * Returns a string representation of the fan's current state, including its speed, power status, radius, and color.
     *
     * @return a formatted string describing the fan.
     */
    @Override
    public String toString() {
        return "Fan speed: " + speed + "\nThe fan is " + (fanStatus ? "on" : "off") +
               "\nThe fan radius is " + radius + "\nThe color of the fan is: " + color;
    }
}
