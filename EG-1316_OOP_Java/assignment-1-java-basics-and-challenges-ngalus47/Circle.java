import javax.swing.JOptionPane;

public class Circle 
{
    public static void main(String[] args) 
    {
        String radiusInput = JOptionPane.showInputDialog("Enter the radius of the circle:");
        double radius = Double.parseDouble(radiusInput);

        double diameter = 2 * radius;
        double circumference = 2 * Math.PI * radius;
        double area = Math.PI * radius * radius;

        String message = "The circle's radius is: " + radius +
                         "\nThe circle's diameter is: " + diameter +
                         "\nThe circle's circumference is: " + circumference +
                         "\nThe circle's area is: " + area;

        JOptionPane.showMessageDialog(null, message);
    }
}
