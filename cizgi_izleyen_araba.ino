#define sensorSol 11
#define sensorOrta 12
#define sensorSag 13

#define MotorR1 6
#define MotorR2 7 
#define MotorRE 9

#define MotorL1 5
#define MotorL2 4
#define MotorLE 3

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
        geri();
        break;
      case '3':
        sola();
        break;
      case '4':
        saga();
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
    digitalWrite(MotorR1, LOW); // Sağ motorun geri hareketi
    digitalWrite(MotorR2, HIGH); // Sağ motorun ileri hareketi
    analogWrite(MotorRE, 75); // Sağ motorun hızı
  
    digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi
    analogWrite(MotorLE, 75); // Sol motorun hızı
    Serial.println("ARABA DÜZ GİDİYOR.   ");
}

void geri(){
    digitalWrite(MotorR1, HIGH); // Sağ motorun geri hareketi
    digitalWrite(MotorR2, LOW); // Sağ motorun ileri hareketi
    analogWrite(MotorRE, 75); // Sağ motorun hızı
  
    digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi
    digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi
    analogWrite(MotorLE, 75); // Sol motorun hızı
    
    Serial.println("ARABA GERİ GİDİYOR.   ");
}

void sola(){
    digitalWrite(MotorR1, LOW); // Sağ motorun geri hareketi
    digitalWrite(MotorR2, HIGH); // Sağ motorun ileri hareketi
    analogWrite(MotorRE, 75); // Sağ motorun hızı
  
    digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi
    analogWrite(MotorLE, 0); // Sol motorun hızı
    
    Serial.println("ARABA SOLA DÖNÜYOR.   ");
}

void saga(){
    digitalWrite(MotorR1, LOW); // Sağ motorun geri hareketi
    digitalWrite(MotorR2, LOW); // Sağ motorun ileri hareketi
    analogWrite(MotorRE, 0); // Sağ motorun hızı
  
    digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi
    analogWrite(MotorLE, 75); // Sol motorun hızı
    
    Serial.println("ARABA SAĞA DÖNÜYOR.   ");
}

void dur(){
    digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi
    digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi
    analogWrite(MotorRE, 0); // Sağ motorun hızı
  
    digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi
    analogWrite(MotorLE, 0); // Sol motorun hızı
    
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
