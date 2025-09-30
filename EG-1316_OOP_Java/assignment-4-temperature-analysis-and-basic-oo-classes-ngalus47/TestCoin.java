/**
 * <h1>TestCoin</h1>
 * This program tests the Coin class by simulating 20 coin tosses and counting the number of heads and tails.
 * It displays the initial side facing up and then the result of each toss.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class TestCoin {
    
    /**
     * The main method simulates coin tosses and counts the outcomes.
     * 
     * @param args Unused.
     */
    public static void main(String[] args) {
        int heads = 0;
        int tails = 0;

        // Create a Coin object.
        Coin coin = new Coin();

        // Display the initial side facing up.
        System.out.println("Initial side facing up: " + coin.getSideUp());

        // Toss the coin 20 times and count the outcomes.
        for (int i = 0; i < 20; i++) {
            coin.toss();
            System.out.println(coin.getSideUp());

            // Use equals() to compare String values correctly.
            if (coin.getSideUp().equals("heads")) {
                heads++;
            } else {
                tails++;
            }
        }

        // Display the results.
        System.out.println("Heads flipped: " + heads);
        System.out.println("Tails flipped: " + tails);
    }
}
