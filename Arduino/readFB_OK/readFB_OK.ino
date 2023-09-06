#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"


FirebaseData fbdo;

void setup() {
  Serial.begin(115200);

  // Kết nối đến mạng Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Kết nối đến Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Đọc giá trị kiểu chuỗi (string) từ Firebase
  if (Firebase.RTDB.getString(&fbdo, "/tray5/hum")) {
    if (fbdo.dataType() == "string") {
      String humValue = fbdo.stringData();
      Serial.print("Humidity Value: ");
      Serial.println(humValue);
    }
  } else {
    Serial.print("Failed to get Humidity data: ");
    Serial.println(fbdo.errorReason());
  }

  // Đọc giá trị kiểu chuỗi (string) từ Firebase
  if (Firebase.RTDB.getString(&fbdo, "/tray5/temp")) {
    if (fbdo.dataType() == "string") {
      String tempValue = fbdo.stringData();
      Serial.print("Temperature Value: ");
      Serial.println(tempValue);
    }
  } else {
    Serial.print("Failed to get Temperature data: ");
    Serial.println(fbdo.errorReason());
  }

  delay(10000); // Đọc dữ liệu mỗi 10 giây
}  if (timeClient.getSeconds() == 0) {
    day = ++i;
    // Serial.print("T:  ");
    // Serial.print(k2_decimal.toInt());
    // Serial.print("  H:  ");
    // Serial.print(k1_decimal.toInt());
    // Serial.print("  TM:  ");
    // Serial.println(timeClient.getSeconds());
  }

  if (millis() - myTime > 5000) {
    if (Firebase.RTDB.getString(&fbdo, "/tray5/hum")) {
      if (fbdo.dataType() == "string") {
        humValue = fbdo.stringData();
        // Serial.println(humValue);
      }
    } else {
      Serial.print("Failed to get Humidity data: ");
      Serial.println(fbdo.errorReason());
    }

    if (Firebase.RTDB.getString(&fbdo, "/tray5/temp")) {
      if (fbdo.dataType() == "string") {
        tempValue = fbdo.stringData();
        // Serial.println(tempValue);
      }
    } else {
      Serial.print("Failed to get Temperature data: ");
      Serial.println(fbdo.errorReason());
    }

    float ht = humValue.toFloat();
    float tt = tempValue.toFloat();
    datat += "*" + String(ht);
    datat += "#" + String(tt);
    Serial2.print(datat);
    // Serial.println(datat);
    delay(1000);
    data = "";
  }
  FirebaseData fbdo;

String data, datat, tem, k1_decimal, k2_decimal, humValue, tempValue;
String k1 = "", k2 = "";
int e1 = 0, e2 = 0;
int day = 0, i = 0;