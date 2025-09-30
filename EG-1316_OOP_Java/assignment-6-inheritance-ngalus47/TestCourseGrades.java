/**
 * The TestCourseGrades class demonstrates the use of the CourseGrades class
 * along with several types of graded activities including lab work, 
 * pass/fail exams, essays, and final exams.
 *
 * It creates instances of each grade type, updates their scores, 
 * sets them in a CourseGrades object, and prints the final report.
 */
public class TestCourseGrades {

    /**
     * The main method creates and modifies various GradedActivity objects,
     * updates their scores, stores them in a CourseGrades object,
     * and prints the final grading report.
     *
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {
        GradedActivity lab = new GradedActivity(80);
        PassFailExam passFailExam = new PassFailExam(10, 9, 70);
        Essay essay = new Essay(25, 18.5, 15.5, 30);
        FinalExam finalExam = new FinalExam(50, 45);

        CourseGrades grades = new CourseGrades(lab, passFailExam, essay, finalExam);

        lab.setScore(85);
        grades.setLab(lab);

        passFailExam.setScore(70);
        grades.setFailExam(passFailExam);

        essay.setScore(essay.getScore() + 5);
        grades.setEssay(essay);

        finalExam.setScore(95);
        grades.setFinalExam(finalExam);

        System.out.println(grades);
    }
}
