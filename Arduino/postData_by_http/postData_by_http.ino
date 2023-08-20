#include <ArduinoHttpClient.h>
#include <WiFi.h>

WiFiClient wifiClient;
HttpClient client = HttpClient(wifiClient, "your-project-id.firebaseio.com", 443);

void setup() {
  // Kết nối Wi-Fi

  // Ghi dữ liệu vào Firebase
  String path = "/your-data-path.json";
  String data = "{\"key\":\"value\"}"; // Dữ liệu bạn muốn gửi
  client.put(path, "application/json", data);
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
