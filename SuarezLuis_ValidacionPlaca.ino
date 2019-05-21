                          //UNIVERSIDAD TÉCNICA DEL NORTE 
                                 //FICA/CIERCOM
                            //SISTEMAS MICROPROCESADOS 

//NOMBRE: LUIS SUAREZ 
//FECHA:  19/05/2019

const int boton = 11;
int pulsador;
int x=0;
String placa_auto;
String dig_letras;
String dig_numeros;
String lugar;

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
  Serial.println("Ingrese la placa en el formato ABC-0123");
  delay (200);
   }
    x=0;
  if (Serial.available() > 0) {
    placa_auto = 'ABC-0123';
    placa_auto = Serial.readString();
    if (placa_auto.length() == 8) {
    dig_letras = placa_auto.substring(0, placa_auto.indexOf("-"));
    dig_numeros = placa_auto.substring(placa_auto.indexOf("-")+1, placa_auto.length());   
    placa_auto = dig_letras + ("-") + dig_numeros;
      if ((dig_letras >= "A" && dig_letras <= "Z") && (dig_numeros >= "0" && dig_numeros <= "9" )) {
        lugar = dig_letras.substring(0, 1);
        if (( lugar == "A" || lugar == "B" || lugar == "C" || lugar == "E" || lugar == "G" || lugar == "H" || lugar == "I" || lugar == "J"|| lugar == "K" || lugar == "L" || lugar == "M" || lugar == "N" || lugar == "O" || lugar == "P" || lugar == "Q" || lugar == "R" || lugar == "S" || lugar == "T" || lugar == "U" || lugar == "V" || lugar == "W" || lugar == "X" || lugar == "Y" || lugar == "Z" ) )
        {
       if(lugar){ 
            if (lugar == "A") {
              Serial.println("");
              Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Azuay");
              Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "B") {
              Serial.println("");
              Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Bolívar");
              Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "C") {
              Serial.println("");
              Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Carchi");
              Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "E") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Esmeraldas");
               Serial.println (" Ingrese una nueva placa para validar");
            }  
            if (lugar == "G") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Guayas");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "H") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Chimborazo");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "I") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Imbabura");
               Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "J") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Santo Domingo de los Tsáchilas");
               Serial.println (" Ingrese una nueva placa para validar");
            }  
            if (lugar == "K") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Sucumbíos");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "L") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Loja");
               Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "M") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Manabí");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "N") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Napo");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "O") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de El Oro");
               Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "P") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Pichincha");
               Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "Q") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Orellana");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "R") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Los Ríos");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "S") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Pastaza");
               Serial.println (" Ingrese una nueva placa para validar");
            } 
            if (lugar == "T") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Tungurahua");
               Serial.println (" Ingrese una nueva placa para validar");
            }  
            if (lugar == "U") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Cañar");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "V") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Morona Santiago");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "W") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Galápagos");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "X") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Cotopaxi");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "Y") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Santa Elena");
               Serial.println (" Ingrese una nueva placa para validar");
            }
            if (lugar == "Z") {
               Serial.println("");
               Serial.println (" La placa: " + placa_auto + " pertenece a la provincia de Zamora Chinchipe");
               Serial.println (" Ingrese una nueva placa para validar");
            }                                                                                         
          }                                      
        }
        else {
          Serial.println("");
          Serial.println (" La placa ingresada es incorrecta");
          Serial.println (" La placa no pertenece a ninguna provincia");
        }
      }
    }
  }
}
