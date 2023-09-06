void setup() {
  Serial.begin(9600); // Khởi tạo cổng Serial (UART) trên ESP8266
}

void loop() {
  int num = 22;
  String dataToSend = String(num) ; // Giá trị số 22 bạn muốn gửi
  Serial.println(dataToSend); // Gửi dữ liệu qua cổng Serial (UART)
  delay(5000); // Chờ 5 giây trước khi gửi dữ liệu tiếp theo
}
