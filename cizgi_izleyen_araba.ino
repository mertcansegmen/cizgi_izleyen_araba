#define sensorSol 11
#define sensorOrta 12
#define sensorSag 13

#define solMotorIleri 6
#define solMotorGeri 7 
#define solMotorHiz 9

#define sagMotorGeri 5
#define sagMotorIleri 4
#define sagMotorHiz 3

#define motorHizi 75

boolean solSensorDegeri;
boolean ortaSensorDegeri;
boolean sagSensorDegeri;

void setup() {
  Serial.begin(9600);
  
  //pinMode(sensorSol, INPUT);
  //pinMode(sensorOrta, INPUT);
  //pinMode(sensorSag, INPUT);
}

void loop() {
  if(Serial.available() > 0){
    char data;
    data = Serial.read();
    Serial.println(data);
    switch(data){
      case '1':
        ileri();
        break;
      case '2':
        saga();
        break;
      case '3':
        geri();
        break;
      case '4':
        sola();
        break;
      case '5':
        saga();
        break;
      case '6':
        sagGeri();
        break;
      case '7':
        solGeri();
        break;
      case '8':
        sola();
        break;
      default:
        dur();
    }
  }
 

  /*
  solSensorDegeri = digitalRead(sensorSol);
  ortaSensorDegeri = digitalRead(sensorOrta);
  sagSensorDegeri = digitalRead(sensorSag);

  sensorDegerleriniYazdir();

  if(solSensorDegeri == 1 && sagSensorDegeri == 0){
    //sola();
  }
  else if(solSensorDegeri == 0 && sagSensorDegeri == 1){
    //saga();
  }
  else if(solSensorDegeri == 0 && sagSensorDegeri == 0){
    //ileri();
  }
  else if(solSensorDegeri == 1 && sagSensorDegeri == 1 ){
    //dur();
  }
  */
}

void ileri(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);
  
  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, motorHizi);
  
  Serial.println("ARABA DÜZ GİDİYOR.   ");
}

void geri(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, motorHizi);

  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, motorHizi);
  
  Serial.println("ARABA GERİ GİDİYOR.   ");
}

void sola(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, motorHizi);

  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
  
  Serial.println("ARABA SOLA DÖNÜYOR.   ");
}

void saga(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);
  
  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, motorHizi);
  
  Serial.println("ARABA SAĞA DÖNÜYOR.   ");
}

void sagIleri(){
  digitalWrite(solMotorIleri, HIGH);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);

  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, motorHizi);
  
  Serial.println("ARABA SAĞ İLERİ GİDİYOR.   ");
}

void solIleri(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);

  digitalWrite(sagMotorIleri, HIGH);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
  
  Serial.println("ARABA SOL İLERİ GİDİYOR.   ");
}

void sagGeri(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, HIGH);
  analogWrite(solMotorHiz, 0);

  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, motorHizi);
  
  Serial.println("ARABA SAĞ GERİ GİDİYOR.   ");
}

void solGeri(){  
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, motorHizi);

  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, HIGH);
  analogWrite(sagMotorHiz, 0);
  
  Serial.println("ARABA SOL GERİ GİDİYOR.   ");
}

void dur(){
  digitalWrite(solMotorIleri, LOW);
  digitalWrite(solMotorGeri, LOW);
  analogWrite(solMotorHiz, 0);

  digitalWrite(sagMotorIleri, LOW);
  digitalWrite(sagMotorGeri, LOW);
  analogWrite(sagMotorHiz, 0);
  
  Serial.println("ARABA DURDU.   ");
}
/*
void sensorDegerleriniYazdir(){
  Serial.print(solSensorDegeri);
  Serial.print(" - ");
  Serial.print(ortaSensorDegeri);
  Serial.print(" - ");
  Serial.print(sagSensorDegeri);
  Serial.println("");
}
*/
