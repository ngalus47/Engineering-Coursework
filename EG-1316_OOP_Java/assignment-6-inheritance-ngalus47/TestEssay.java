package challenge1;

/**
 * <h1>TestEssay</h1>
 * Tests the Essay class by creating an Essay object and printing its details and score.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-24
 */
public class TestEssay {

    /**
     * The main method creates an Essay object and prints its information.
     *
     * @param args command-line arguments (not used).
     */
    public static void main(String[] args) {
        Essay essay = new Essay(25, 18.5, 15.5, 30);

        System.out.println(essay);
        System.out.println(essay.printScore());
        System.out.println("Letter Score:" + essay.getGrade());
    }
}
