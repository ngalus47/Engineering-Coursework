package challenge1;

/**
 * <h1>GradedActivity</h1>
 * Represents a graded activity with a numeric score and a corresponding letter grade.
 * Provides methods to set and get the score, determine the letter grade, and print the score.

 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-24
 */
public class GradedActivity {
    private double score;

    /**
     * Default constructor.
     */
    public GradedActivity() {
        super();
    }

    /**
     * Constructor that sets the initial score.
     *
     * @param score the score to assign.
     */
    public GradedActivity(double score) {
        super();
        this.score = score;
    }

    /**
     * Sets the numeric score.
     *
     * @param s the score to set.
     */
    public void setScore(double s) {
        score = s;
    }

    /**
     * Returns the numeric score.
     *
     * @return the current score.
     */
    public double getScore() {
        return score;
    }

    /**
     * Returns the letter grade based on the numeric score.
     *
     * @return the letter grade (A–F).
     */
    public char getGrade() {
        char letterGrade;

        if (score >= 90) {
            letterGrade = 'A';
        } else if (score >= 80) {
            letterGrade = 'B';
        } else if (score >= 70) {
            letterGrade = 'C';
        } else if (score >= 60) {
            letterGrade = 'D';
        } else {
            letterGrade = 'F';
        }

        return letterGrade;
    }

    /**
     * Returns a formatted string of the score.
     *
     * @return a string showing the score out of 100.
     */
    public String printScore() {
        return String.format("Activity Score: %.2f/100", score);
    }
}
