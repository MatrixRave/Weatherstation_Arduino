#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const String ssid = "congstar.home_C591_2.4G"; 
const String password = "01036501"; 

const char* server = "http://3.16.78.33:5000/wsdata"; 

unsigned long last_time = 0;
unsigned long timer_delay = 10000;
float temperatur;
float humidity;
float airPressure;
float soilHumidity; 
float gasValue;
float lightValue; 
WiFiClient wifiClient;

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WIFI…");
  while(WiFi.status() != WL_CONNECTED) {
  delay(500); 
  Serial.println("."); 
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
 if (Serial.available()>0) {
  
  humiditiy = Serial.parseFloat(); 
  temperature = Serial.parseFloat(); 
  airPressure = Serial.parseFloat(); 
  soilHumidity = Serial.parseFloat(); 
  gasValue = Serial.parseFloat(); 
  lightValue = Serial.parseFloat();
  
  if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
   
      http.begin(wifiClient,server);

      http.addHeader("Content-Type", "application/json");
      String httpRequestData = "{\"temperature\":";
      httpRequestData.concat(temperature);
      httpRequestData.concat(",");
      httpRequestData.concat("\"humidity\":");
      httpRequestData.concat(humidity); 
      httpRequestData.concat("}");   
      http.POST(httpRequestData);
      http.end();

      delay(2000); 
  }
 }
}
