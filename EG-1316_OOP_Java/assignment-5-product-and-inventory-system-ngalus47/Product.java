/**
 * <h1>Product</h1>
 * The Product class represents a product with a unique identifier, name, price, and quantity.
 * It provides methods to calculate the total value of the product and includes standard getter
 * and setter methods.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class Product {
    // Unique identifier for the product.
    String productID;
    // Name of the product.
    String productName;
    // Price of the product.
    double price;
    // Quantity available.
    int quantity;

    /**
     * Default constructor for Product.
     */
    public Product() {
    }

    /**
     * Constructs a Product with the specified product ID, product name, price, and quantity.
     *
     * @param productID   the unique identifier for the product.
     * @param productName the name of the product.
     * @param price       the price of the product.
     * @param quantity    the quantity available.
     */
    public Product(String productID, String productName, double price, int quantity) {
        this.productID = productID;
        this.productName = productName;
        this.price = price;
        this.quantity = quantity;
    }

    /**
     * Returns the product ID.
     *
     * @return the productID.
     */
    public String getProductID() {
        return productID;
    }

    /**
     * Sets the product ID.
     *
     * @param productID the product ID to set.
     */
    public void setProductID(String productID) {
        this.productID = productID;
    }

    /**
     * Returns the product name.
     *
     * @return the productName.
     */
    public String getProductName() {
        return productName;
    }

    /**
     * Sets the product name.
     *
     * @param productName the product name to set.
     */
    public void setProductName(String productName) {
        this.productName = productName;
    }

    /**
     * Returns the price of the product.
     *
     * @return the price.
     */
    public double getPrice() {
        return price;
    }

    /**
     * Sets the price of the product.
     *
     * @param price the price to set.
     */
    public void setPrice(double price) {
        this.price = price;
    }

    /**
     * Returns the quantity of the product.
     *
     * @return the quantity.
     */
    public int getQuantity() {
        return quantity;
    }

    /**
     * Sets the quantity of the product.
     *
     * @param quantity the quantity to set.
     */
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    /**
     * Calculates the total value of the product by multiplying the price by the quantity.
     *
     * @return the total value.
     */
    public double calculateTotalValue() {
        return price * quantity;
    }

    /**
     * Returns a string representation of the product, including its ID, name, price, quantity, and total value.
     *
     * @return a formatted string with product details.
     */
    @Override
    public String toString() {
        return "Product ID: " + productID + "\nProduct Name: " + productName + "\nPrice: $" + price +
                "\nQuantity: " + quantity + "\nTotal Value: $" + calculateTotalValue();
    }
}
