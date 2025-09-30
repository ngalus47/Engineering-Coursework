import javax.swing.JOptionPane;

public class MilesPerGallon
{
    public static void main(String[] args) 
    {
        String milesDrivenInput = JOptionPane.showInputDialog("Enter the miles driven:");
        double milesDriven = Double.parseDouble(milesDrivenInput);

        String gallonsUsedInput = JOptionPane.showInputDialog("Enter the gallons of fuel used:");
        double gallonsUsed = Double.parseDouble(gallonsUsedInput);

        double mpg = milesDriven / gallonsUsed;

        JOptionPane.showMessageDialog(null, "The miles-per-gallon is: " + mpg);
    }
}
