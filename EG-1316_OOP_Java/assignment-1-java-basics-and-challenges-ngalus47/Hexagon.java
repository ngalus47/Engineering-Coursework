import javax.swing.JOptionPane;

public class Hexagon 
{
    public static void main(String[] args) 
    {
        String sideInput = JOptionPane.showInputDialog("Enter the side length of the hexagon:");
        double side = Double.parseDouble(sideInput);

        double perimeter = 6 * side;
        double area = (3 * Math.sqrt(3) / 2) * side * side;

        String message = "The hexagon's perimeter is: " + perimeter +
                         "\nThe hexagon's area is: " + area;

        JOptionPane.showMessageDialog(null, message);
    }
}
