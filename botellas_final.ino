int inter=0;//contador de intersecciones
void setup() {
  motorSpeed(M1,90);//varian de 0 a 100
  motorSpeed(M2,90);
  lineCompare(J1,852);//numero sacado desde el ejemplo linetest2
  lineCompare(J2,812);
  motorOn(M3,FORWARD);
  delay(300);//varia dependiendo que tanto quiero abrir la pinza
  motorOff(M3);
}

void loop() {
  if(ultrasoundRead(J5)<10){//valor depende de que tan cerca quiera la botella
    motorsOff(M2,M1);
    motorOn(M3,REVERSE);
    delay(300);//varia dependiendo que tanto quiero cerrar la pinza
    motorOff(M3);
    motorOn(M1,REVERSE);
    motorOn(M2,FORWARD);
    delay(500);//varia depende que tanto quiero girar a la derecha
    motorOn(M1,FORWARD);
    delay(800);//depende de que tanto quiero que vaya hacia adelante
    motorsOff(M2,M1);
    motorOn(M3,FORWARD);
    delay(300);//varia dependiendo que tanto quiero abrir la pinza
    motorOff(M3);
    motorOn(M1,REVERSE);
    motorOn(M2,REVERSE);
    delay(800);//tiempo para volver a la linea
    while(lineRead(J2)==BLACK){//mientras no encuentra la linea gira a la izquierda, mirar que tan lejos estoy de la linea y cuadrar tiempos o calibrar sensores
      motorOn(M1,FORWARD);
      motorOn(M2,REVERSE);
    }
  }
  else{
    if(lineRead(J1)==BLACK && lineRead(J2)==BLACK){
      motorOn(M1,FORWARD);
      motorOn(M2,FORWARD);
    }
    if(lineRead(J1)==BLACK && lineRead(J2)==WHITE){
      motorOn(M1,FORWARD);
      motorOn(M2,REVERSE);
    }
    if(lineRead(J1)==WHITE && lineRead(J2)==BLACK){
      motorOn(M1,REVERSE);
      motorOn(M2,FORWARD);
    }
    if(lineRead(J1)==WHITE && lineRead(J2)==WHITE){
      inter++;//suma uno a inter
      motorOn(M1,FORWARD);
      motorOn(M2,FORWARD);
      delay(200);
      if(inter==1){
        motorOn(M1,REVERSE);
        motorOn(M2,FORWARD);
        delay(200);//para que se salga de la linea y no presente problemas
        while(lineRead(J1)==BLACK){
          motorOn(M1,REVERSE);
          motorOn(M2,FORWARD);
        }
      }
      if(inter==5){
        motorOn(M2,REVERSE);
        motorOn(M1,FORWARD);
        delay(200);//para que se salga de la linea y no presente problemas
        while(lineRead(J2)==BLACK){
          motorOn(M2,REVERSE);
          motorOn(M1,FORWARD);
        }
      }
      if(inter==7){
        while(ultrasoundRead(J5)>12){
          motorOn(M1,FORWARD);
          motorOn(M2,FORWARD);
        }
        motorsOff(M1,M2);
        motorOn(M3,REVERSE);
        delay(300);//varia dependiendo que tanto quiero cerrar la pinza
        motorOff(M3);
        motorOn(M1,REVERSE);
        motorOn(M2,REVERSE);
        delay(2000);
      }
    }
  }
}
