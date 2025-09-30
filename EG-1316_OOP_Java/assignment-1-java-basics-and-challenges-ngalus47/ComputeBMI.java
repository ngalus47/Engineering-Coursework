import javax.swing.JOptionPane;

public class ComputeBMI 
{
    public static void main(String[] args) 
    {
        String weightInput = JOptionPane.showInputDialog("Enter your weight in pounds:");
        double weightInPounds = Double.parseDouble(weightInput);

        String heightInput = JOptionPane.showInputDialog("Enter your height in inches:");
        double heightInInches = Double.parseDouble(heightInput);

        double weightInKg = weightInPounds * 0.45359237;
        double heightInMeters = heightInInches * 0.0254;

        double bmi = weightInKg / (heightInMeters * heightInMeters);

        JOptionPane.showMessageDialog(null, "Your Body Mass Index is: " + bmi);
    }
}
