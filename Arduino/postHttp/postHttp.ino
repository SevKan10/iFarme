#include <ArduinoHttpClient.h>
#include <WiFi.h>
//-------------------------------Thư viện
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"
//-------------------------------Khai báo mạng
WiFiClient wifiClient;
HttpClient client = HttpClient(wifiClient, "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/", 443);


void setup() {
  Serial.begin(9600);
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

  Serial.println("------------------------------------");
  Serial.println("Connected...");
}

void loop() {

  // Gửi dữ liệu vào Firebase
  String path = "/test.json"; // Điều này gửi dữ liệu vào nút "/test"
  String data = "{\"value\": " + String(random(0, 10)) + "}"; // Dữ liệu muốn gửi
  client.put(path, "application/json", data); // Content-Type là "application/json" cho dữ liệu JSON
  Serial.println(data);
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.print("HTTP Response Code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  delay(100);
}


