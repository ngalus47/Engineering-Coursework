/**
* <h1>Rectangle</h1>
* Represents a rectangle defined by its length and width.
* Provides methods to calculate the area and perimeter of the rectangle.
*
* @author Nick Galus
* @version 1.0
* @since 2025-02-10
*/
public class Rectangle 
{
    // Instance variables to store the dimensions of the rectangle
    int length;
    int width;
    
    /**
    * Constructs a new Rectangle with the specified length and width.
    * @param length The length of the rectangle.
    * @param width The width of the rectangle.
    */
    public Rectangle(int length, int width) {
        this.length = length;
        this.width = width;
    }

    /**
    * Returns the length of the rectangle.
    * @return The current length.
    */
    public int getLength() {
        return length;
    }

    /**
    * Sets the length of the rectangle.
    * @param length The new length to be set.
    */
    public void setLength(int length) {
        this.length = length;
    }

    /**
    * Returns the width of the rectangle.
    * @return The current width.
    */
    public int getWidth() {
        return width;
    }

    /**
    * Sets the width of the rectangle.
    * @param width The new width to be set.
    */
    public void setWidth(int width) {
        this.width = width;
    }
    
    /**
    * Calculates and returns the area of the rectangle.
    * @return The area computed as length multiplied by width.
    */
    public float getArea() {
        return width * length;
    }
    
    /**
    * Calculates and returns the perimeter of the rectangle.
    * @return The perimeter computed as 2 times the sum of length and width.
    */
    public float getPerimeter() {
        return (width + length) * 2;
    }
}
