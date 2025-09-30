import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.InetSocketAddress;
import java.net.URI;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.ArrayList;
import java.util.Base64;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.CountDownLatch;

import org.json.JSONArray;
import org.json.JSONObject;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;

class Playlist {
	public final String id;
	public final String name;

	public Playlist(String id, String name) {
		this.id = id;
		this.name = name;
	}

	@Override
	public String toString() {
		return name;
	}
}
/**
 * <h1>Spotify Service Utility</h1>
 * Handles communication with the Spotify Web API including:
 * authentication, playback control, playlist management, and user device handling.
 * Used in the VIBE Pulse app to sync music playback with heart rate.
 * 
 * @author Nick Galus
 * @version 1.0
 * @since 05-14-2025
 */
public class SpotifyService {

	private static final String CLIENT_ID = "c6af2b83a19143549961faaba649701c";
	private static final String CLIENT_SECRET = "40adfaa760584bd19078f2ba74c5c761";
	private static final String REDIRECT_URI = "http://localhost:8888/callback";

	private static String authorizationCode = null;
	private static final CountDownLatch latch = new CountDownLatch(1);

	/**
	 * Opens a browser to allow the user to log in and authorize access,
	 * then returns a short-lived access token.
	 * 
	 * @return Spotify user access token, or null if authorization fails
	 */
	public String connectAndReturnUserToken() {
		try {
			startServer();
			String authUrl = buildAuthorizationUrl();
			java.awt.Desktop.getDesktop().browse(URI.create(authUrl));
			latch.await();
			return getUserAccessToken(authorizationCode);
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	/**
	 * Adds tracks to an existing playlist by ID.
	 * 
	 * @param token Spotify access token
	 * @param playlistId ID of the playlist to add tracks to
	 * @param uris List of track URIs to add
	 * @throws Exception on request failure
	 */
	public void addTracksToPlaylist(String token, String playlistId, List<String> uris) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		JSONArray uriArray = new JSONArray();
		for (String uri : uris)
			uriArray.put(uri);

		JSONObject body = new JSONObject().put("uris", uriArray);

		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create("https://api.spotify.com/v1/playlists/" + playlistId + "/tracks"))
				.header("Authorization", "Bearer " + token).header("Content-Type", "application/json")
				.POST(HttpRequest.BodyPublishers.ofString(body.toString())).build();

		client.send(request, HttpResponse.BodyHandlers.ofString());
	}

