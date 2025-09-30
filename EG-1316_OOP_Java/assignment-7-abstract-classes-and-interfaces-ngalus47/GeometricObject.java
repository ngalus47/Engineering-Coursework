/**
 * <h1>GeometricObject</h1>
 * Represents an abstract geometric object and provides comparison methods based on area.
 * Subclasses must implement the area calculation logic.
 * Implements Comparable for area-based comparisons.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-25
 */
public abstract class GeometricObject implements Comparable {
    // Area of the geometric object
    double area;

    /**
     * Abstract method that must be implemented by subclasses to calculate the area.
     *
     * @return the area of the geometric object
     */
    abstract double findArea();

    /**
     * Checks if this object's area is equal to the specified area.
     *
     * @param area the area to compare with
     * @return true if areas are equal, false otherwise
     */
    @Override
    public boolean equals(double area) {
        return (this.area == area) ? true : false;
    }

    /**
     * Determines if this object's area is greater than or equal to the specified area.
     *
     * @param area the area to compare with
     * @return true if this area is greater than or equal, false otherwise
     */
    @Override
    public boolean isGreater(double area) {
        return (this.area >= area) ? true : false;
    }

    /**
     * Determines if this object's area is less than or equal to the specified area.
     *
     * @param area the area to compare with
     * @return true if this area is less than or equal, false otherwise
     */
    @Override
    public boolean isLess(double area) {
        return (this.area <= area) ? true : false;
    }
}
