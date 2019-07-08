          //UNIVERSIDAD TÉCNICA DEL NORTE
                 //FICA/CIERCOM
            //SISTEMAS MICROPROCESADOS
    
//NOMBRE: LUIS SUAREZ
//FECHA:  07/07/2019

#include <TimerOne.h>
int habitacion1 = 5;
int habitacion2 = 6;
int habitacion3 = 7;
int habitacion4 = 8;
int habitacion5 = 9;
int c;
int x=0;
int estado=0;
char clave[5];

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, programa, LOW);
  pinMode(habitacion1, OUTPUT);
  pinMode(habitacion2, OUTPUT);
  pinMode(habitacion3, OUTPUT);
  pinMode(habitacion4, OUTPUT);
  pinMode(habitacion5, OUTPUT);
  Serial.println("Bienvenidos al programa de seguridad domotica");
  Serial.println("Ingrese Clave para encender el sistema");
  delay(800);
}

void loop() {
}

void programa() {
  Serial.println("Ingrese Clave");
  delay (200);
x = 0;
if (Serial.available() > 0)
{
  if (c <= 5)
  {
    clave[c] = Serial.read();
    c++;
  }
  if (c == 5)
  {
    if ((clave[0] == '1') && (clave[1] == '2') && (clave[2] == '3') && (clave[3] == '4') && (clave[4] == '5'))
    {
      estado = 1;
      Serial.println("Clave Correcta");
      c = 0;
    }
    else if (c == 5)
    {
      estado = 0;
      c = 0;
      x = 0;
      Serial.println("Clave Incorrecta");
    }
  }
}
if (estado == 1)
{
digitalWrite(habitacion1,HIGH);
digitalWrite(habitacion2,LOW);
digitalWrite(habitacion3,HIGH);
digitalWrite(habitacion4,LOW);
digitalWrite(habitacion5,HIGH);
}
if (estado == 0)
{
digitalWrite(habitacion1,LOW);
digitalWrite(habitacion2,LOW);
digitalWrite(habitacion3,LOW);
digitalWrite(habitacion4,LOW);
digitalWrite(habitacion5,LOW);
}

int on = 1 - on;
if (on == 1)
  Timer1.stop();
else
  Timer1.start();
}
