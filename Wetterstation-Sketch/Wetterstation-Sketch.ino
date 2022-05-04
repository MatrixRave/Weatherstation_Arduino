#include <DHT.h> //include der Bibliothek für den DHT22
#include <Adafruit_Sensor.h> //include der Adafruit-Bibliothek für verschiedene Sensoren
#define DHTPIN 2  //definieren des Digitalpins an den der DHT22 angeschlossen ist 
#define DHTTYPE DHT22 //definieren des Typs des DHT Sensors
#define LSPIN 4 //definieren des Digitalpins des Lichtsensors

/*Definition der einzelnen Variablen in denen die Werte der einzelnen Sensoren abgelegt werden.
Gleichzeitig Definition eines DHT-Objekts, für den Zugriff auf den DHT22 Sensor*/
float mq2Value; 
float hygrometerValue; 
float lsValue; 
float dhtHumidity;
float dhtTemperature; 
float airPressure; 
DHT dht(DHTPIN, DHTTYPE); 

/*Setup aller Sensoren, im speziellen des DHT22. Der Delay liegt bei 30Sekunden um den MQ2-Sensor
aufheizen zu können, um eventuelle Messungenauigkleiten durch Luftfeuchtigkeit zu vermeiden*/
void setup() { 
  Serial.begin(9600);
  dht.begin(); 
  delay(30000); 
}

/*Messschleife: Werte aller Sensoren werden ausgelesen und seriell ausgegeben, um ebenfalls 
seriell auf dem ESP8266 gelesen werden zu können und dort weiter zu verarbeiten.*/
void loop() {

  dhtHumidity = dht.readHumidity(); 
  dhtTemperature = dht.readTemperature(); 

  Serial.print(dhtHumidity);
  Serial.print(dhtTemperature);

  hygrometerValue = analogRead(A1); 
  Serial.println(hygrometerValue); 


  lsValue = digitalRead(LSPIN); 
  Serial.println(lsValue);  

  mq2Value = analogRead(0); 
  Serial.println(mq2Value); 
  
  delay(2000); 
}
