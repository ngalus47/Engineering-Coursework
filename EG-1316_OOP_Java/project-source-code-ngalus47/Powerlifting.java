/**
 * <h1>Powerlifting Activity Simulation</h1>
 * Simulates heart rate changes during a powerlifting session.
 * Cycles through warmup, active, and cooldown phases, adjusting BPM values over time.
 * 
 * This class extends the abstract Activity class and is used in the VIBE Pulse app.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public class Powerlifting extends Activity {
    private int time = 0;
    private float currentBPM = 80; // start near resting
    private final float peakBPM = 165;
    private final float restBPM = 80;

    private enum Phase { WARMUP, ACTIVE, COOLDOWN }
    private Phase phase = Phase.WARMUP;

    /**
     * Constructs a new Powerlifting activity with the specified color.
     * 
     * @param colorHex Hex color string used for UI visuals
     */
    public Powerlifting(String colorHex) {
        setColorHex(colorHex);
        setName("Powerlifting");
    }

    /**
     * Determines if heart rate logic should be triggered based on current BPM.
     * 
     * @param bpm Current heart rate in beats per minute
     * @return true if the bpm is below 120, otherwise false
     */
    @Override
    public boolean heartRateTrigger(int bpm) {
        return bpm < 120;
    }

    /**
     * Simulates a heart rate reading based on the current phase of the workout.
     * Gradually increases or decreases the BPM depending on phase progression.
     * 
     * @return Simulated HeartRateEntry with time and BPM value
     */
    @Override
    public HeartRateEntry readHeartRate() {
        float bpm;

        switch (phase) {
            case WARMUP:
                bpm = currentBPM + (float)(Math.random() * 5 + 1); // +1 to +6
                if (bpm >= 140) {
                    bpm = 140;
                    phase = Phase.ACTIVE;
                }
                break;

            case ACTIVE:
                bpm = currentBPM + (float)(Math.random() * 5 + 2); // +2 to +7
                if (bpm >= peakBPM) {
                    bpm = peakBPM;
                    phase = Phase.COOLDOWN;
                }
                break;

            case COOLDOWN:
                bpm = currentBPM - (float)(Math.random() * 5 + 1); // -1 to -6
                if (bpm <= restBPM) {
                    bpm = restBPM;
                }
                break;

            default:
                bpm = currentBPM;
        }

        currentBPM = bpm;
        HeartRateEntry entry = new HeartRateEntry(time, bpm);
        time += 10; // increment simulation time
        return entry;
    }
}
