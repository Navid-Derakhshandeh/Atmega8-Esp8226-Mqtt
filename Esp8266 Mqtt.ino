#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "test.mosquitto.org";
const char* mqtt_topic = "cip";

WiFiClient espClient;
PubSubClient client(espClient);

const int ledPin = D1;  // D1 = GPIO5

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(" Message received:");
  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  Serial.println(message);

  // Convert message to integer safely
  int value = message.toInt();
  Serial.print("Converted to integer: ");
  Serial.println(value);

  // Control LED based on value
  if (value > 50) {
    digitalWrite(ledPin, HIGH);
    Serial.println(" LED ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println(" LED OFF");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client_" + String(random(0xffff), HEX);
if (client.connect(clientId.c_str())) {
  Serial.println("connected ");
  client.subscribe(mqtt_topic);
  Serial.println("Subscribed to topic: cip");
} else {
  Serial.print(" failed, rc=");
  Serial.println(client.state());
  delay(5000);
}
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Make sure LED starts off
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
