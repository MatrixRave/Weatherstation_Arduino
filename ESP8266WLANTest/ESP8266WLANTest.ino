#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const String ssid = "congstar.home_C591_2.4G"; 
const String password = "01036501"; 

// Domain Name with full URL Path for HTTP POST Request
const char* server = "http://api.thingspeak.com/update";

String my_Api_key = "EnterYourApiKey";


unsigned long last_time = 0;
unsigned long timer_delay = 10000;
WiFiClient wifiClient;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WIFI…");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("After 10 seconds the first reading will be displayed");

  //initialize a random number 
  randomSeed(analogRead(23));
}

void loop() {
  //Send an HTTP POST request every 10 seconds
  if ((millis()-last_time) > timer_delay) {
 
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
   
      http.begin(wifiClient,server);
      
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      // Data to send with HTTP POST
      String httpRequestData = "api_key=" + my_Api_key + "&field1=" + String(random(50));           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      
      /*
      
      http.addHeader("Content-Type", "application/json");
      // JSON data to send with HTTP POST
      String httpRequestData = "{\"api_key\":\"" + my_Api_Key + "\",\"field1\":\"" + String(random(50)) + "\"}";           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);*/
     
      Serial.print("HTTP Response code is: ");
      Serial.println(httpResponseCode);
      http.end();
    }
    else {
      Serial.println("WiFi is Disconnected!");
    }
    last_time = millis();
  }
}
