#include <SoftwareSerial.h>
SoftwareSerial mySerial (5,4);

#include "DHT.h"            
#define DHTPIN 2       
const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();         
}

void loop() {
  float h = dht.readHumidity();    
  float t = dht.readTemperature(); 

       Serial.print(h);
       Serial.print("  ");
       Serial.println(t );


  mySerial.print(h);             
  delay(1000);              
  mySerial.print(t);                           
  delay(1000);                    
}