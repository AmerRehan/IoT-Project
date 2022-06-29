#include<ThingSpeak.h>
#include<ESP8266WiFi.h>

int raw_Value = A0;
char* ssid = "SIEMENS";   // wifi name
char* pass = "$i#m#n$@CAM";  // wifi pass
WiFiClient client;
long id = 1781919;       // channel id
char* api = "AISG2KW6EGONWHML";   // write api key
char ip[] = "184.106.153.149";

void setup() {
  
  Serial.begin(9600);
  pinMode(raw_Value, INPUT);
  Serial.println("Connecting to Wifi");
  WiFi.begin(ssid,pass);
  
  while(WiFi.status()!=WL_CONNECTED){
    
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  
  raw_Value = A0;
  
  if(client.connect(ip,80)){
    Serial.print(raw_Value);
    ThingSpeak.setField(1,raw_Value);
    ThingSpeak.writeFields(id,api);
    }
  delay(500);
}
