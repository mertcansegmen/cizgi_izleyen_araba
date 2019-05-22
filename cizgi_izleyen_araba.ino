#define sensorSol 12
#define sensorOrtaSol 11
#define sensorOrtaSag 10
#define sensorSag 9

#define solMotorGeri 6
#define solMotorHiz 7
#define solMotorIleri 8

#define sagMotorIleri 4
#define sagMotorGeri 3
#define sagMotorHiz 5

#define motorHizi 60
#define donusHizi 60

boolean sensorlerAktifMi = false;
boolean geriSayimYapildiMi = false;

boolean sensorSolDeger;
boolean sensorSagDeger;
boolean sensorOrtaSolDeger;
boolean sensorOrtaSagDeger;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char data;
    data = Serial.read();
    Serial.println(data);
    switch(data){
      case '1': ileri();        break;
      case '2': saga();         break;
      case '3': geri();         break;
      case '4': sola();         break;
      case '5': hafifSaga();    break;
      case '6': sagArkaya();    break;
      case '7': solArkaya();    break;
      case '8': hafifSola();    break;
      
      case 'a': 
        sensorleriAktiflestir();
        break;
      case 'd': 
        sensorleriDevreDisiBirak();
        break;
      default: dur(); break;
    }
  }

  if(sensorlerAktifMi){
    if(!geriSayimYapildiMi)
      geriSayimiBaslat();
    cizgiTakipEt(); 
  }
}

void cizgiTakipEt(){
  sensorOrtaSolDeger = digitalRead(sensorOrtaSol);
  sensorOrtaSagDeger = digitalRead(sensorOrtaSag);
  sensorSolDeger = digitalRead(sensorSol);
  sensorSagDeger = digitalRead(sensorSag);

  
  if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    ileri();
  }
  

  /*
  if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    sola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    saga();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    hafifSola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    hafifSola();
  }*/
}

void geriSayimiBaslat(){
    //buzzer
    delay(1000);
    //buzzer
    delay(1000);
    //buzzer
    delay(1000);
    //buzzer
    delay(1000);
    //buzzer
    delay(1000);
    geriSayimYapildiMi = true;
    ileri();
}

void sensorleriAktiflestir(){
  sensorlerAktifMi = true;
}

void sensorleriDevreDisiBirak(){
  sensorlerAktifMi = false;
  geriSayimYapildiMi = false;
  dur();
}


void ileri(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, motorHizi);
}

void geri(){  
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, motorHizi);
}

void dur(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
}

void sola(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, donusHizi);

}

void saga(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, donusHizi);
}

void hafifSola(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);
  
  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, motorHizi);
}


void hafifSaga(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
}

void solArkaya(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, motorHizi);
}


void sagArkaya(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
}
