#include <FirebaseESP32.h>
#include <FirebaseESP32HTTPClient.h>
#include <WiFi.h>

const char* ssid = "MINH KHA";
const char* password = "0855508877";
FirebaseData firebaseData;

void setup() {
  WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Send data to Firebase
  Firebase.setDouble(firebaseData, "sensor/value", 25.5);

  delay(5000); // Send data every 5 seconds
}
