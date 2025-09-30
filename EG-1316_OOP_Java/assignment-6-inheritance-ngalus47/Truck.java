/**
 * The Truck class represents a type of Automobile with towing capabilities.
 * It extends the Automobile class by adding a tow capacity attribute.
 */
public class Truck extends Automobile {
    double towCapacity;

    /**
     * Default constructor that calls the parent constructor.
     */
    public Truck() {
        super();
    }

    /**
     * Constructs a Truck with the specified year, weight, license plate, make, and tow capacity.
     *
     * @param year the manufacturing year of the truck
     * @param weight the weight of the truck
     * @param licensePlate the license plate of the truck
     * @param make the make or brand of the truck
     * @param towCapacity the maximum tow capacity of the truck
     */
    public Truck(int year, double weight, String licensePlate, String make, double towCapacity) {
        super(year, weight, licensePlate, make);
        this.towCapacity = towCapacity;
    }

    /**
     * Returns the tow capacity of the truck.
     *
     * @return tow capacity
     */
    public double getTowCapacity() {
        return towCapacity;
    }

    /**
     * Sets the tow capacity of the truck.
     *
     * @param towCapacity the maximum towing capacity
     */
    public void setTowCapacity(double towCapacity) {
        this.towCapacity = towCapacity;
    }

    /**
     * Returns a string representation of the truck including base automobile info and tow capacity.
     *
     * @return string with truck details
     */
    @Override
    public String toString() {
        return String.format("%s Tow Capacity: %.1f", super.toString(), towCapacity);
    }
}
