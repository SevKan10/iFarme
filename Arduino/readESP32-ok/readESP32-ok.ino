// ESP32
String data, tem;
String k1="",k2="";
int e1=0, e2=0;
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  while (!Serial) {;}
  while (!Serial2) {;}
}

void loop() {
  Rece(); 
  Send();
}

void Rece()
{
   String read;
 while(Serial2.available() > 0) 
  { read = Serial2.readString(); 
    data += String(read);
    tem = data;
    //Serial.println(data);
     data="";
  }
  for (int i=0;i<=tem.length();i++){
    if (tem[i]=='*'){
      e1=1;
    }
   else if (tem[i]=='#'){
      e2=1;e1=0;
    }
    else{
      if(e1==1){
        k1+=tem[i];
      }
      if(e2==1){
        k2+=tem[i];
      }
    }
  }
  Serial.print(k1);
  Serial.print("\t");
  Serial.println(k2);
}
void Send() // giữ nguyên
{ String read;
 while(Serial.available() > 0)
  { read = Serial.readString(); 
    data += String(read);
    Serial2.print(data); data="";
  }
}
