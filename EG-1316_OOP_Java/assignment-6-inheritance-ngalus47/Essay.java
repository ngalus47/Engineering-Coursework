package challenge1;

/**
 * <h1>Essay</h1>
 * Represents an essay that is graded based on grammar, spelling, correct length, and content.
 * Inherits from GradedActivity and calculates the total score accordingly.

 * @author Nick Galus
 * @version 1.0
 * @since 2025-03-24
 */
public class Essay extends GradedActivity {
    private double grammar;
    private double spelling;
    private double correctLen;
    private double content;

    /**
     * Constructs an Essay object with given scores.
     *
     * @param grammar grammar score (out of 30)
     * @param spelling spelling score (out of 20)
     * @param correctLen correct length score (out of 20)
     * @param content content score (out of 30)
     */
    public Essay(double grammar, double spelling, double correctLen, double content) {
        setScore(grammar + spelling + correctLen + content);
        this.grammar = grammar;
        this.spelling = spelling;
        this.correctLen = correctLen;
        this.content = content;
    }

    public double getGrammar() {
        return grammar;
    }

    public void setGrammar(double grammar) {
        this.grammar = grammar;
    }

    public double getSpelling() {
        return spelling;
    }

    public void setSpelling(double spelling) {
        this.spelling = spelling;
    }

    public double getCorrectLen() {
        return correctLen;
    }

    public void setCorrectLen(double correctLen) {
        this.correctLen = correctLen;
    }

    public double getContent() {
        return content;
    }

    public void setContent(double content) {
        this.content = content;
    }

    /**
     * Updates the total score based on individual component scores.
     */
    public void updateScore() {
        setScore(grammar + spelling + correctLen + content);
    }

    /**
     * Returns a formatted string showing the breakdown of the essay grade.
     *
     * @return breakdown of grammar, spelling, correct length, and content scores
     */
    @Override
    public String toString() {
        return String.format("Essay Grade Breakdown:\n"
                + "\tGrammar: %.2f/30\n"
                + "\tSpelling: %.2f/20\n"
                + "\tCorrect Length: %.2f/20\n"
                + "\tContent: %.2f/30\n", grammar, spelling, correctLen, content);
    }
}
