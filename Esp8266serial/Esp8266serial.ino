void setup() {
  Serial.begin(9600); // Serielles Interface wird mit Baudrate von 9600 Baud initialisiert
  delay(30000); //Delay von 3 Sekunden um lesen zeitgleich mit Datenerhebung zu beginnen 
 }

//Endlosschleife zum auslesen der Daten
void loop() {  
  if(Serial.available()>0)    //Prüft den Buffer auf Daten  
  {
    Serial.write(Serial.read());  //Liest die seriellen Daten und schreibt den Bytestrom als ASCII-Zeichen aus
  }
  else
  {
    Serial.println("Could not receive Data"); // Wenn keine Daten empfangen werden wird Fehlermeldung ausgegeben
    delay(2200);                      // mache 2 Sekunden Pause 
  }
}
