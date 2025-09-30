/**
 * The Automobile class represents a general automobile that extends the Vehicle class.
 * It adds license plate and make information specific to standard road vehicles.
 */
public class Automobile extends Vehicle {
    String licensePlate;
    String make;

    /**
     * Default constructor that calls the parent Vehicle constructor.
     */
    public Automobile() {
        super();
    }

    /**
     * Constructs an Automobile with the specified year, weight, license plate, and make.
     *
     * @param year the manufacturing year of the automobile
     * @param weight the weight of the automobile
     * @param licensePlate the license plate identifier
     * @param make the make or brand of the automobile
     */
    public Automobile(int year, double weight, String licensePlate, String make) {
        super(year, weight);
        this.licensePlate = licensePlate;
        this.make = make;
    }

    /**
     * Returns the license plate of the automobile.
     *
     * @return license plate string
     */
    public String getLicensePlate() {
        return licensePlate;
    }

    /**
     * Sets the license plate of the automobile.
     *
     * @param licensePlate the license plate string
     */
    public void setLicensePlate(String licensePlate) {
        this.licensePlate = licensePlate;
    }

    /**
     * Returns the make of the automobile.
     *
     * @return make or brand
     */
    public String getMake() {
        return make;
    }

    /**
     * Sets the make of the automobile.
     *
     * @param make the make or brand
     */
    public void setMake(String make) {
        this.make = make;
    }

    /**
     * Returns a string representation of the automobile including year, weight, license plate, and make.
     *
     * @return string with automobile details
     */
    @Override
    public String toString() {
        return String.format("%s: Year: %s weight: %.2f Liscense Plate: %s Make: %s",
                             make, super.getYear(), super.getWeight(), licensePlate, make);
    }
}
