#include <DHT.h> //Bibliothek für DHT22
#include <Adafruit_Sensor.h> //Allgemeine Adafruitbibliothek für Sensoren


#define DHTPIN 2           //Digitalpin 2 für DHT22
#define DHTTYPE DHT22      //Sensortyp als DHT22 festgelegt 
DHT dht(DHTPIN, DHTTYPE);  //Objekt zum Zugriff auf den DHT

void setup() {
  Serial.begin(9600); //Serielle Kommunikation wird auf 9600 Baud eingestellt
  dht.begin(); //DHT22 wird gestartet 
  delay(3000);
}

void loop(){  
  float dhtHumidity = dht.readHumidity();  //Feuchtigkeitswert mit DHT22 auslesen
  float dhtTemperature = dht.readTemperature(); //Temperaturwert mit DHT22 auslesen
 
  //Ausgabe der gemessenen Temperatur und Feuchtigkeitswerte
  Serial.println(dhtHumidity); 
  Serial.println(dhtTemperature);
  
  delay(2000); //nächte Messung nach 2 Sekunden
}
