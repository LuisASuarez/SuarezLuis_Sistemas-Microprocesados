                          //UNIVERSIDAD TÉCNICA DEL NORTE 
                                 //FICA/CIERCOM
                            //SISTEMAS MICROPROCESADOS 

//NOMBRE: LUIS SUAREZ 
//FECHA:  16/06/2019

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
int d=0;
Servo motor;
LiquidCrystal lcd(12,11,5,4,3,2);
const byte filas = 4; 
const byte columnas = 3; 
char keys[filas][columnas] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'#','0','*'}
};
int j =0;
char clave[5];
byte filPins[filas] = {A0, A1, A2, A3}; 
byte colPins[columnas] = {10, 9, 8}; 
Keypad keypad= Keypad( makeKeymap(keys), filPins, colPins, filas, columnas );
int i=0;
int sis;

void setup()
{
Serial.begin(9600);
pinMode(9,OUTPUT);
lcd.begin(16,2);
lcd.print("Bienvenido");
Serial.println("Bienvenido");
Serial.println("Ingrese Clave");
delay(800);
}

void loop()
{
if(d==0)  
{
lcd.setCursor(0,0);
lcd.print("Ingrese Clave");
}
if(d==1)  
{
lcd.setCursor(0,0);
lcd.print("Sistema ON");
}
char key = keypad.getKey();

if (key != NO_KEY)
{
  
switch(j)
{ 
case 0:
clave[j]=key;
Serial.println(clave[j]);
lcd.setCursor(i,1);
lcd.print(clave[j]);
delay(800);
lcd.setCursor(i,1);
lcd.print('*');
j++;
i++;
break;

case 1:
clave[j]=key;
Serial.println(clave[j]);
lcd.setCursor(i,1);
lcd.print(clave[j]);
delay(800);
lcd.setCursor(i,1);
lcd.print('*');
j++;
i++;
break;

case 2:
clave[j]=key;
Serial.println(clave[j]);
lcd.setCursor(i,1);
lcd.print(clave[j]);
delay(800);
lcd.setCursor(i,1);
lcd.print('*');
j++;
i++;
break;

case 3:
clave[j]=key;
Serial.println(clave[j]);
lcd.setCursor(i,1);
lcd.print(clave[j]);
delay(800);
lcd.setCursor(i,1);
lcd.print('*');
delay(800);
j=0;
i=0;

if(clave[0]=='2'&&clave[1]=='4'&&clave[2]=='0'&&clave[3]=='1')
{
digitalWrite(9,HIGH);
Serial.println("Clave Correcta");
lcd.setCursor(0,1);
lcd.print("Clave Correcta");
delay(800);
lcd.clear();
sis=1;
d=1;
}
else
{
digitalWrite(9,LOW);
Serial.println("Clave Incorrecta");
lcd.setCursor(0,0);
lcd.print("Clave Incorrecta");
lcd.setCursor(0,1);
lcd.print("Sistema OFF");
delay(800);
lcd.clear();
sis=0;
d=0;
}
break;
}
}
}
