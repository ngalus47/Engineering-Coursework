/**
* <h1>Loan Calculator</h1>
* This program allows users to input a loan amount, interest rate, and number of years.
* It calculates the monthly and total payments based on the provided loan information.
* 
* @author  Nick Galus
* @version 1.0
* @since   2025-05-06
*/

import javax.swing.*;
import java.awt.event.*;

public class LoanCalculator 
{
    /**
    * This is the main method which launches the loan calculator GUI.
    * @param args Unused.
    * @return Nothing.
    */
    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("Loan Calculator");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel amountLabel = new JLabel("Loan Amount:");
        amountLabel.setBounds(20, 20, 120, 25);
        frame.add(amountLabel);

        JTextField amountField = new JTextField();
        amountField.setBounds(150, 20, 200, 25);
        frame.add(amountField);

        JLabel interestLabel = new JLabel("Annual Interest Rate:");
        interestLabel.setBounds(20, 60, 140, 25);
        frame.add(interestLabel);

        JTextField interestField = new JTextField();
        interestField.setBounds(150, 60, 200, 25);
        frame.add(interestField);

        JLabel yearsLabel = new JLabel("Number of Years:");
        yearsLabel.setBounds(20, 100, 140, 25);
        frame.add(yearsLabel);

        JTextField yearsField = new JTextField();
        yearsField.setBounds(150, 100, 200, 25);
        frame.add(yearsField);

        JLabel monthlyLabel = new JLabel("Monthly Payment:");
        monthlyLabel.setBounds(20, 160, 140, 25);
        frame.add(monthlyLabel);

        JTextField monthlyField = new JTextField();
        monthlyField.setBounds(150, 160, 200, 25);
        monthlyField.setEditable(false);
        frame.add(monthlyField);

        JLabel totalLabel = new JLabel("Total Payment:");
        totalLabel.setBounds(20, 200, 140, 25);
        frame.add(totalLabel);

        JTextField totalField = new JTextField();
        totalField.setBounds(150, 200, 200, 25);
        totalField.setEditable(false);
        frame.add(totalField);

        JButton computeButton = new JButton("Compute");
        computeButton.setBounds(150, 240, 100, 30);
        frame.add(computeButton);

        computeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                double amount = Double.parseDouble(amountField.getText());
                double rate = Double.parseDouble(interestField.getText());
                int years = Integer.parseInt(yearsField.getText());

                Loan loan = new Loan(rate, years, amount);
                monthlyField.setText(String.format("%.2f", loan.getMonthlyPayment()));
                totalField.setText(String.format("%.2f", loan.getTotalPayment()));
            }
        });

        frame.setVisible(true);
    }
}
