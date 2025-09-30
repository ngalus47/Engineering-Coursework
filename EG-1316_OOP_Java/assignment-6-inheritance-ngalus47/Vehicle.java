/**
 * The Vehicle class serves as a base class for all types of vehicles.
 * It stores general information such as manufacturing year and weight.
 */
public class Vehicle {
    private int year;
    private double weight;

    /**
     * Default constructor that initializes a Vehicle with default values.
     */
    public Vehicle() {
    }

    /**
     * Constructs a Vehicle with the specified year and weight.
     *
     * @param year the manufacturing year of the vehicle
     * @param weight the weight of the vehicle
     */
    public Vehicle(int year, double weight) {
        super();
        this.year = year;
        this.weight = weight;
    }

    /**
     * Returns the manufacturing year of the vehicle.
     *
     * @return vehicle year
     */
    public int getYear() {
        return year;
    }

    /**
     * Sets the manufacturing year of the vehicle.
     *
     * @param year vehicle year
     */
    public void setYear(int year) {
        this.year = year;
    }

    /**
     * Returns the weight of the vehicle.
     *
     * @return vehicle weight
     */
    public double getWeight() {
        return weight;
    }

    /**
     * Sets the weight of the vehicle.
     *
     * @param weight vehicle weight
     */
    public void setWeight(double weight) {
        this.weight = weight;
    }

    /**
     * Returns a string representation of the vehicle including year and weight.
     *
     * @return string with vehicle details
     */
    @Override
    public String toString() {
        return "Vehicle [year=" + year + ", weight=" + weight + "]";
    }
}
