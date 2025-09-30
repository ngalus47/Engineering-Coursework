/**
 * <h1>Circle</h1>
 * A concrete class that extends GeometricObject to represent a circle.
 * Provides an implementation to compute the area of a circle.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-25
 */
public class Circle extends GeometricObject {
	double radius;

	/**
	 * Constructs a Circle with the specified radius.
	 * 
	 * @param radius the radius of the circle
	 */
	public Circle(double radius) {
		this.radius = radius;
	}

	/**
	 * Computes the area of the circle using the formula π * r².
	 * 
	 * @return the area of the circle
	 */
	@Override
	double findArea() {
		return Math.PI * Math.pow(radius, 2);
	}
}
