/**
* <h1>Temperature Converter</h1>
* Converts temperatures between Fahrenheit and Celsius using Swing UI.
*
* @version 1.1
* @since   2025-05-06
*/

import javax.swing.*;
import java.awt.*;

public class TempConverter
{
    /**
    * This is the main method which launches the temperature converter GUI.
    * @param args Unused.
    * @return Nothing.
    */
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Temperature Converter");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel(new GridLayout(2, 3, 10, 10));
        inputPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15)); // Top, Left, Bottom, Right

        JLabel fahrenheitLabel = new JLabel("Degrees Fahrenheit");
        JTextField fahrenheitField = new JTextField();
        JButton toCelsiusButton = new JButton("F -> C");

        JLabel celsiusLabel = new JLabel("Degrees Celsius");
        JTextField celsiusField = new JTextField();
        JButton toFahrenheitButton = new JButton("C -> F");

        inputPanel.add(fahrenheitLabel);
        inputPanel.add(fahrenheitField);
        inputPanel.add(toCelsiusButton);
        inputPanel.add(celsiusLabel);
        inputPanel.add(celsiusField);
        inputPanel.add(toFahrenheitButton);

        frame.add(inputPanel, BorderLayout.CENTER);

        toCelsiusButton.addActionListener(e -> {
            try {
                double f = Double.parseDouble(fahrenheitField.getText());
                double c = (f - 32) * 5 / 9;
                celsiusField.setText(String.format("%.2f", c));
            } catch (NumberFormatException ex) {
                celsiusField.setText("Invalid");
            }
        });

        toFahrenheitButton.addActionListener(e -> {
            try {
                double c = Double.parseDouble(celsiusField.getText());
                double f = (c * 9 / 5) + 32;
                fahrenheitField.setText(String.format("%.2f", f));
            } catch (NumberFormatException ex) {
                fahrenheitField.setText("Invalid");
            }
        });

        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
