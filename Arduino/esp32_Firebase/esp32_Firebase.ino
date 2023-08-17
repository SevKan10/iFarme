#include <WiFi.h> 
#include <WiFiClient.h> 
#include "FirebaseESP32.h"
#include <ArduinoJson.h>
#define LDR_PIN       34        

#define WIFI_SSID "MINH KHA"                //Nhập thông tin wifi của nhà bạn vào đây
#define WIFI_PASSWORD "0855508877"

#define FIREBASE_HOST "console.firebase.google.com/project/demoweb-174ea/database/demoweb-174ea-default-rtdb/data/~2F" //2 cái này lấy trong FB nhé
#define FIREBASE_AUTH "MDPTT0HTtkNjWu6dR1YoPU5i5mX7CfSlRSAusiNZ "
FirebaseData firebaseData;
unsigned long t1= 0;
int x =0;         //khai báo biến x nhận dữ liệu
//Wifi client;
String path = "/";
FirebaseJson json;

float getLightPercentage(void)
{
  int ldrRawVal;
  float percentage;
  ldrRawVal = analogRead(LDR_PIN);    
  percentage = ((float)((ldrRawVal*100)/4096));
  return percentage;
}
void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  if (!Firebase.beginStream(firebaseData, path))
  {
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println();
  }
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
}

void loop() {

  // put your main code here, to run repeatedly:
Firebase.setInt(firebaseData, path + "/LDR/Percent", 12); //gui gtri tu esp len fb kieu nguyen
//  
//   Firebase.getInt(firebaseData, path + "/LDR/Percent")); //lấy gtri từ Firebase về gán vào biến x
//        x = firebaseData.intData(); //lay gtri tu fb ve esp
  float lightpercentage = getLightPercentage();
  if (millis() - t1 > 500){
    if (Firebase.setFloat(firebaseData, path + "/LDR/Percent", lightpercentage))
        
      t1= millis();
  }
  }