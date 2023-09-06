void setup() {
  Serial.begin(9600); // Khởi tạo cổng Serial (UART) trên ESP8266
  Serial2.begin(9600); // Khởi tạo cổng Serial (UART) trên ESP8266
}

void loop() {
  String dataToSend = "22"; // Giá trị số 22 bạn muốn gửi
  Serial2.println(dataToSend); // Gửi dữ liệu qua cổng Serial (UART)
  delay(5000); // Chờ 5 giây trước khi gửi dữ liệu tiếp theo
}
