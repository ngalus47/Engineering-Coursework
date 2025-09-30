/**
 * The Car class represents a type of Automobile with a specified maximum number of passengers.
 * It extends the Automobile class by adding passenger capacity.
 */
public class Car extends Automobile {
    int maxPassengers;

    /**
     * Default constructor that calls the parent constructor.
     */
    public Car() {
        super();
    }

    /**
     * Constructs a Car with the specified year, weight, license plate, make, and passenger capacity.
     *
     * @param year the manufacturing year of the car
     * @param weight the weight of the car
     * @param licensePlate the license plate of the car
     * @param make the make or brand of the car
     * @param maxPassengers the maximum number of passengers the car can carry
     */
    public Car(int year, double weight, String licensePlate, String make, int maxPassengers) {
        super(year, weight, licensePlate, make);
        this.maxPassengers = maxPassengers;
    }

    /**
     * Returns the maximum number of passengers the car can carry.
     *
     * @return maximum passenger capacity
     */
    public int getMaxPassengers() {
        return maxPassengers;
    }

    /**
     * Sets the maximum number of passengers the car can carry.
     *
     * @param maxPassengers passenger capacity
     */
    public void setMaxPassengers(int maxPassengers) {
        this.maxPassengers = maxPassengers;
    }

    /**
     * Returns a string representation of the car including base automobile info and max passengers.
     *
     * @return string with car details
     */
    @Override
    public String toString() {
        return String.format("%s Max Passengers: %d", super.toString(), maxPassengers);
    }    
}
