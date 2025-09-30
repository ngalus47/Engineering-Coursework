import javax.swing.JOptionPane;

public class Octagon
{
    public static void main(String[] args) 
    {
        String sideInput = JOptionPane.showInputDialog("Enter the side length of the octagon:");
        double side = Double.parseDouble(sideInput);

        double perimeter = 8 * side;
        double area = 2 * (1 + Math.sqrt(2)) * side * side;

        String message = "The octagon's perimeter is: " + perimeter +
                         "\nThe octagon's area is: " + area;

        JOptionPane.showMessageDialog(null, message);
    }
}
