import java.io.*;
import java.util.Map;

/**
 * <h1>Activity Base Class</h1>
 * Abstract base class for modeling different physical activities and their heart rate behavior.
 * Handles color representation, name, zone mapping, and simulation file input.
 * 
 * Used by VIBE Pulse for activity-specific BPM simulation and zone-based playback control.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public abstract class Activity {
    String name;
    String colorHex;
    protected DataInputStream input;
    private final String filePath = "simulate.dat";

    /**
     * Represents heart rate zones: REST or ACTIVE.
     */
    public enum Zone {
        REST,
        ACTIVE
    }

    /**
     * Maps a given BPM to a zone.
     * 
     * @param bpm Beats per minute
     * @return Zone.REST if bpm < 120, otherwise Zone.ACTIVE
     */
    public static Zone getZone(float bpm) {
        return bpm < 120 ? Zone.REST : Zone.ACTIVE;
    }

    /**
     * Static map linking zones to default Spotify track URIs.
     */
    public static final Map<Zone, String> zoneToTrack = Map.of(
        Zone.REST,    "spotify:track:1hKdDCpiI9mqz1jVHRKG0E",
        Zone.ACTIVE,  "spotify:track:6rqhFgbbKwnb9MLmUQDhG6"
    );

    /**
     * Constructor attempts to open a binary file input stream for data simulation.
     * File is named "simulate.dat" by default.
     */
    public Activity() {
        try {
            input = new DataInputStream(new FileInputStream(filePath));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Determines whether the given BPM value should trigger a heart rate event.
     * 
     * @param bpm Current heart rate
     * @return true if threshold met, otherwise false
     */
    public abstract boolean heartRateTrigger(int bpm);

    /**
     * Reads the next simulated heart rate entry for the activity.
     * 
     * @return A HeartRateEntry containing time and bpm
     */
    public abstract HeartRateEntry readHeartRate();

    /**
     * <h2>HeartRateEntry</h2>
     * Small helper class to store time and bpm values for a single reading.
     */
    public static class HeartRateEntry {
        public int time;
        public float bpm;

        /**
         * Constructs a new heart rate entry.
         * 
         * @param time Time in seconds since simulation start
         * @param bpm Beats per minute at the given time
         */
        public HeartRateEntry(int time, float bpm) {
            this.time = time;
            this.bpm = bpm;
        }
    }

    /**
     * Returns the activity name.
     * 
     * @return Name string
     */
    public String getName() { return name; }

    /**
     * Sets the activity name.
     * 
     * @param name Name string
     */
    public void setName(String name) { this.name = name; }

    /**
     * Returns the hex color used for UI visuals.
     * 
     * @return Hex color string
     */
    public String getColorHex() { return colorHex; }

    /**
     * Sets the hex color used for UI visuals.
     * 
     * @param colorHex Hex color string
     */
    public void setColorHex(String colorHex) { this.colorHex = colorHex; }
}

