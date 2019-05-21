                          //UNIVERSIDAD TÉCNICA DEL NORTE 
                                 //FICA/CIERCOM
                            //SISTEMAS MICROPROCESADOS 

//NOMBRE: LUIS SUAREZ 
//FECHA:  19/05/2019

const int boton = 11;
int pulsador;
int x=0;
int digitoult;
int num_impar;
int num_par;
int num1;
int num3;
int num5;
int num7;
int num9;
int total;
int dig_1;
int decena;
int validacion;
String numero1;
String numero3;
String numero5;
String numero7;
String numero9;
String ced;
String pares;
String digitor;
String ult_dig;

void setup() {
  Serial.begin(9600);
  pinMode(boton,INPUT);
}

void loop() {
 pulsador=digitalRead(boton);
  if(pulsador==HIGH)
  {
    x=1-x;
  }
  if(x==1)
  {
  Serial.println("Ingrese la cedula en el formato XXXXXXXXX-X");
  delay (200);
   }
    x=0;
    
  if (Serial.available() > 0) {
    ced = '100375363-7';
    ced = Serial.readString();

  if (ced.length() == 11) {
      digitor = ced.substring(0, 2);

  if ( digitor.toInt() >= 1 && digitor.toInt() <= 24 ){
     ult_dig = ced.substring(ced.indexOf("-") + 1, ced.length());
     digitoult = ult_dig.toInt();
     pares = (ced.substring(1, 2)).toInt() + (ced.substring(3, 4)).toInt() + (ced.substring(5, 6)).toInt() + (ced.substring(7, 8)).toInt();
     num_par = pares.toInt();
     numero1 = ced.substring(0, 1);
     num1 = numero1.toInt();
     num1 = (num1 * 2);
  if ( num1 > 9 ) {
          num1 = (num1 - 9);
        }
        numero3 = ced.substring(2, 3);
        num3 = numero3.toInt();
        num3 = (num3 * 2);
  if ( num3 > 9 ) {
          num3 = (num3 - 9);
        }
        numero5 = ced.substring(4, 5);
        num5 = numero5.toInt();
        num5 = (num5 * 2);
  if ( num5 > 9 ) {
          num5 = (num5 - 9);
        }
        numero7 = ced.substring(6, 7);
        num7 = numero7.toInt();
        num7 = (num7 * 2);
  if ( num7 > 9 ) {
          num7 = (num7 - 9);
        }
        numero9 = ced.substring(8, 9);
        num9 = numero9.toInt();
        num9 = (num9 * 2);
  if ( num9 > 9 ) {
          num9 = (num9 - 9);
        }
        num_impar = num1 + num3 + num5 + num7 + num9;
        total = (num_par + num_impar);
        String primer_digito_suma = String(total).substring(0, 1);
        dig_1 = primer_digito_suma.toInt();
        decena = ((dig_1) + 1) * 10;
        validacion = decena - total;
        if (validacion == 10) {
          validacion = 0;
        }
        if (validacion == digitoult) {
          Serial.println("");
          Serial.println (" La cedula: " + ced + " es correcta ");
          Serial.println (" Ingrese un nuevo numero de cedula para validar ");
        } else {
          Serial.println("");
          Serial.println (" La cedula: " + ced + " es incorrecta ");
          Serial.println (" Ingrese un numero de cedula valido ");
        }
      } 
    }
    if (ced.length() < 10) {
    Serial.println("");
    Serial.println("La cedula ingresada tiene menos de 10 digitos");
    Serial.println("Ingrese nuevamente el numero de cedula");
    delay(300);
}
    if (ced.length() > 11) {
    Serial.println("");
    Serial.println("La cedula ingresada tiene mas de 10 digitos");
    Serial.println("Ingrese nuevamente el numero de cedula");
    delay(300);
   }

  }
}
