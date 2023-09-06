String receivedData = "";

void setup() {
  Serial.begin(9600); 
  Serial2.begin(9600); 
}

void loop() {
   while (Serial2.available()) {
    char receivedChar = Serial2.read();
    if (receivedChar == '\n') {
      Serial.print("Received Data: ");
      Serial.println(receivedData);
      receivedData = "";
    } else {
      receivedData += receivedChar;
    }
  }
}
