          //UNIVERSIDAD TÉCNICA DEL NORTE
                 //FICA/CIERCOM
            //SISTEMAS MICROPROCESADOS
    
//NOMBRE: LUIS SUAREZ
//FECHA:  16/07/2019

#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

int horas;
int minutos;
int horero;
int minutero;
int segundero; 
int on = 0;
int funcion=0;
String hor;
String minut;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, sistema, FALLING);
  attachInterrupt(1, alarma, FALLING);
  lcd.begin(16, 2); 
  MsTimer2::set(100, reloj);
  MsTimer2::start();
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  horas = EEPROM.read(3);
  minutos = EEPROM.read(4);
  Serial.println("Sistema de Reloj");
}

void loop() {
  if (funcion == 1) {
    if (Serial.available() > 0) {
      hor = Serial.readString();
      horas = hor.toInt();
      EEPROM.update(3,horas);
    }
  }
  if (funcion == 0) {
    if (Serial.available() > 0) {
      minut = Serial.readString();
      minutos = minut.toInt();
      EEPROM.update(4,minutos);
    }
  }
  if (on == 1) {
    if ((horero == horas) && (minutero == minutos)) {
      digitalWrite (7,HIGH);
      digitalWrite (8,HIGH);
      delay (1000);
    } else {
      digitalWrite (7,LOW);
      digitalWrite (8,LOW);
    }
  }
  if (on == 0) {
    digitalWrite (7,LOW);
    digitalWrite (8,LOW);
  }
}

void reloj() {
  if (segundero < 10) {
    lcd.clear();
    lcd.setCursor(11, 0);
    lcd.print("0");
    lcd.setCursor(12, 0);
    lcd.print(segundero);
    Serial.print(segundero);
    Serial.println(" ");
  } else {
    lcd.clear();
    lcd.setCursor(10, 0);
    lcd.print(':');
    lcd.setCursor(11, 0);
    lcd.print(segundero);
    Serial.print(segundero);
    Serial.println(" ");
  }
  if (minutero < 10) {
    lcd.setCursor(7, 0);
    lcd.print(':');
    lcd.setCursor(8, 0);
    lcd.print("0");
    lcd.setCursor(9, 0);
    lcd.print(minutero);
    lcd.setCursor(10, 0);
    lcd.print(':');
    Serial.print(minutero);
    Serial.print(':');
  } else {
    lcd.setCursor(7, 0);
    lcd.print(':');
    lcd.setCursor(8, 0);
    lcd.print(minutero);
    lcd.setCursor(10, 0);
    lcd.print(':');
    Serial.print(minutero);
    Serial.print(':');
  }
  if (horero < 10) {
    lcd.setCursor(5, 0);
    lcd.print("0");
    lcd.setCursor(6, 0);
    lcd.print(horero);
    lcd.setCursor(7, 0);
    Serial.print(horero);
    Serial.print(':');    

  } else {
    lcd.setCursor(5, 0);
    lcd.print(horero);
    lcd.setCursor(7, 0);
    Serial.print(horero);
    Serial.print(':');
  }
}

void alarma() {
  on = 1-on;
  if (on==1) {
    Serial.println("ALARMA ON");
  } else if (on==0) {
    Serial.println("ALARMA OFF");
  }
}

void almacenar() {
  if (segundero < 3){
    segundero++;
    almacenar();
    EEPROM.write(0, segundero);
  }
  else {
    segundero = 0;
    if (minutero < 3){
      minutero++;
      almacenar();
      EEPROM.write(1, minutero);
    }
    else {
      minutero = 0;
      if (horero < 1){
        horero++;
        almacenar();
        EEPROM.write(2, horero);
      }
      else {
        horero = 0;
        almacenar();
      }
    }
  }
}
