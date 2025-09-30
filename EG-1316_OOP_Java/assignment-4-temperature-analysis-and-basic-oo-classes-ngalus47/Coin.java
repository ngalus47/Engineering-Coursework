/**
 * <h1>Coin</h1>
 * Simulates a coin with two possible outcomes: heads or tails.
 * Provides methods to toss the coin and retrieve the current side facing up.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-02-10
 */
public class Coin {
    // Represents the current side facing up ("heads" or "tails")
    String sideUp;

    /**
     * Default constructor for the Coin class.
     * Initializes the coin by performing an initial toss.
     */
    public Coin() {
        toss();
    }

    /**
     * Returns the current side facing up.
     * 
     * @return a String representing the side currently facing up.
     */
    public String getSideUp() {
        return sideUp;
    }

    /**
     * Simulates tossing the coin.
     * Randomly assigns "heads" or "tails" to the sideUp variable.
     */
    public void toss() {
        int rand = (int) (Math.random() * 2);
        sideUp = rand == 0 ? "heads" : "tails";
    }
}
