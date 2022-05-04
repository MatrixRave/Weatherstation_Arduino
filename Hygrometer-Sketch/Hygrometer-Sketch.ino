float sensorValue; //Variable um den vom Sensor ausgelesenen Wert zu speichern

void setup() {
  Serial.begin(9600);
  delay(2000); 
}

void loop() {
  sensorValue = analogRead(A1); //Wert wird am Analog-Pin A1 ausgelesen und in der Variable 
  Serial.println(sensorValue); 
  delay(2000);
}
