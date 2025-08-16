int inter=0;//contador de intersecciones
void setup() {
  motorSpeed(M1,97);//varian de 0 a 100
  motorSpeed(M2,97);
  lineCompare(J1,505);//numero sacado desde el ejemplo linetest2
  lineCompare(J2,457);
  lineCompare(J3,349);//pendiente por calibrar
  AbrirPinza();
}

void loop() {
  if(ultrasoundRead(J6)<=12){//valor depende de que tan cerca quiera la botella
    motorsOff(M2,M1);
    CerrarPinza();
    GirarDerecha();
    delay(500);//varia depende que tanto quiero girar a la derecha
    goForward(M1,M2);
    delay(700);//depende de que tanto quiero que vaya hacia adelante
    motorsOff(M2,M1);
    AbrirPinza();
    goReverse(M1,M2);
    delay(700);//tiempo para volver a la linea
    while(lineRead(J2)==BLACK){ //mientras no encuentra la linea gira a la izquierda, mirar que tan lejos estoy de la linea y cuadrar tiempos o calibrar sensores
      motorOn(M1,FORWARD);
      motorOn(M2,REVERSE);
    }
  }
  else{
    if(lineRead(J1)==BLACK && lineRead(J2)==BLACK){
      goForward(M1,M2);
    }
    if(lineRead(J1)==BLACK && lineRead(J2)==WHITE){
      GirarIzquierda();
    }
    if(lineRead(J1)==WHITE && lineRead(J2)==BLACK){
      GirarDerecha();
    }
    if(lineRead(J1)==WHITE && lineRead(J2)==WHITE){
      inter++;//suma uno a inter
      goForward(M1,M2);
      delay(200);
      if(inter==1){
        GirarDerecha_Interseccion();
      }
      if(inter==1 && ultrasoundRead(J6)<20){ //calibrar distancia
        while(ultrasoundRead(J6)>12){
          goForward(M1,M2);
        }
        CerrarPinza();
        goReverse(M1,M2);//reversar
        delay(750);//verificar tiempo
        motorsOff(M1,M2);
        delay(100);
        GirarIzquierda();
        delay(500);
        goForward(M1,M2);//ir para adelante
        delay(300);
        motorsOff(M1,M2);
        delay(100);
        AbrirPinza();
        goReverse(M1,M2);//reversar
        delay(300);
        GirarDerecha();
        delay(500);
        goForward(M1,M2);//ir para adelante
        delay(500);
        inter-1;
        while(lineRead(J1)==BLACK && lineRead(J2)==BLACK){ //reincorporacion a la linea
          goForward(M1,M2);
        }
      }
      if(inter==4){ //revisar intersecciones
        GirarIzquierda_Interseccion(); 
      }
      if(inter==4 && ultrasoundRead(J6) < 17){ //pendiente por calibrar
      while(ultrasoundRead(J5)>12){
        goForward(M1,M2);
       }
       CerrarPinza();
       goForward(M1,M2);//ir para adelante
       delay(800);
       AbrirPinza();
       goReverse(M1,M2);//reversar
       delay(800);
       motorsOff(M1,M2);
       inter-1;//restar 1 a inter
       }
      
      if(inter==6){
        GirarDerecha_Interseccion();
      }
      if(inter==7){
        GirarDerecha_Interseccion();
        }
      if(inter==8 && ultrasoundRead(J6)<=12){
       AbrirPinza();
       GirarIzquierda();
       delay(350);
       goForward(M1,M2);//ir para adelante
       delay(500);
       motorsOff(M1,M2);
       AbrirPinza();
       goReverse(M1,M2);//reversar
       delay(500);
       GirarDerecha();
       motorsOff(M1,M2); 
      
      if(inter==9){
       while(ultrasoundRead(J6)>12){
          goForward(M1,M2);
          motorSpeed(M1,100);
          motorSpeed(M2,100);
        }
        motorsOff(M1,M2);
        CerrarPinza();
        goReverse(M1,M2);
        delay(15000);
        motorsOff(M1,M2);
        delay(5000);
    }
   }
  }
 }
}
void GirarDerecha(){
  motorOn(M1,REVERSE);
  motorOn(M2,FORWARD);
}

void GirarIzquierda(){
  motorOn(M1,FORWARD);
  motorOn(M2,REVERSE);
}

void GirarDerecha_Interseccion(){
  motorOn(M1,REVERSE);
  motorOn(M2,FORWARD);
  delay(200);
  while(lineRead(J1)==BLACK){
    motorOn(M1,REVERSE);
    motorOn(M2,FORWARD);
 }
}

void GirarIzquierda_Interseccion(){
  motorOn(M1,FORWARD);
  motorOn(M2,REVERSE);
  delay(200);
  while(lineRead(J2)==BLACK){
    motorOn(M1,REVERSE);
    motorOn(M2,FORWARD);
  }
}

void CerrarPinza(){
  motorOn(M3,REVERSE);
  delay(350);
  motorOff(M3);
}

void AbrirPinza(){
  motorOn(M3,FORWARD);
  delay(350);
  motorOff(M3);
}

