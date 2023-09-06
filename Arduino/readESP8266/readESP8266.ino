String receivedData = "";

void setup() {
  Serial.begin(9600); // Khởi tạo cổng Serial (UART) cho Serial Monitor
}

void loop() {
   while (Serial.available()) {
    char receivedChar = Serial.read();
    if (receivedChar == '\n') {
      // Nếu gặp ký tự newline, hiển thị dữ liệu và đặt lại receivedData
      Serial.print("Received Data: ");
      Serial.println(receivedData);
      receivedData = "";
    } else {
      // Nếu không phải ký tự newline, thêm vào receivedData
      receivedData += receivedChar;
    }
  }
}
