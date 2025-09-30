/**
 * The PassFailExam class represents a pass/fail exam that extends the GradedActivity class.
 * It determines whether the student passed based on the number of correct answers and the passing score.
 */
public class PassFailExam extends GradedActivity {
    int numberOfQuestions;
    int numberCorrect;
    int passingScore;

    /**
     * Default constructor that calls the superclass constructor.
     */
    public PassFailExam() {
        super();
    }

    /**
     * Constructs a PassFailExam with the given number of questions, correct answers, and passing score.
     * Calculates and sets the score as a percentage.
     *
     * @param numberOfQuestions total number of questions on the exam
     * @param numberCorrect number of correct answers
     * @param passingScore minimum score required to pass
     */
    public PassFailExam(int numberOfQuestions, int numberCorrect, int passingScore) {
        setScore(((double) numberCorrect / numberOfQuestions) * 100.0);
        this.passingScore = passingScore;
    }

    /**
     * Returns the minimum score required to pass the exam.
     *
     * @return passing score
     */
    public int getPassingScore() {
        return passingScore;
    }

    /**
     * Sets the passing score for the exam.
     *
     * @param passingScore score required to pass
     */
    public void setPassingScore(int passingScore) {
        this.passingScore = passingScore;
    }

    /**
     * Returns the total number of questions on the exam.
     *
     * @return number of questions
     */
    public int getNumberOfQuestions() {
        return numberOfQuestions;
    }

    /**
     * Sets the total number of questions on the exam.
     *
     * @param numberOfQuestions total number of questions
     */
    public void setNumberOfQuestions(int numberOfQuestions) {
        this.numberOfQuestions = numberOfQuestions;
    }

    /**
     * Returns the number of correctly answered questions.
     *
     * @return number of correct answers
     */
    public int getNumberCorrect() {
        return numberCorrect;
    }

    /**
     * Sets the number of correct answers.
     *
     * @param numberCorrect number of correct answers
     */
    public void setNumberCorrect(int numberCorrect) {
        this.numberCorrect = numberCorrect;
    }

    /**
     * Returns whether the exam is a pass or fail based on the score and passing score.
     *
     * @return "PASS" if score is equal to or greater than passing score, otherwise "FAIL"
     */
    public String passFail() {
        if (getScore() >= passingScore) {
            return "PASS";
        }
        return "FAIL";
    }
}
