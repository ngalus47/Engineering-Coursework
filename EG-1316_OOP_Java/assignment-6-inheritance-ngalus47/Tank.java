/**
 * The Tank class represents a type of Vehicle that includes an armor width.
 * It extends the Vehicle class by adding a property specific to tanks.
 */
public class Tank extends Vehicle {
    double armorWidth;

    /**
     * Default constructor that initializes a Tank using the parent constructor.
     */
    public Tank() {
        super();
    }

    /**
     * Constructs a Tank with a given year, weight, and armor width.
     *
     * @param year the manufacturing year of the tank
     * @param weight the weight of the tank
     * @param armorWidth the width of the tank's armor
     */
    public Tank(int year, double weight, double armorWidth) {
        super(year, weight);
        this.armorWidth = armorWidth;
    }

    /**
     * Returns the armor width of the tank.
     *
     * @return armor width
     */
    public double getArmorWidth() {
        return armorWidth;
    }

    /**
     * Sets the armor width of the tank.
     *
     * @param armorWidth the width of the tank's armor
     */
    public void setArmorWidth(double armorWidth) {
        this.armorWidth = armorWidth;
    }

    /**
     * Returns a string representation of the tank including year, weight, and armor width.
     *
     * @return string with tank details
     */
    @Override
    public String toString() {
        return String.format("Tank: Year: %d Weight: %f Armor Width: %.2f", super.getYear(), super.getWeight(), armorWidth);
    }
}
