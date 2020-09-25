//The MQTT credentials

EspMQTTClient client(
  "Harleys iPhone",             // Wifi ssid  ABB_Indgym_Guest
  "hejhoj123",                 // Wifi password   Welcome2abb
  "maqiatto.com",              // MQTT broker ip
  1883,                        // MQTT broker port
  "harley@berglun.se",         // MQTT username
  "HEJHEJ",                    // MQTT password
  "Node",                      // Client name
  onConnectionEstablished,     // Connection established callback
  true,                        // Enable web updater
  true                         // Enable debug messages
);
