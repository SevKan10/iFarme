#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "D87Btza8MgiifClqiT3fL7DdQ3rtO8cVQqRKY6BY"
#define WIFI_SSID "MINH KHA"
#define WIFI_PASSWORD "0855508877"

FirebaseData firebaseData;
FirebaseJson json;
int Vrdata = 0;

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

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.
  
  Firebase.enableClassicRequest(firebaseData, true);
  */

  //String path = "/data";


  Serial.println("------------------------------------");
  Serial.println("Connected...");
}

void loop() {

  int Sdata = random(10, 100);
  Serial.println(Sdata);
  delay(100);

  json.clear();//để xóa nút giá trị cũ
  json.set("/value", Sdata);
  Firebase.updateNode(firebaseData, "/test", json);

  int Xdata = random(0, 50);
  Serial.println(Xdata);
  delay(100);

  json.clear();//để xóa nút giá trị cũ 
  json.set("/value1", Xdata);//set nút để lưu giá trị
  Firebase.updateNode(firebaseData, "/test1", json);
}