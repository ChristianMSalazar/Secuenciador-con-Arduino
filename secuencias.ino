//SECUENCIADOR LED PARA ARBOL DE NAVIDAD CON ARDUINO
int saltar=0; // Variable que indica el numero de la secuencia a ejecutarse
int pausa=200;
void setup(){
  for(int i=2;i<=9;i++){ //indicamos los pines de salida
    pinMode(i,OUTPUT);
    pinMode(10,INPUT); //indicamos el pin de entrada
    }
}
void loop(){
  if(digitalRead(10)==HIGH){ //Al presionar el pulsador
    saltar++; // Cambia de secuencia
    if(saltar>5){ //Solo hay 5 secuencias 0,1,2,3 y 4 al ser 4 . .
      saltar=0; // Vuelve a secuencia 0
      }
      while (digitalRead(10)==HIGH){} // Mientras se pulsa no haga nada mas
      }
      if(saltar==0){ //Si es 0 inicie funcion de efecto1
        efecto1();
        }
        if(saltar==1){ //Si es 1 inicie funcion de efecto2
          efecto2();
          }
          if(saltar==2){ //Si es 2 inicie funcion de efecto3
            efecto3();
            }
            if(saltar==3){ //Si es 3 inicie funcion de efecto4
              efecto4();
              }
              if(saltar==4){ //Si es 4 inicie funcion de efecto5
                efecto5();
                }
                if(saltar==5){ //Si es 5 inicie funcion de efecto5
                  efecto6();
                  }
}
void efecto1(void){
  for(int i=2;i<=9;i++){
      digitalWrite(i,HIGH);
      delay(100);
      }
      for(int i=2;i<=9;i++){
        digitalWrite(i,LOW);
        delay(100);
        }
}
void efecto2(void){
  for(int i=2;i<=9;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    }
}
void efecto3(void){
  for(int i=2; i<=9; i++){ //Pin 2 al 9
    digitalWrite(i, HIGH); // Prenda pin actual
    digitalWrite(i-1,LOW); // Apage el Anterior
    delay(100); // retardo entre prender y apagar
    }
    for (int i=9; i>=2; i--){ //Al contrario de la
      digitalWrite(i, LOW); // anterior secuencia va de 9 a 2
      digitalWrite(i-1,HIGH);
      delay(100);
      }
}
void efecto4(void){
  int k=11; // inicializo una variable auxiliar 
  for(int i=6; i<=9;i++){ //leo de 6 a 9
    digitalWrite(i, HIGH); // prendo pin actual
    digitalWrite(k-i, HIGH); // prendo pin de la diferencia 11-6 = 5
    delay(100); //retardo
    }
    for(int i=9; i>=2;i--){ // Al contrario de lo anterior
      digitalWrite(i, LOW);
      digitalWrite(k-i, LOW);
      delay(100);
      }
}
void efecto5(void){
  int k=11;
  for(int i=2; i<=5;i++){
    digitalWrite(i,HIGH);
    digitalWrite(k-i,LOW);
    }
    delay(150);
    for(int i=2; i<=5;i++){
      digitalWrite(i,LOW);
      digitalWrite(k-i,HIGH);
      }
      delay(150);
}
void efecto6(void){
  //encendemos y apagamos los leds desde los extremos
  //2____________9
  //  3_________8
  //    4_____7
  //      5_6
int step=3;
 for(int pinLed=2;pinLed<10;pinLed++){
  //pone el LED en high
  digitalWrite(pinLed,HIGH);
  digitalWrite(pinLed+2*step+1,HIGH);
  delay(pausa);
  //pone el LED en LOW
  digitalWrite(pinLed,LOW);
  digitalWrite(pinLed+2*step+1,LOW);
  delay(pausa);
  step--;
  }
}
