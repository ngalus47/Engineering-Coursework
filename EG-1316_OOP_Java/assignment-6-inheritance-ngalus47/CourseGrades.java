/**
 * The CourseGrades class stores and manages grades for a set of four graded activities:
 * a lab, a pass/fail exam, an essay, and a final exam.
 * Each activity is stored in an array of GradedActivity objects.
 */
public class CourseGrades {
    GradedActivity[] grades = new GradedActivity[4];

    /**
     * Constructs a CourseGrades object with specified graded components.
     *
     * @param lab the lab grade
     * @param exam the pass/fail exam grade
     * @param essay the essay grade
     * @param finalExam the final exam grade
     */
    public CourseGrades(GradedActivity lab, PassFailExam exam, Essay essay, FinalExam finalExam) {
        super();
        this.grades[0] = lab;
        this.grades[1] = exam;
        this.grades[2] = essay;
        this.grades[3] = finalExam;
    }

    /**
     * Sets the lab grade.
     *
     * @param lab the lab grade
     */
    public void setLab(GradedActivity lab) {
        this.grades[0] = lab;
    }

    /**
     * Sets the pass/fail exam grade.
     *
     * @param exam the pass/fail exam grade
     */
    public void setFailExam(PassFailExam exam) {
        this.grades[1] = exam;
    }

    /**
     * Sets the essay grade.
     *
     * @param essay the essay grade
     */
    public void setEssay(Essay essay) {
        this.grades[2] = essay;
    }

    /**
     * Sets the final exam grade.
     *
     * @param finalExam the final exam grade
     */
    public void setFinalExam(FinalExam finalExam) {
        this.grades[3] = finalExam;
    }

    /**
     * Returns a formatted string containing all four grades.
     *
     * @return string representation of the lab, pass/fail exam, essay, and final exam scores
     */
    @Override
    public String toString() {
        return String.format("Lab: %.2f\n" +
                             "Pass/Fail Exam: %.2f\n" +
                             "Essay: %.2f\n" +
                             "Final Exam: %.2f\n",
                             this.grades[0].getScore(),
                             this.grades[1].getScore(),
                             this.grades[2].getScore(),
                             this.grades[3].getScore());
    }
}
