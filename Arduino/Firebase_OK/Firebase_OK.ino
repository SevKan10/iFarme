#include <WiFi.h>
#include <FirebaseESP32.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define FIREBASE_HOST "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"

FirebaseData firebaseData;
FirebaseJson json;
FirebaseData fbdo;

String data, datat, tem, k1_decimal, k2_decimal, humValue, tempValue;
String k1 = "", k2 = "";
int e1 = 0, e2 = 0;
int day = 0, i = 0;

const long utcOffsetInSeconds = 7 * 3600;  // Độ chênh lệch múi giờ, ở đây là UTC+7 (Việt Nam)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

unsigned long myTime = 0;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  // Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  // Tiny, small, medium, large, and unlimited.
  // Size and its write timeout: tiny (1s), small (10s), medium (30s), large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  Firebase.enableClassicRequest(firebaseData, true);

  Serial.println("Connected...");

  timeClient.begin();
}

void loop() {

  String read;
  while (Serial2.available() > 0) {
    read = Serial2.readString();
    data += String(read);
    tem = data;
    data = "";
  }

  for (int i = 0; i < tem.length(); i++) {
    if (tem[i] == '*') {
      e1 = 1;
      e2 = 0;
    } else if (tem[i] == '#') {
      e2 = 1;
      e1 = 0;
    } else {
      if (e1 == 1) {
        k1 += tem[i];
      }
      if (e2 == 1) {
        k2 += tem[i];
      }
    }
  }

  timeClient.update();

  if (millis() - myTime >= 1000) {
    myTime = millis();

    if (!k1.isEmpty() && !k2.isEmpty()) {
      k1_decimal = k1.substring(0, 2);
      k2_decimal = k2.substring(0, 2);

      json.clear();
      json.set("/Temp", k2_decimal.toInt());
      json.set("/Day", day);
      json.set("/Hum", k1_decimal.toInt());

      Firebase.updateNode(firebaseData, "/Tray1", json);
      Firebase.updateNode(firebaseData, "/Tray2", json);
      Firebase.updateNode(firebaseData, "/Tray3", json);
      Firebase.updateNode(firebaseData, "/Tray4", json);

      k1 = "";
      k2 = "";
    }
  }

}
