                          //UNIVERSIDAD TÉCNICA DEL NORTE 
                                 //FICA/CIERCOM
                            //SISTEMAS MICROPROCESADOS 

//NOMBRE: LUIS SUAREZ 
//FECHA:  31/07/2019

#include<avr/power.h>
#include<avr/sleep.h>
#include <TimerOne.h>
#include<avr/wdt.h>
#include<EEPROM.h>
int dato;
int valor;
void on(void);

void setup() {
  dato=EEPROM.read(0);
  Serial.begin(9600);
  Serial.println("MODO SLEEP DORMIDO");
  if(dato==0){
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0,1);
    wdt_enable(WDTO_2S);
  }
  else{
    sleep_disable();
    EEPROM.write(0,0);
    wdt_enable(WDTO_1S);
    
  }

  set_sleep_mode(SLEEP_MODE_STANDBY);
  sleep_enable();
  Timer1.initialize(3000000);
  delay(10);
}

void loop() {
  valor=analogRead(A0);
  if (dato == LOW) {
    Serial.println("Me dormi :|");
    delay(2000);
    sleep_mode();    
  } else {
    Serial.println("Me desperte :|");
    EEPROM.write(0,255);
    valor = 255*(analogRead(A0)/1023);
    valor=EEPROM.read(0);
    Serial.print("Valor:");
    Serial.println(valor);
    delay(2000);
}}
