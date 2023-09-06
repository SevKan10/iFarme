#include <SoftwareSerial.h>
SoftwareSerial Serial2(D5, D6);  //RX TX 2 chân này và chân D1 D2 chạy ổn định nhất Sửa D7 D8 lỗi banh xác :))
String data;
//------------------------------------------------------
#include "DHT.h"
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//-------------------------------------------------------
unsigned int i = 0;
unsigned int day = 0;
unsigned long mytime;
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  while (!Serial) { ; }
  while (!Serial2) { ; }

  dht.begin();
}

void loop() {

  Rece();
  Send();
}

void Rece() {
  String read;
  while (Serial2.available() > 0) {
    read = Serial2.readString();
    data += String(read);
    Serial.print(data);
    data = "";  // Không sửa thành println, được phép bỏ
  }
}

void Send()  // Giữ nguyên
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  data += "*" + String(h);
  data += "#" + String(t);
  Serial2.print(data);
  // Serial.println(data);
  delay(1000);
  data = "";
}
