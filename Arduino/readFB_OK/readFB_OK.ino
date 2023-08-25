#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"

// Khởi tạo đối tượng Firebase
FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  // Kết nối Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Khởi tạo kết nối Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Đọc giá trị từ Firebase Realtime Database
  if (Firebase.getInt(firebaseData, "/Data/Day")) {
    Serial.println("Got data from Firebase:");
    Serial.print("Day: " + String(firebaseData.dataType()) + " = " + String(firebaseData.intData()));
  } else {
    Serial.println("Failed to get Day data from Firebase.");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.getInt(firebaseData, "/Data/Hum")) {
    Serial.print("  Hum: " + String(firebaseData.dataType()) + " = " + String(firebaseData.intData()));
  } else {
    Serial.println("Failed to get Hum data from Firebase.");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.getInt(firebaseData, "/Data/Temp")) {
    Serial.println("  Temp: " + String(firebaseData.dataType()) + " = " + String(firebaseData.intData()));
  } else {
    Serial.println("Failed to get Temp data from Firebase.");
    Serial.println(firebaseData.errorReason());
  }

  delay(1000);
}
