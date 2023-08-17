#include "FirebaseESP32.h"
#include "WiFi.h"

const char* ssid = "MINH KHA";
const char* password = "0855508877"; 

#define FIREBASE_HOST "demoweb-174ea/database/demoweb-174ea-default-rtdb/data/~2F" //2 cái này lấy trong FB nhé
#define FIREBASE_AUTH "MDPTT0HTtkNjWu6dR1YoPU5i5mX7CfSlRSAusiNZ "

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
  Firebase.setDouble(firebaseData, "sensor/value", millis());

  delay(100); // Send data every 5 seconds
}
