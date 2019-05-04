                          //UNIVERSIDAD TÉCNICA DEL NORTE 
                                 //FICA/CIERCOM
                            //SISTEMAS MICROPROCESADOS 

//NOMBRE: LUIS SUAREZ 
//FECHA:  04/05/2019

//Puertos con entrada de datos digitales
//Declaración de variables
int b1 = 24;
int b2 = 32;
int b3 = 40;
int on = 0;
int cont = 0;
int A = 25;
int B = 26;
int C = 27;
int D = 28;
int E = 33;
int F = 34;
int G = 35;
int H = 36;
int I = 41;
int J = 42;
int K = 43;
int L = 44;
int decenas;
int unidades;
int decenas1;
int unidades1;
int decenas2;
int unidades2;
int dec = 22;
int uni = 23;
int dec1 = 30;
int uni1 = 31;
int dec2 = 38;
int uni2 = 39;
int on1 = 0;
int cont1 = 0;
int on2 = 0;
int cont2 = 0;
void setup() {
  pinMode(b1, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(uni, OUTPUT);
  pinMode(b2, INPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(dec1, OUTPUT);
  pinMode(uni1, OUTPUT);
  pinMode(b3, INPUT);
  pinMode(I, OUTPUT);
  pinMode(J, OUTPUT);
  pinMode(K, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(dec2, OUTPUT);
  pinMode(uni2, OUTPUT);
}

void loop() {
  //Funcionamiento del botón 1
  if (digitalRead(b1) == LOW)
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    on = 1 - on;
    if (cont < 25)
      cont++;
    else
      cont = 0;

  }
  
 decenas = cont / 10;
  unidades = cont - decenas * 10;
  digitalWrite(dec, HIGH);
  digitalWrite(uni, LOW);
  contador(decenas);
  delay(50);
  digitalWrite(dec, LOW);
  digitalWrite(uni, HIGH);
  contador(unidades);
  delay(50);

  //Funcionamiento del botón 2
  if (digitalRead(b2) == LOW)
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    on1 = 1 - on1;
    if (cont1 < 25)
      cont1++;
    else
      cont1 = 0;
  }
  decenas1 = cont1 / 10;
  unidades1 = cont1 - decenas1* 10;
  digitalWrite(dec1, HIGH);
  digitalWrite(uni1, LOW);
  contador1(decenas1);
  delay(50);
  digitalWrite(dec1, LOW);
  digitalWrite(uni1, HIGH);
  contador1(unidades1);
  delay(50);

  //Funcionamiento del botón 3 SUMA
  if (digitalRead(b3) == LOW)
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    on2 = 1 - on2;
    if (cont2 < 50)
      cont2= cont + cont1; //Proceso de suma 
    else
      cont2 = 0;
  }
  
 decenas2 = cont2 / 10;
  unidades2 = cont2 - decenas2 * 10;
  digitalWrite(dec2, HIGH);
  digitalWrite(uni2, LOW);
  contador2(decenas2);
  delay(50);
  digitalWrite(dec2, LOW);
  digitalWrite(uni2, HIGH);
  contador2(unidades2);
  delay(50);
}
void contador (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }}
  
 void contador1 (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      break;
    case 1:
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      break;
    case 2:
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      break;
    case 3:
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      break;
    case 4:
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      break;
    case 5:
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      break;
    case 6:
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      break;
    case 7:
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      break;
    case 8:
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(H, HIGH);
      break;
    case 9:
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(H, HIGH);
      break;
  }
}

void contador2 (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(I, LOW);
      digitalWrite(J, LOW);
      digitalWrite(K, LOW);
      digitalWrite(L, LOW);
      break;
    case 1:
      digitalWrite(I, HIGH);
      digitalWrite(J, LOW);
      digitalWrite(K, LOW);
      digitalWrite(L, LOW);
      break;
    case 2:
      digitalWrite(I, LOW);
      digitalWrite(J, HIGH);
      digitalWrite(K, LOW);
      digitalWrite(L, LOW);
      break;
    case 3:
      digitalWrite(I, HIGH);
      digitalWrite(J, HIGH);
      digitalWrite(K, LOW);
      digitalWrite(L, LOW);
      break;
    case 4:
      digitalWrite(I, LOW);
      digitalWrite(J, LOW);
      digitalWrite(K, HIGH);
      digitalWrite(L, LOW);
      break;
    case 5:
      digitalWrite(I, HIGH);
      digitalWrite(J, LOW);
      digitalWrite(K, HIGH);
      digitalWrite(L, LOW);
      break;
    case 6:
      digitalWrite(I, LOW);
      digitalWrite(J, HIGH);
      digitalWrite(K, HIGH);
      digitalWrite(L, LOW);
      break;
    case 7:
      digitalWrite(I, HIGH);
      digitalWrite(J, HIGH);
      digitalWrite(K, HIGH);
      digitalWrite(L, LOW);
      break;
    case 8:
      digitalWrite(I, LOW);
      digitalWrite(J, LOW);
      digitalWrite(K, LOW);
      digitalWrite(L, HIGH);
      break;
    case 9:
      digitalWrite(I, HIGH);
      digitalWrite(J, LOW);
      digitalWrite(K, LOW);
      digitalWrite(L, HIGH);
      break;
  }}
