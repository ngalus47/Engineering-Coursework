/**
 * <h1>VIBE Pulse UI Test</h1> Test class used to manually verify the behavior
 * of the VIBE Pulse app and heart rate simulation. Initializes a Powerlifting
 * activity and launches the JavaFX UI.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public class VIBEPulseTest {

	/**
	 * Main method for testing the Powerlifting heart rate reader and launching the
	 * UI.
	 * 
	 * @param args Command-line arguments passed to the application
	 */
	public static void main(String[] args) {
		// Create Powerlifting activity instance for initial test
		Powerlifting lifting = new Powerlifting("Blue");

		// Simulate one heart rate reading
		lifting.readHeartRate();

		// Launch JavaFX application
		VIBEPulseUI.launch(VIBEPulseUI.class, args);
	}
}
