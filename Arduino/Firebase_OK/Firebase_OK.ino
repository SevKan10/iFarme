#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
FirebaseData firebaseData;
FirebaseJson json;
long unsigned int myTime = 0;
void setup() 
{

  Serial.begin(9600); 

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  Firebase.enableClassicRequest(firebaseData, true);
  

  //String path = "/data";


  Serial.println("------------------------------------");
  Serial.println("Connected...");
}

void loop() 
{
  if (millis()-myTime>=5000)
  {
    float t = random(10,50);
    float h = random(50,100);
    int day = random(10,30);
    json.clear();        //để xóa nút giá trị cũ
    json.set("/Temp", t);  //set nút để lưu giá trị
    json.set("/Hum", h);  //set nút để lưu giá trị
    json.set("/Day", day);  //set nút để lưu giá trị
    Firebase.updateNode(firebaseData, "/Tray1", json);
    Firebase.updateNode(firebaseData, "/Tray2", json);
    Firebase.updateNode(firebaseData, "/Tray3", json);
    Firebase.updateNode(firebaseData, "/Tray4", json);

    myTime = millis();
  }

}