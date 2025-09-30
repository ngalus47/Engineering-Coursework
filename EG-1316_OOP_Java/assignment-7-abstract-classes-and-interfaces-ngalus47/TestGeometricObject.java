/**
 * <h1>TestGeometricObject</h1>
 * Tests the functionality of the Rectangle and Circle classes.
 * Compares their areas using inherited methods from GeometricObject.
 * Demonstrates polymorphism and abstract method implementation.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-25
 */
public class TestGeometricObject {

	/**
	 * Main method to create and compare Rectangle and Circle objects.
	 * Outputs the areas and comparison results to the console.
	 *
	 * @param args command line arguments (not used)
	 */
	public static void main(String[] args) {
		Rectangle rectangle = new Rectangle(6, 5);
		Circle circle = new Circle(5);

		System.out.printf("Rectangle Area: %.2f\n", rectangle.findArea());
		System.out.printf("Circle Area: %.2f\n", circle.findArea());

		System.out.println("Rectangle area is equal to circle area: " + rectangle.equals(circle.findArea()));
		System.out.println("Rectangle area is greater than circle area: " + rectangle.isGreater(circle.findArea()));
		System.out.println("Rectangle area is less than circle area: " + rectangle.isLess(circle.findArea()));
	}
}
