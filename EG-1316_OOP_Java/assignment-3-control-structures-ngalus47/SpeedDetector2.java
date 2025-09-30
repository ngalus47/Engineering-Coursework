/**
* <h1>Gives speeding tickets</h1>
* Prints out a speeding ticket
*
* @author  Nick Galus
* @version 2.0
* @since   2025-02-09
*/

import javax.swing.JOptionPane;

public class SpeedDetector2 
{
	/**
	* This is the main method which prints out the speeding tickets
	* @param args Unused.
	* @return Nothing.
	*/
	
    public static void main(String[] args) 
    {
        String speedInput = JOptionPane.showInputDialog("Please enter your speed");
        int speed = Integer.parseInt(speedInput);

        String message = "Your speed is " + speed;

        JOptionPane.showMessageDialog(null, message);
        
        if(speed > 60)
        {
            JOptionPane.showMessageDialog(null,"Slow down! Drive safe.", "Ticket warning",JOptionPane.WARNING_MESSAGE);

        }
        else
        {
        	JOptionPane.showMessageDialog(null, "Congratualations! You are a safe driver.");
        }
    }
}
