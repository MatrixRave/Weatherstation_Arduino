#define LSPin 4
int value; 

void setup() { 
  Serial.begin(9600); 
  delay(3000); 
}

void loop() { 
  value = digitalRead(LSPin); 
  Serial.println(value); 
  delay(2000); 
}
