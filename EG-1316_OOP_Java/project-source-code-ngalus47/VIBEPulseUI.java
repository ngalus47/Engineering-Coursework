
/**
 * <h1>VIBE Pulse UI</h1>
 * Main user interface for the VIBE Pulse app. Handles view switching, activity selection,
 * live heart rate tracking, and Spotify playback controls.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */

import java.util.Map;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class VIBEPulseUI extends Application {

	private StackPane rootPane = new StackPane();
	private VBox mainView;
	private SettingsPage settingsPage;

	private Activity selectedActivity = new Powerlifting("blue");
	private javafx.animation.Timeline timeline;
	private XYChart.Series<Number, Number> heartRateSeries = new XYChart.Series<>();
	private SpotifyPlaybackController playbackController;
	private float lastBpm = 80f;

	private SpotifyService spotifyService = new SpotifyService();
	private String restPlaylistId = null;
	private String activePlaylistId = null;

	/**
	 * Sets the ID for the rest playlist.
	 * 
	 * @param id Spotify playlist ID for rest state
	 */
	public void setRestPlaylistId(String id) {
		this.restPlaylistId = id;
	}

	/**
	 * Sets the ID for the active playlist.
	 * 
	 * @param id Spotify playlist ID for active state
	 */
	public void setActivePlaylistId(String id) {
		this.activePlaylistId = id;
	}

	/**
	 * Main entry point of the JavaFX app. Initializes and shows the main scene.
	 * 
	 * @param stage Primary stage for this application
	 */
	@Override
	public void start(Stage stage) {
		mainView = createMainView(stage);
		settingsPage = new SettingsPage(() -> rootPane.getChildren().setAll(mainView), spotifyService,
				controller -> this.playbackController = controller);

		rootPane.getChildren().add(mainView);
		Scene scene = new Scene(rootPane, 360, 700);
		stage.setScene(scene);
		stage.setTitle("VIBE Pulse");
		stage.setResizable(false);
		stage.show();
	}

	/**
	 * Constructs the main view of the app including title, activity button, heart
	 * rate chart, and controls.
	 * 
	 * @param stage The main application stage
	 * @return VBox containing the main view layout
	 */
	private VBox createMainView(Stage stage) {
		VBox root = new VBox(15);
		root.setPadding(new Insets(15));
		root.setAlignment(Pos.TOP_CENTER);
		root.setStyle("-fx-background-color: #f5f5f5;");

		HBox topBar = new HBox();
		topBar.setAlignment(Pos.CENTER);
		topBar.setPadding(new Insets(0, 20, 5, 30));
		topBar.setMinWidth(360);
		topBar.setStyle("-fx-background-color: #f5f5f5;");

		Label title = new Label("VIBE Pulse");
		title.setFont(Font.font("Arial", 20));

		Button settingsBtn = new Button("⚙");
		settingsBtn.setFont(Font.font(14));
		settingsBtn.setStyle("-fx-background-color: transparent;");
		settingsBtn.setOnAction(e -> rootPane.getChildren().setAll(settingsPage));

		Region spacerLeft = new Region();
		Region spacerRight = new Region();
		HBox.setHgrow(spacerLeft, Priority.ALWAYS);
		HBox.setHgrow(spacerRight, Priority.ALWAYS);

		topBar.getChildren().addAll(spacerLeft, title, spacerRight, settingsBtn);

		VBox card = new VBox(15);
		card.setPadding(new Insets(15));
		card.setAlignment(Pos.TOP_CENTER);
		card.setStyle("-fx-background-color: white;" + "-fx-background-radius: 10;"
				+ "-fx-effect: dropshadow(gaussian, rgba(0,0,0,0.1), 5, 0.1, 0, 2);");

		card.getChildren().addAll(createModeButtons(), createHeartRateChart(), createPlaybackControls());

		root.getChildren().addAll(topBar, card);
		return root;
	}

	/**
	 * Creates the activity selection buttons.
	 * 
	 * @return VBox containing activity mode buttons
	 */
	private VBox createModeButtons() {
		VBox buttonBox = new VBox(10);
		buttonBox.setAlignment(Pos.CENTER);

		Button lifting = new Button("Lifting");
		lifting.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				selectedActivity = new Powerlifting("blue");
				heartRateSeries.getData().clear();

				NumberAxis xAxis = (NumberAxis) heartRateSeries.getChart().getXAxis();
				xAxis.setLowerBound(0);
				xAxis.setUpperBound(100);

				if (playbackController != null) {
					playbackController.resetZone();
				}

				startLiveHeartRateUpdates();

				if (playbackController != null && selectedActivity != null) {
					Activity.HeartRateEntry first = selectedActivity.readHeartRate();
					if (first != null) {
						lastBpm = first.bpm;
						heartRateSeries.getData().add(new XYChart.Data<>(first.time, first.bpm));
						playbackController.handleBpmUpdate(first.bpm);
					}
				}
			}
		});

		lifting.setMinSize(160, 60);
		lifting.setStyle("-fx-background-color: #4caf50; -fx-text-fill: white; -fx-font-size: 16px;");
		buttonBox.getChildren().addAll(lifting);
		return buttonBox;
	}

	/**
	 * Creates and configures the heart rate chart.
	 * 
	 * @return StackPane containing the heart rate chart
	 */
	private StackPane createHeartRateChart() {
		NumberAxis xAxis = new NumberAxis(0, 60, 10);
		NumberAxis yAxis = new NumberAxis(50, 200, 10);
		xAxis.setAutoRanging(false);
		xAxis.setLabel("Time (s)");
		yAxis.setLabel("Heart Rate (bpm)");
		xAxis.setLowerBound(0);
		xAxis.setUpperBound(100);

		LineChart<Number, Number> chart = new LineChart<>(xAxis, yAxis);
		chart.setTitle("Live Heart Rate");
		chart.setLegendVisible(false);
		chart.setMinHeight(220);
		chart.getData().add(heartRateSeries);
		chart.setMaxWidth(300);

		StackPane chartContainer = new StackPane(chart);
		chartContainer.setAlignment(Pos.CENTER);
		chartContainer.setPadding(new Insets(10, 0, 0, 0));
		return chartContainer;
	}

	/**
	 * Creates the Spotify playback control buttons.
	 * 
	 * @return HBox containing playback buttons
	 */
	private HBox createPlaybackControls() {
		HBox controls = new HBox(30);
		controls.setAlignment(Pos.CENTER);
		controls.setPadding(new Insets(10));

		Button back = new Button("⏮");
		back.setOnAction(e -> {
			if (playbackController != null) {
				playbackController.skipPrevious();
			}
		});

		Button play = new Button("▶/⏸");
		play.setOnAction(e -> {
			if (playbackController != null) {
				playbackController.togglePlayback(lastBpm);
			}
		});

		Button forward = new Button("⏭");
		forward.setOnAction(e -> {
			if (playbackController != null) {
				playbackController.skipNext();
			}
		});

		styleRoundButton(back, "#d32f2f");
		styleRoundButton(play, "#1976d2");
		styleRoundButton(forward, "#388e3c");

		HBox.setMargin(back, new Insets(0, 10, 0, 10));
		HBox.setMargin(play, new Insets(0, 10, 0, 10));
		HBox.setMargin(forward, new Insets(0, 10, 0, 10));

		controls.getChildren().addAll(back, play, forward);
		return controls;
	}

	/**
	 * Applies styling to round playback control buttons.
	 * 
	 * @param btn   The button to style
	 * @param color The background color to apply
	 */
	private void styleRoundButton(Button btn, String color) {
		btn.setStyle("-fx-background-color: " + color + ";" + "-fx-text-fill: white;" + "-fx-font-size: 24px;"
				+ "-fx-background-radius: 100px;" + "-fx-min-width: 80px;" + "-fx-min-height: 80px;");
	}

	/**
	 * Starts live updates of heart rate data using a Timeline animation. Updates
	 * the chart and Spotify playback zone as needed.
	 */
	private void startLiveHeartRateUpdates() {
		if (timeline != null) {
			timeline.stop();
		}

		timeline = new javafx.animation.Timeline(new javafx.animation.KeyFrame(javafx.util.Duration.seconds(2), e -> {
			if (selectedActivity != null) {
				Activity.HeartRateEntry entry = selectedActivity.readHeartRate();

				if (entry != null) {
					lastBpm = entry.bpm;
					heartRateSeries.getData().add(new XYChart.Data<>(entry.time, entry.bpm));

					NumberAxis xAxis = (NumberAxis) heartRateSeries.getChart().getXAxis();
					int windowSize = 100;
					if (entry.time > windowSize) {
						xAxis.setLowerBound(entry.time - windowSize);
						xAxis.setUpperBound(entry.time);
					}

					if (playbackController != null) {
						playbackController.handleBpmUpdate(entry.bpm);
					}
				}
			}
		}));
		timeline.setCycleCount(javafx.animation.Animation.INDEFINITE);
		timeline.play();
	}
}
