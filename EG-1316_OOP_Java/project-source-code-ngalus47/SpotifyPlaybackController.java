import java.util.List;

/**
 * <h1>Spotify Playback Controller</h1>
 * Controls Spotify playback logic based on heart rate zones. 
 * Plays or pauses music, manages zone changes, and selects songs based on current activity.
 * Integrates with the SpotifyService to make API calls.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public class SpotifyPlaybackController {
	private final SpotifyService spotifyService;
	private final String userAccessToken;
	private Activity.Zone lastZone = null;
	private boolean playbackActive = false;

	private String restPlaylistId;
	private String activePlaylistId;

	private final List<String> restTracks = List.of(
		"spotify:track:1c6xK3q4xqjv3tVjXc5v0x", // George Harrison
		"spotify:track:3yfqSUWxFvZELEM4PmlwIR", // Sam Cooke
		"spotify:track:7pKfPomDEeI4TPT6EOYjn9", // Buffalo Springfield
		"spotify:track:4Z4F8xZ7z6z9M8nV7h6Z7h", // Brent Cobb
		"spotify:track:0xYvDCc4N2b8t5xN6b6x6x"  // Kacey Musgraves (placeholder)
	);

	private final List<String> activeTracks = List.of(
		"spotify:track:6rqhFgbbKwnb9MLmUQDhG6", // Black Sabbath
		"spotify:track:3Qm86XLflmIXVm1wcwkgDK", // Motörhead
		"spotify:track:1AhDOtG9vPSOmsWgNW0BEY", // Iron Maiden
		"spotify:track:4cH6v3Jq3zW3V1L6x6x6x", // Ozzy Osbourne (placeholder)
		"spotify:track:7yCPwWs66K8Ba5lFuU2bcx"  // Nirvana
	);

	/**
	 * Constructs the playback controller.
	 * 
	 * @param service Instance of SpotifyService for API calls
	 * @param token Spotify user access token
	 */
	public SpotifyPlaybackController(SpotifyService service, String token) {
		this.spotifyService = service;
		this.userAccessToken = token;
	}

	/**
	 * Picks a random track URI from a list of URIs.
	 * 
	 * @param tracks List of Spotify track URIs
	 * @return A random track URI
	 */
	private String pickRandom(List<String> tracks) {
		int index = (int) (Math.random() * tracks.size());
		return tracks.get(index);
	}

	/**
	 * Skips to the next track using Spotify API.
	 */
	public void skipNext() {
		try {
			spotifyService.skipToNext(userAccessToken);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Skips to the previous track using Spotify API.
	 */
	public void skipPrevious() {
		try {
			spotifyService.skipToPrevious(userAccessToken);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Sets the ID of the user's rest playlist.
	 * 
	 * @param id Spotify playlist ID
	 */
	public void setRestPlaylistId(String id) {
		this.restPlaylistId = id;
	}

	/**
	 * Sets the ID of the user's active playlist.
	 * 
	 * @param id Spotify playlist ID
	 */
	public void setActivePlaylistId(String id) {
		this.activePlaylistId = id;
	}

	/**
	 * Resets the current heart rate zone.
	 * Used to trigger new playback on the next update.
	 */
	public void resetZone() {
		this.lastZone = null;
	}

	/**
	 * Toggles between play and pause depending on current state.
	 * Selects song based on heart rate zone when resuming.
	 * 
	 * @param bpm Current heart rate in beats per minute
	 */
	public void togglePlayback(float bpm) {
		try {
			if (playbackActive) {
				spotifyService.pausePlayback(userAccessToken);
				playbackActive = false;
				System.out.println("Playback paused");
			} else {
				Activity.Zone zone = Activity.getZone(bpm);
				String trackUri = Activity.zoneToTrack.get(zone);
				spotifyService.playSong(userAccessToken, trackUri);
				playbackActive = true;
				System.out.println("Resumed with track for zone " + zone);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Called when heart rate updates. Chooses a new track if zone has changed.
	 * Automatically transfers playback to an active device.
	 * 
	 * @param bpm Current heart rate in beats per minute
	 */
	public void handleBpmUpdate(float bpm) {
		Activity.Zone currentZone = Activity.getZone(bpm);

		try {
			if (currentZone != lastZone || !playbackActive) {
				lastZone = currentZone;

				String trackUri;
				if (currentZone == Activity.Zone.ACTIVE) {
					trackUri = pickRandom(activeTracks);
					System.out.println("Zone: ACTIVE → " + trackUri);
				} else {
					trackUri = pickRandom(restTracks);
					System.out.println("Zone: REST → " + trackUri);
				}

				if (trackUri != null) {
					spotifyService.transferPlayback(userAccessToken);
					spotifyService.playSong(userAccessToken, trackUri);
					playbackActive = true;
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Manually resumes playback based on the current heart rate.
	 * 
	 * @param bpm Current heart rate in beats per minute
	 */
	public void resumeManually(float bpm) {
		Activity.Zone zone = Activity.getZone(bpm);
		try {
			String trackUri = Activity.zoneToTrack.get(zone);
			spotifyService.playSong(userAccessToken, trackUri);
			playbackActive = true;
			System.out.println("Manual resume for zone " + zone);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
