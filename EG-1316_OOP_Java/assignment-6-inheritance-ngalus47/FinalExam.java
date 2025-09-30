/**
 * The FinalExam class represents a final exam and extends the GradedActivity class.
 * It calculates a numeric score based on the number of correct answers and total questions.
 */
public class FinalExam extends GradedActivity {
    int numberOfQuestions;
    int numberCorrect;

    /**
     * Default constructor that initializes a FinalExam using the parent constructor.
     */
    public FinalExam() {
        super();
    }

    /**
     * Constructs a FinalExam object with a given number of questions and correct answers.
     * Calculates and sets the score as a percentage.
     *
     * @param numberOfQuestions total number of questions on the exam
     * @param numberCorrect number of questions answered correctly
     */
    public FinalExam(int numberOfQuestions, int numberCorrect) {
        setScore(((double) numberCorrect / numberOfQuestions) * 100.0);
    }

    /**
     * Gets the number of questions on the exam.
     *
     * @return number of questions
     */
    public int getNumberOfQuestions() {
        return numberOfQuestions;
    }

    /**
     * Sets the number of questions on the exam.
     *
     * @param numberOfQuestions total number of questions
     */
    public void setNumberOfQuestions(int numberOfQuestions) {
        this.numberOfQuestions = numberOfQuestions;
    }

    /**
     * Gets the number of questions answered correctly.
     *
     * @return number of correct answers
     */
    public int getNumberCorrect() {
        return numberCorrect;
    }

    /**
     * Sets the number of correct answers on the exam.
     *
     * @param numberCorrect number of correct answers
     */
    public void setNumberCorrect(int numberCorrect) {
        this.numberCorrect = numberCorrect;
    }
}
