#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const String ssid = "congstar.home_C591_2.4G"; 
const String password = "01036501"; 
const char* host = "postman-echo.com"; //edit the host adress, ip address etc. 
String url = "/post/"; int adcvalue=0; 

void setup() { 
  Serial.begin(115200); 
  delay(10000); 
  Serial.println(); 
  Serial.println(); Serial.println("Connecting to: "); 
  Serial.println(ssid); 
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) 
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println(""); 
Serial.println("WiFi connected"); 
Serial.println("IP address: "); 
Serial.println(WiFi.localIP());
int value = 0; 
}

void loop() { }
