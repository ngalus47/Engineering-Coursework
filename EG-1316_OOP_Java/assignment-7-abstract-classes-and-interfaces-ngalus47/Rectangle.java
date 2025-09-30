/**
 * <h1>Rectangle</h1>
 * A concrete class that extends GeometricObject to represent a rectangle.
 * Provides an implementation to compute the area of a rectangle.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-25
 */
public class Rectangle extends GeometricObject {
	double len;
	double width;

	/**
	 * Constructs a Rectangle with specified length and width.
	 * 
	 * @param len the length of the rectangle
	 * @param width the width of the rectangle
	 */
	public Rectangle(double len, double width) {
		this.len = len;
		this.width = width;
	}

	/**
	 * Computes the area of the rectangle.
	 * 
	 * @return the area as length multiplied by width
	 */
	@Override
	public double findArea() {
		return len * width;
	}
}
