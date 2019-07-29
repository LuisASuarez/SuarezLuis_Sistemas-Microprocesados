          //UNIVERSIDAD TÉCNICA DEL NORTE
                 //FICA/CIERCOM
            //SISTEMAS MICROPROCESADOS
    
//NOMBRE: LUIS SUAREZ
//FECHA:  28/07/2019

#include <avr/wdt.h> 
#include<EEPROM.h>
#include<MsTimer2.h>
#include<TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
int segundero;
int minutero;
int horero;
int i = 0;
int seg = 50;
int minu = 10;
int hor = 0;


void setup()
{
  Serial.begin(9600);
  lcd.begin (16, 2);
  MsTimer2::set(500, reloj);
  MsTimer2::start();
  Timer1.initialize(200000);
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  wdt_disable(); 
  wdt_enable(WDTO_4S);
}
 
void loop()
{
  wdt_reset(); 
  if (segundero < 60) {
      segundero++;
      lcd.setCursor(0, 0);
      lcd.print("Reloj:");
      lcd.setCursor(0, 1);
      lcd.print(horero);
      lcd.setCursor(3, 1);
      lcd.print(':');
      lcd.setCursor(4, 1);
      lcd.print(minutero);
      lcd.setCursor(6, 1);
      lcd.print(':');
      lcd.setCursor(7, 1);
      lcd.println(segundero);
    }
    else {
      segundero = 0;
      if (minutero < 60) {
        minutero++;
      }
      else {
        minutero = 0;
        if (horero < 12) {
          horero++;
        }
        else {
          horero = 0;
        }
      }
    }
    if (minutero == 10) {
      EEPROM.update(0, 1);
      if (segundero == 50 && EEPROM.read(0) == 1) { 
        EEPROM.update(2, 1); 
        if (EEPROM.read(0) == 1 && EEPROM.read(1) == 1) {
          EEPROM.update(0, 1);
          wdt_enable(WDTO_1S);
        }
      }
    }
}

void reloj() {
  if (segundero < 60) {
    segundero++;
    Serial.print(segundero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(horero);
    Serial.print(':');
  }
  else {
    segundero = 0;
    Serial.print(segundero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(horero);
    Serial.print(':');
    if (minutero < 60) {
      minutero++;
      Serial.print(segundero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.println(horero);
      Serial.print(':');

    }
    else {
      minutero = 0;
      Serial.print(segundero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.println(horero);
      Serial.print(':');
      if (horero < 12) {
        horero++;
        Serial.print(segundero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.println(horero);
        Serial.print(':');

      }
      else {
        horero = 0;
        Serial.print(segundero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.println(horero);
        Serial.print(':');
      }
    }
  }
}

void backup() {
  i++;
  if (i == 5) {
    Serial.println("backup");
    EEPROM.write(0, segundero);
    EEPROM.write(1, minutero);
    EEPROM.write(2, horero);
    i = 0;
  }
}

void reinicio() {

  if (seg == 50) {
    seg++;
    lcd.setCursor(0, 0);
    lcd.print(hora);
    lcd.print(":");
    lcd.setCursor(3, 0);
    lcd.print(minu);
    lcd.print(":");
    lcd.setCursor(6, 0);
    lcd.print(seg);
  }
  else {
    seg = 0;
    if (minu == 10) {
      minu++;
      lcd.setCursor(0, 0);
      lcd.print(hor);
      lcd.print(":");
      lcd.setCursor(3, 0);
      lcd.print(minu);
      lcd.print(":");
      lcd.setCursor(6, 0);
      lcd.print(seg);
    }
    else {
      minu = 0;

      if (hor < 12) {
        hor++;
        lcd.setCursor(0, 0);
        lcd.print(hor);
        lcd.print(":");
        lcd.setCursor(3, 0);
        lcd.print(minu);
        lcd.print(":");
        lcd.setCursor(6, 0);
        lcd.print(seg);
      }
      else {
        hor = 0;

      }
    }
  }
  reinicio();
}
