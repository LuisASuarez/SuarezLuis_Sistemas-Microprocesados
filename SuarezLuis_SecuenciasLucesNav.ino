int contador=9;
int i=0;
int j=0;
int z=0;
int ante=0;
int leds []={2,3,4,5,6,7,8,9};
 
void setup() {
  
for (;i<contador;i++){
pinMode(leds[i],OUTPUT);
}
i=0;

}



void loop() {

//Ejercicio 1: En este ejercicio se prenden las luces de las posiciones Pares
for(i=6;i>=0;i=i-2){
  digitalWrite(leds[i],HIGH);
  delay(200);
  digitalWrite(leds[i],LOW);  
  delay(200);
}

//Ejercicio 2: En este ejercicio se prenden las luces de las posiciones Impares
for(i=7;i>=0;i=i-2){
  digitalWrite(leds[i],HIGH);
  delay(200);
  digitalWrite(leds[i],LOW);  
  delay(200);
}

//Ejercicio 3: En este ejercicio se prenden las luces de manera ascendente 
 
  for(i=j;i<contador;i++){
  digitalWrite(leds[i],HIGH);
  delay(100);
  digitalWrite(leds[i],LOW);  
  delay(100);
  
}
//Ejercicio 4: En este ejercicio se prenden las luces de manera ascendente y luego descendente
 
  for(int w=0;w<contador;w++){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}
for(int w=contador-1;w>=0;w--){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}
  for(int w=0;w<contador;w++){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}
for(int w=contador-1;w>=0;w--){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}

//Ejercicio 5: En este ejercicio se prenden las luces de manera ascendente de tres en tres y luego descendente se apagan una por una

for(z=0;z<contador;z++){
    ante=z-2;
  digitalWrite(leds[z],HIGH);
  delay(50);
  digitalWrite(leds[ante],LOW); 
}
for(z=contador-1;z>=0;z--){
    ante=z;
  digitalWrite(leds[z],HIGH);
  delay(50);
  digitalWrite(leds[ante],LOW); 
}
for(i=0;i<8;i++){
  digitalWrite(leds[i],HIGH);
  digitalWrite(leds[7-i],HIGH);
  delay(500);
  digitalWrite(leds[i],LOW);  
  digitalWrite(leds[7-i],LOW); 
  delay(500);
}
}
