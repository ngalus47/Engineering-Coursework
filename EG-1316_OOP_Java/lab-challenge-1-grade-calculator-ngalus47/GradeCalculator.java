public class GradeCalculator {
    public static void main(String[] args) {
        char mInitial = 'A';
        char letterGrade;
        int daysAttended = 17, totalDays = 20;
        double participation = 95.5, avg = 0;
        int[] quizScores = {95, 88, 92};
        String name = "John Smith";

        try {
            if (name == null || name.trim().isEmpty()) throw new IllegalArgumentException("Name cannot be empty.");
            if (daysAttended < 0 || totalDays <= 0) throw new IllegalArgumentException("Attendance days cannot be negative or zero.");
            for (int score : quizScores) {
                if (score < 0 || score > 100) throw new IllegalArgumentException("Quiz scores must be between 0 and 100.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        name = name.substring(0, name.indexOf(' ')) + " " + mInitial + "." + name.substring(name.indexOf(' '));
        double attendance = ((double) daysAttended / totalDays) * 100;

        for (int score : quizScores) avg += score;
        avg /= quizScores.length;

        if (avg >= 90) letterGrade = 'A';
        else if (avg >= 80) letterGrade = 'B';
        else if (avg >= 70) letterGrade = 'C';
        else if (avg >= 60) letterGrade = 'D';
        else letterGrade = 'F';

        double minScoreForPassingFinal = ((70 - avg) * 2);
        if (minScoreForPassingFinal < 0) minScoreForPassingFinal = 0;
        if (minScoreForPassingFinal > 100) minScoreForPassingFinal = 100;

        double maxPossibleFinalGrade = (avg + 100) / 2;
        double pointsToNextGrade = (Math.min(100, (letterGrade == 'A' ? 0 : letterGrade == 'B' ? 90 : letterGrade == 'C' ? 80 : letterGrade == 'D' ? 70 : 60)) - avg);
        String status = (avg >= 70 && attendance >= 75) ? "PASSED" : "FAILED";

        System.out.println("Student Grade Summary\n----------------");
        System.out.println("Name: " + name);
        System.out.print("Quiz Scores: ");
        for (int i = 0; i < quizScores.length; i++) {
            System.out.print(quizScores[i] + (i < quizScores.length - 1 ? ", " : "\n"));
        }
        System.out.println("Participation: " + String.format("%.1f", participation) + "%");
        System.out.println("Attendance: " + String.format("%.0f", attendance) + "% (" + daysAttended + "/" + totalDays + ")");
        System.out.println("Weighted Average: " + String.format("%.2f", avg));
        System.out.println("Letter Grade: " + letterGrade);
        System.out.println("Status: " + status);

        System.out.println("\nAdditional Information\n--------------------");
        System.out.println("Points to next grade: " + (pointsToNextGrade > 0 ? "N/A (Highest grade achieved)" : String.format("%.2f", pointsToNextGrade)));
        System.out.println("Minimum final exam score needed: " + String.format("%.0f", minScoreForPassingFinal));
        System.out.println("Maximum possible final grade: " + String.format("%.2f", maxPossibleFinalGrade));
    }
}
