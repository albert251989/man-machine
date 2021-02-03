int option;
int led = 13;
int aroma = 11;
int val=25;
int led25=14;

#include <OneWire.h>                
#include <DallasTemperature.h>

OneWire ourWire(12);                //Se establece el pin 12  como bus OneWire 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

void setup() {
   Serial.begin(9600);
   pinMode(led, OUTPUT);
   pinMode(aroma, OUTPUT);
   digitalWrite(led, HIGH);
   digitalWrite(aroma, HIGH);
   sensors.begin();   //Se inicia el sensor
  

}

void loop() {
     
    //si existe datos disponibles los leemos
  if (Serial.available()>0){
        //leemos la opcion enviada
        option=Serial.read();
        if(option=='A') {
          digitalWrite(led, LOW);
         
        }
        if(option=='B') {
          digitalWrite(led, HIGH);
            }

        if(option=='D') {
          digitalWrite(led, HIGH);
         
        }
        if(option=='E') {
          digitalWrite(led, LOW);
            }

        if(option=='F') { //activa el aromaterapia
          digitalWrite(aroma, LOW);
          delay(500);
          digitalWrite(aroma, HIGH);
            }
    
        if(option=='C') {
          sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
          int temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
          
          Serial.print("n0.val=");
          Serial.print(temp);
          Serial.write(0xff);
          Serial.write(0xff);
          Serial.write(0xff);
          delay(100);
        }

    
  }

}
