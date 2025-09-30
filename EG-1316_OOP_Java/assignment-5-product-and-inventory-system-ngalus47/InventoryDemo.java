/**
 * <h1>InventoryDemo</h1>
 * Demonstrates the functionality of the Inventory system by adding, finding, and removing products.
 * This class creates an Inventory instance, adds several Product objects, and displays the inventory status.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class InventoryDemo {
    
    /**
     * The main method executes the demonstration of the inventory system.
     * It performs operations like adding products, printing the inventory, finding a specific product,
     * removing a product, and then printing the updated inventory.
     *
     * @param args Unused.
     */
    public static void main(String[] args) {
        // Create an Inventory instance.
        Inventory inventory = new Inventory();

        // Add products to the inventory.
        System.out.println("Adding products to inventory...");
        inventory.addProduct(new Product("P001", "Laptop", 999.99, 10));
        inventory.addProduct(new Product("P002", "Hedphones", 59.99, 20));
        inventory.addProduct(new Product("P003", "Mouse", 24.99, 50));

        // Print all products currently in the inventory.
        System.out.println("\nAll Products in Inventory: \n-------------");
        inventory.printAllProducts();

        // Find and display details of the product with ID P002.
        System.out.println("\nFinding product with ID P002...");
        inventory.findProduct("P002");

        // Remove the product with ID P001 from the inventory.
        System.out.println("\nRemoving product with ID P001...");
        inventory.removeProduct("P001");
        System.out.println("Product removed successfully!");

        // Print the updated inventory after removal.
        System.out.println("\nUpdated Inventory: \n-------------");
        inventory.printAllProducts();
    }
}
