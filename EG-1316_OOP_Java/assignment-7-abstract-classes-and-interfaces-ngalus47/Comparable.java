/**
 * <h1>Comparable</h1>
 * A custom interface to compare geometric objects based on area.
 * Provides method signatures for equality, greater-than, and less-than checks.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-25
 */
public interface Comparable {

	/**
	 * Checks if the given area is equal to this object's area.
	 *
	 * @param area the area to compare with
	 * @return true if areas are equal, false otherwise
	 */
	public boolean equals(double area);

	/**
	 * Checks if this object's area is greater than or equal to the given area.
	 *
	 * @param area the area to compare with
	 * @return true if this area is greater than or equal, false otherwise
	 */
	public boolean isGreater(double area);

	/**
	 * Checks if this object's area is less than or equal to the given area.
	 *
	 * @param area the area to compare with
	 * @return true if this area is less than or equal, false otherwise
	 */
	public boolean isLess(double area);
}
