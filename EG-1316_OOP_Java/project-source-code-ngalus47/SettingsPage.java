import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

import java.net.URI;
import java.util.function.Consumer;

/**
 * <h1>Settings Page</h1>
 * JavaFX UI component for managing Spotify connection and future playlist settings.
 * Allows the user to connect to Spotify, initialize playback controller, and return to the main view.
 * 
 * This class is part of the VIBE Pulse app interface.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public class SettingsPage extends VBox {

    /**
     * Constructs the SettingsPage layout and behavior.
     * 
     * @param onBack Callback to switch back to the main view
     * @param spotifyService Shared SpotifyService instance
     * @param setPlaybackController Consumer to pass back the created SpotifyPlaybackController
     */
    public SettingsPage(Runnable onBack, SpotifyService spotifyService,
                        Consumer<SpotifyPlaybackController> setPlaybackController) {
        setSpacing(20);
        setPadding(new Insets(20));
        setAlignment(Pos.TOP_CENTER);
        setStyle("-fx-background-color: #f5f5f5;");

        Label title = new Label("Settings");
        title.setFont(Font.font("Arial", 24));

        Button backBtn = new Button("← Back to Home");
        backBtn.setStyle(
            "-fx-background-color: white; " +
            "-fx-border-color: #ccc; " +
            "-fx-border-radius: 6; " +
            "-fx-background-radius: 6;"
        );

        VBox card = new VBox(15);
        card.setPadding(new Insets(20));
        card.setAlignment(Pos.TOP_CENTER);
        card.setStyle(
            "-fx-background-color: white; " +
            "-fx-background-radius: 12; " +
            "-fx-effect: dropshadow(gaussian, rgba(0,0,0,0.1), 6, 0.2, 0, 2);"
        );

        Button connectBtn = new Button("Connect to Spotify");
        connectBtn.setStyle(
            "-fx-background-color: #28a745; " +
            "-fx-text-fill: white; " +
            "-fx-font-size: 16px; " +
            "-fx-background-radius: 6;"
        );
        connectBtn.setMinWidth(200);

        Label restLabel = new Label("REST Playlist: auto-populate & edit coming soon");
        Label activeLabel = new Label("ACTIVE Playlist: auto-populate & edit coming soon");

        Button openRestBtn = new Button("Open REST Playlist");
        Button openActiveBtn = new Button("Open ACTIVE Playlist");

        // Handle Spotify connection in background thread
        connectBtn.setOnAction(e -> {
            new Thread(() -> {
                String token = spotifyService.connectAndReturnUserToken();
                if (token != null) {
                    try {
                        spotifyService.transferPlayback(token);
                        SpotifyPlaybackController controller = new SpotifyPlaybackController(spotifyService, token);
                        setPlaybackController.accept(controller);

                        controller.resetZone();            // ensures a track will be played
                        controller.handleBpmUpdate(80f);   // simulate REST zone for startup
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }
            }).start();
        });

        // Go back to main view
        backBtn.setOnAction(e -> onBack.run());

        card.getChildren().addAll(title, connectBtn, restLabel, openRestBtn, activeLabel, openActiveBtn);
        getChildren().addAll(backBtn, card);
    }

    /**
     * Opens a given URL in the user's default browser.
     * 
     * @param url String containing a valid HTTP or HTTPS URL
     */
    private void openInBrowser(String url) {
        try {
            java.awt.Desktop.getDesktop().browse(new URI(url));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
