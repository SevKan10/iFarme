#include <ArduinoHttpClient.h>
#include <WiFi.h>

WiFiClient wifiClient;
HttpClient client = HttpClient(wifiClient, "your-project-id.firebaseio.com", 443);

void setup() {
  // Kết nối Wi-Fi

  // Đọc dữ liệu từ Firebase
  String path = "/your-data-path.json";
  client.get(path);
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.print("HTTP Response Code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
}

void loop() {
  // Your loop code here
}
