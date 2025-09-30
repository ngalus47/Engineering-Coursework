/**
* <h1>Scoreboard</h1>
* Displays a scoreboard with Red and Blue teams. Buttons increase scores
* and reset button sets both scores to zero.
* 
* @version 1.1
* @since   2025-05-06
*/

import javax.swing.*;
import java.awt.*;

public class Scoreboard 
{
    /**
    * This is the main method which launches the scoreboard GUI.
    * @param args Unused.
    * @return Nothing.
    */
    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("JButton Scoreboard");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new BorderLayout(10, 10));

        JPanel centerPanel = new JPanel(new GridLayout(3, 2, 10, 5));

        JLabel redLabel = new JLabel("Red Team", SwingConstants.CENTER);
        redLabel.setForeground(Color.RED);
        JLabel blueLabel = new JLabel("Blue Team", SwingConstants.CENTER);

        JLabel redScoreLabel = new JLabel("0", SwingConstants.CENTER);
        JLabel blueScoreLabel = new JLabel("0", SwingConstants.CENTER);

        JButton redButton = new JButton("Red Score!");
        JButton blueButton = new JButton("Blue Score!");
        JButton resetButton = new JButton("Reset Score");

        centerPanel.add(redLabel);
        centerPanel.add(blueLabel);
        centerPanel.add(redScoreLabel);
        centerPanel.add(blueScoreLabel);
        centerPanel.add(redButton);
        centerPanel.add(blueButton);

        JPanel wrapperPanel = new JPanel(new BorderLayout());
        wrapperPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 0, 10));
        wrapperPanel.add(centerPanel, BorderLayout.CENTER);

        JPanel resetPanel = new JPanel(new BorderLayout());
        resetPanel.setBorder(BorderFactory.createEmptyBorder(0, 10, 10, 10));
        resetPanel.add(resetButton, BorderLayout.CENTER);

        frame.add(wrapperPanel, BorderLayout.CENTER);
        frame.add(resetPanel, BorderLayout.SOUTH);

        final int[] redScore = {0};
        final int[] blueScore = {0};

        redButton.addActionListener(e -> {
            redScore[0]++;
            redScoreLabel.setText(String.valueOf(redScore[0]));
        });

        blueButton.addActionListener(e -> {
            blueScore[0]++;
            blueScoreLabel.setText(String.valueOf(blueScore[0]));
        });

        resetButton.addActionListener(e -> {
            redScore[0] = 0;
            blueScore[0] = 0;
            redScoreLabel.setText("0");
            blueScoreLabel.setText("0");
        });

        frame.setVisible(true);
    }
}
