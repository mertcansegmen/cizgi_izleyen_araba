#define sensorSol 10
#define sensorOrtaSol 11
#define sensorOrtaSag 12
#define sensorSag 13

#define MotorR1 6
#define MotorR2 7 
#define MotorRE 9

#define MotorL1 5
#define MotorL2 4
#define MotorLE 3

void setup() {
  Serial.begin(9600);
  
  pinMode(sensorSol, INPUT);
  pinMode(sensorOrtaSol, INPUT);
  pinMode(sensorOrtaSag, INPUT);
  pinMode(sensorSag, INPUT);
}

void loop() {
  boolean sol = digitalRead(sensorSol);
  boolean ortaSol = digitalRead(sensorOrtaSol);
  boolean ortaSag = digitalRead(sensorOrtaSag);
  boolean sag = digitalRead(sensorSag);

  sensorDegerleriniYazdir();

  if(ortaSol == 1 && ortaSag == 0){
    sol();
  }
  else if(ortaSol == 0 && ortaSag == 1){
    sag();
  }
  else if(ortaSol == 1 && ortaSag == 1 ){
    ileri();
  }
  else if(ortaSol == 0 && ortaSag == 0 ){
    dur();
  }
}

void ileri(){
    digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
    digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
    analogWrite(MotorRE, 150); // Sağ motorun hızı 150
  
    digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
    analogWrite(MotorLE, 150); // Sol motorun hızı 150
    Serial.print("ARABA DÜZ GİDİYOR.   ");
}

void sol(){
    digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
    digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
    analogWrite(MotorRE, 150); // Sağ motorun hızı 150
  
    digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
    digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
    analogWrite(MotorLE, 150); // Sol motorun hızı 150
    Serial.print("ARABA SOLA DÖNÜYOR.   ");
}

void sag(){
    digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi pasif
    digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi aktif
    analogWrite(MotorRE, 150); // Sağ motorun hızı 150
  
    digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
    analogWrite(MotorLE, 150); // Sol motorun hızı 150
    Serial.print("ARABA SAĞA DÖNÜYOR.   ");
}

void dur(){
    digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi pasif
    digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
    analogWrite(MotorRE, 0); // Sağ motorun hızı 0
  
    digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
    digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
    analogWrite(MotorLE, 0); // Sol motorun hızı 0
}

void sensorDegerleriniYazdir(){
  Serial.print(sol);
  Serial.print(" - ");
  Serial.print(ortaSol);
  Serial.print(" - ");
  Serial.print(ortaSag);
  Serial.print(" - ");
  Serial.print(sag);
  Serial.println("");
}
