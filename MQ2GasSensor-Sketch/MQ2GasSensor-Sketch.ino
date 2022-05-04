float sensorValue; //Float-Variable um vom Sensor ermittelten Wert zu speichern

void setup(){
  Serial.begin(9600); 
  delay(30000); //Sensor aufheizen um Luftfeuchte bei Messung als Ungenauigkeit zu eliminieren 
}

void loop() {
  sensorValue = analogRead(0); //Lesen analog den Wert des Sensors aus 
  Serial.print("Sensor Value: "); Serial.print(sensorValue); //Gebe Werte aus
  if(sensorValue > 200) { //wenn Wert größer 100 Warnung ausgeben 
    Serial.print("  Gas detected!"); 
    Serial.println("");
  }
  delay(2000); //2 Sekunden warten bevor der nächste Wert gelesen wird
}
