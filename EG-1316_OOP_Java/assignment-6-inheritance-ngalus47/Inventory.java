import java.util.ArrayList;

/**
 * <h1>Inventory</h1>
 * Manages an inventory of products by providing methods to add, remove, print, and search for products.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class Inventory {
    // List to hold products in the inventory.
    ArrayList<Product> inventory = new ArrayList<>();

    /**
     * Adds a product to the inventory.
     *
     * @param product the product to be added.
     */
    public void addProduct(Product product) {
        inventory.add(product);
    }

    /**
     * Removes a product from the inventory based on the provided product ID.
     * This method removes all products matching the given ID.
     *
     * @param productId the ID of the product to remove.
     */
    public void removeProduct(String productId) {
        // Use removeIf with equals() for string comparison.
        inventory.removeIf(item -> item.getProductID().equals(productId));
    }

    /**
     * Prints details of all products in the inventory.
     */
    public void printAllProducts() {
        for (Product item : inventory) {
            System.out.println(item);
            System.out.println("-------------");
        }
    }

    /**
     * Searches for a product by its ID and prints its details if found.
     *
     * @param productId the ID of the product to search for.
     */
    public void findProduct(String productId) {
        for (Product item : inventory) {
            if (item.getProductID().equals(productId)) {
                System.out.println("Found: " + item.getProductName() + " (Qty: " + item.getQuantity() + ")");
                return;
            }
        }
        System.out.println("Unable to find " + productId);
    }
}
