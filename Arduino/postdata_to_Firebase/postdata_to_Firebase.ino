#include "FirebaseESP32.h"
#include "WiFi.h"

const char* ssid = "MINH KHA";
const char* password = "0855508877"; 

#define FIREBASE_HOST "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"

FirebaseData firebaseData;
void setup() {
  Serial.begin(9600);
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
  Firebase.setDouble(firebaseData, "test/value", millis());

  delay(100);
}
