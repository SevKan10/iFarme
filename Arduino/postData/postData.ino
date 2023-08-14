#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "Kênh Sáng Tạo Trẻ";
const char* password = "dangkykenhsangtaotrenhe";
const char* serverURL = "http://192.168.1.2/"; // Thay thế bằng URL của trang web nhận dữ liệu
WebServer webServer();
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  float temperature = 25.0; // Độ nhiệt độ (đọc từ cảm biến)
  float humidity = 50.0; // Độ ẩm (đọc từ cảm biến)
  int day = 10; // Ngày (lấy từ thời gian thực)

  sendDataToServer(temperature, humidity, day);
  
  delay(60000); // Gửi dữ liệu mỗi 1 phút
}

void sendDataToServer(float temp, float hum, int day) {
  HTTPClient http;
  http.begin(serverURL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  String postData = "temp=" + String(temp) + "&hum=" + String(hum) + "&day=" + String(day);
  
  int httpResponseCode = http.POST(postData);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.println("Error sending data to server");
  }

  http.end();
}