	/**
	 * Pauses the current playback.
	 * 
	 * @param userAccessToken Spotify access token
	 * @throws Exception on request failure
	 */
	public void pausePlayback(String userAccessToken) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://api.spotify.com/v1/me/player/pause"))
				.header("Authorization", "Bearer " + userAccessToken).PUT(HttpRequest.BodyPublishers.noBody()).build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		System.out.println("Pause playback status: " + response.statusCode());
	}

	/**
	 * Gets the current user's playlists.
	 * 
	 * @param userAccessToken Spotify access token
	 * @return list of playlists
	 * @throws Exception on request failure
	 */
	public List<Playlist> getUserPlaylists(String userAccessToken) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://api.spotify.com/v1/me/playlists"))
				.header("Authorization", "Bearer " + userAccessToken).GET().build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		JSONObject json = new JSONObject(response.body());
		JSONArray items = json.getJSONArray("items");

		List<Playlist> playlists = new ArrayList<>();
		for (int i = 0; i < items.length(); i++) {
			JSONObject item = items.getJSONObject(i);
			playlists.add(new Playlist(item.getString("id"), item.getString("name")));
		}
		return playlists;
	}

	/**
	 * Skips to the next track in playback.
	 * 
	 * @param token Spotify access token
	 * @throws Exception on request failure
	 */
	public void skipToNext(String token) throws Exception {
	    HttpRequest request = HttpRequest.newBuilder()
	        .uri(URI.create("https://api.spotify.com/v1/me/player/next"))
	        .header("Authorization", "Bearer " + token)
	        .POST(HttpRequest.BodyPublishers.noBody())
	        .build();

	    HttpClient client = HttpClient.newHttpClient();
	    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
	    System.out.println("Skip to next status: " + response.statusCode());
	}

	/**
	 * Skips to the previous track in playback.
	 * 
	 * @param token Spotify access token
	 * @throws Exception on request failure
	 */
	public void skipToPrevious(String token) throws Exception {
	    HttpRequest request = HttpRequest.newBuilder()
	        .uri(URI.create("https://api.spotify.com/v1/me/player/previous"))
	        .header("Authorization", "Bearer " + token)
	        .POST(HttpRequest.BodyPublishers.noBody())
	        .build();

	    HttpClient client = HttpClient.newHttpClient();
	    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
	    System.out.println("Skip to previous status: " + response.statusCode());
	}

	/**
	 * Randomly plays a track from a given playlist.
	 * 
	 * @param userAccessToken Spotify access token
	 * @param playlistId Spotify playlist ID
	 * @throws Exception on request failure
	 */
	public void playRandomTrackFromPlaylist(String userAccessToken, String playlistId) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create("https://api.spotify.com/v1/playlists/" + playlistId + "/tracks"))
				.header("Authorization", "Bearer " + userAccessToken).GET().build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		JSONArray items = new JSONObject(response.body()).getJSONArray("items");

		if (items.length() > 0) {
			JSONObject track = items.getJSONObject((int) (Math.random() * items.length())).getJSONObject("track");
			String trackUri = track.getString("uri");
			playSong(userAccessToken, trackUri);
		}
	}

	/**
	 * Creates a new private playlist under the user's account.
	 * 
	 * @param token Spotify access token
	 * @param userId Spotify user ID
	 * @param name Playlist name
	 * @return Playlist ID
	 * @throws Exception on request failure
	 */
	public String createPlaylist(String token, String userId, String name) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		JSONObject body = new JSONObject().put("name", name).put("description", "Generated by VIBE Pulse").put("public",
				false);

		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create("https://api.spotify.com/v1/users/" + userId + "/playlists"))
				.header("Authorization", "Bearer " + token).header("Content-Type", "application/json")
				.POST(HttpRequest.BodyPublishers.ofString(body.toString())).build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		return new JSONObject(response.body()).getString("id");
	}

	/**
	 * Retrieves the Spotify user ID of the authenticated user.
	 * 
	 * @param token Spotify access token
	 * @return user ID as a String
	 * @throws Exception on request failure
	 */
	public String getCurrentUserId(String token) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://api.spotify.com/v1/me"))
				.header("Authorization", "Bearer " + token).GET().build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		return new JSONObject(response.body()).getString("id");
	}

	/**
	 * Retrieves or creates the default VIBE Pulse playlists (REST and ACTIVE).
	 * 
	 * @param token Spotify access token
	 * @return Map of playlist names to their Spotify IDs
	 * @throws Exception on request failure
	 */
	public Map<String, String> findOrCreateDefaultPlaylists(String token) throws Exception {
	    Map<String, String> playlistMap = new HashMap<>();
	    JSONArray playlists = getAllUserPlaylists(token);
	    String userId = getCurrentUserId(token);

	    String restId = findPrivatePlaylistIdByName(playlists, "VIBE_Pulse_REST");
	    String activeId = findPrivatePlaylistIdByName(playlists, "VIBE_Pulse_ACTIVE");

	    if (restId == null) {
	        restId = createPlaylist(token, userId, "VIBE_Pulse_REST");
	        populatePlaylist(token, restId, getRestUris());
	    }

	    if (activeId == null) {
	        activeId = createPlaylist(token, userId, "VIBE_Pulse_ACTIVE");
	        populatePlaylist(token, activeId, getActiveUris());
	    }

	    playlistMap.put("VIBE_Pulse_REST", restId);
	    playlistMap.put("VIBE_Pulse_ACTIVE", activeId);

	    return playlistMap;
	}

	/**
	 * Resumes Spotify playback on the user's current device.
	 * 
	 * @param userAccessToken Spotify access token
	 * @throws Exception on request failure
	 */
	public void resumePlayback(String userAccessToken) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://api.spotify.com/v1/me/player/play"))
				.header("Authorization", "Bearer " + userAccessToken).PUT(HttpRequest.BodyPublishers.noBody()).build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		System.out.println("Resume playback status: " + response.statusCode());
	}
	/**
	 * Starts a local HTTP server to listen for the Spotify OAuth redirect.
	 * Saves the authorization code once received.
	 * 
	 * @throws IOException if the server cannot start
	 */
	private void startServer() throws IOException {
		HttpServer server = HttpServer.create(new InetSocketAddress(8888), 0);
		server.createContext("/callback", (HttpExchange exchange) -> {
			String query = exchange.getRequestURI().getQuery();
			if (query != null && query.contains("code=")) {
				for (String param : query.split("&")) {
					if (param.startsWith("code=")) {
						authorizationCode = param.substring(5);
						break;
					}
				}
			}
			String response = "Authorization received. You can close this window.";
			exchange.sendResponseHeaders(200, response.length());
			try (OutputStream os = exchange.getResponseBody()) {
				os.write(response.getBytes());
			}
			latch.countDown();
			server.stop(0);
		});
		server.start();
		System.out.println("Local HTTP server started on http://localhost:8888/callback");
	}

	/**
	 * Builds the Spotify OAuth authorization URL with required scopes.
	 * 
	 * @return Encoded URL string
	 * @throws UnsupportedEncodingException if encoding fails
	 */
	private String buildAuthorizationUrl() throws UnsupportedEncodingException {
		String scopes = "user-read-playback-state user-modify-playback-state playlist-modify-private playlist-modify-public";
		String url = "https://accounts.spotify.com/authorize" + "?response_type=code" + "&client_id=" + CLIENT_ID
				+ "&scope=" + URLEncoder.encode(scopes, "UTF-8") + "&redirect_uri="
				+ URLEncoder.encode(REDIRECT_URI, "UTF-8") + "&state=xyz";
		return url;
	}

	/**
	 * Exchanges authorization code for an access token using Spotify's API.
	 * 
	 * @param code The authorization code received from the redirect
	 * @return Spotify access token
	 * @throws Exception if the exchange fails
	 */
	private String getUserAccessToken(String code) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		String auth = CLIENT_ID + ":" + CLIENT_SECRET;
		String encodedAuth = Base64.getEncoder().encodeToString(auth.getBytes());

		String form = "grant_type=authorization_code" + "&code=" + code + "&redirect_uri="
				+ URLEncoder.encode(REDIRECT_URI, "UTF-8");

		HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://accounts.spotify.com/api/token"))
				.header("Authorization", "Basic " + encodedAuth)
				.header("Content-Type", "application/x-www-form-urlencoded")
				.POST(HttpRequest.BodyPublishers.ofString(form)).build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		return new JSONObject(response.body()).getString("access_token");
	}

	/**
	 * Transfers playback to the user's active device and starts playing.
	 * 
	 * @param token Spotify access token
	 * @throws Exception if transfer fails or no device is active
	 */
	public void transferPlayback(String token) throws Exception {
	    String deviceId = getActiveDeviceId(token);

	    JSONObject body = new JSONObject()
	        .put("device_ids", new JSONArray().put(deviceId))
	        .put("play", true);

	    HttpRequest request = HttpRequest.newBuilder()
	        .uri(URI.create("https://api.spotify.com/v1/me/player"))
	        .header("Authorization", "Bearer " + token)
	        .header("Content-Type", "application/json")
	        .PUT(HttpRequest.BodyPublishers.ofString(body.toString()))
	        .build();

	    HttpClient client = HttpClient.newHttpClient();
	    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

	    System.out.println("Transfer playback response: " + response.statusCode());
	}

	/**
	 * Retrieves the device ID of the active Spotify device.
	 * 
	 * @param token Spotify access token
	 * @return Active device ID string
	 * @throws Exception if no device is active
	 */
	public String getActiveDeviceId(String token) throws Exception {
	    HttpRequest request = HttpRequest.newBuilder()
	        .uri(URI.create("https://api.spotify.com/v1/me/player/devices"))
	        .header("Authorization", "Bearer " + token)
	        .build();

	    HttpClient client = HttpClient.newHttpClient();
	    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

	    JSONArray devices = new JSONObject(response.body()).getJSONArray("devices");
	    for (int i = 0; i < devices.length(); i++) {
	        JSONObject dev = devices.getJSONObject(i);
	        if (dev.getBoolean("is_active")) {
	            return dev.getString("id");
	        }
	    }

	    throw new IllegalStateException("No active Spotify device found. Please open Spotify on a device.");
	}

	/**
	 * Plays a single Spotify track using its URI.
	 * 
	 * @param token Spotify access token
	 * @param trackUri Spotify URI of the track
	 * @throws Exception if playback fails
	 */
	public void playSong(String token, String trackUri) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		JSONObject body = new JSONObject()
			.put("uris", new JSONArray().put(trackUri))
			.put("position_ms", 0);

		HttpRequest request = HttpRequest.newBuilder()
			.uri(URI.create("https://api.spotify.com/v1/me/player/play"))
			.header("Authorization", "Bearer " + token)
			.header("Content-Type", "application/json")
			.PUT(HttpRequest.BodyPublishers.ofString(body.toString()))
			.build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		System.out.println("Playback status: " + response.statusCode());
		System.out.println("Playback response: " + response.body());
	}

	/**
	 * Finds the ID of a private playlist by name from a playlist array.
	 * 
	 * @param playlists JSONArray of playlists
	 * @param name Name to match
	 * @return Playlist ID if found, otherwise null
	 */
	private String findPrivatePlaylistIdByName(JSONArray playlists, String name) {
		for (int i = 0; i < playlists.length(); i++) {
			JSONObject pl = playlists.getJSONObject(i);
			if (name.equals(pl.getString("name")) && !pl.getBoolean("public")) {
				return pl.getString("id");
			}
		}
		return null;
	}

	/**
	 * Populates the given playlist with the provided track URIs.
	 * 
	 * @param token Spotify access token
	 * @param playlistId Playlist ID
	 * @param trackUris List of track URIs
	 * @throws Exception if request fails
	 */
	public void populatePlaylist(String token, String playlistId, List<String> trackUris) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		JSONObject body = new JSONObject();
		body.put("uris", trackUris);

		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create("https://api.spotify.com/v1/playlists/" + playlistId + "/tracks"))
				.header("Authorization", "Bearer " + token).header("Content-Type", "application/json")
				.POST(HttpRequest.BodyPublishers.ofString(body.toString())).build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		if (response.statusCode() != 201) {
			System.out.println("Failed to populate playlist: " + response.body());
		}
	}

	/**
	 * Gets a list of default 'rest' track URIs used for relaxing playback.
	 * 
	 * @return List of track URIs
	 */
	public List<String> getRestUris() {
	    return List.of(
	        "spotify:track:7pKfPomDEeI4TPT6EOYjn9",
	        "spotify:track:5CQ30WqJwcep0pYcV4AMNc",
	        "spotify:track:6Ozh9Ok6h4Oi1wUSLtBseN",
	        "spotify:track:3B54sVLJ402zGa6Xm4YGNe",
	        "spotify:track:4J4k0RQ4pSJ1y3FLOj4qx3"
	    );
	}

	/**
	 * Gets a list of default 'active' track URIs used for workout playback.
	 * 
	 * @return List of track URIs
	 */
	public List<String> getActiveUris() {
	    return List.of(
	        "spotify:track:6rqhFgbbKwnb9MLmUQDhG6",
	        "spotify:track:3Qm86XLflmIXVm1wcwkgDK",
	        "spotify:track:1AhDOtG9vPSOmsWgNW0BEY",
	        "spotify:track:4cH6v3Jq3zW3V1L6x6x6x",
	        "spotify:track:0j2T0R9o6E3THQnIt4f3yR"
	    );
	}

	/**
	 * Retrieves all user playlists with a limit of 50 results.
	 * 
	 * @param token Spotify access token
	 * @return JSONArray of playlist objects
	 * @throws Exception if request fails
	 */
	private JSONArray getAllUserPlaylists(String token) throws Exception {
		HttpClient client = HttpClient.newHttpClient();
		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create("https://api.spotify.com/v1/me/playlists?limit=50"))
				.header("Authorization", "Bearer " + token).GET().build();

		HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
		JSONObject json = new JSONObject(response.body());
		return json.getJSONArray("items");
	}
}
