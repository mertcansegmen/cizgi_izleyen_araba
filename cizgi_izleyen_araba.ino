#define SENSOR_SOL 11
#define SENSOR_ORTA_SOL 9
#define SENSOR_ORTA_SAG 10
#define SENSOR_SAG 12

#define SOL_MOTOR_GERI 6
#define SOL_MOTOR_HIZ 7
#define SOL_MOTOR_ILERI 8

#define SAG_MOTOR_ILERI 4
#define SAG_MOTOR_GERI 3
#define SAG_MOTOR_HIZ 5

#define MOTOR_HIZI 45
#define IC_TEKER_DONUS_HIZI 75
#define DIS_TEKER_DONUS_HIZI 50

boolean sensorlerAktifMi;
boolean geriSayimYapildiMi;

boolean sensorSolDeger;
boolean sensorSagDeger;
boolean sensorOrtaSolDeger;
boolean sensorOrtaSagDeger;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char gelenDeger;
    gelenDeger = Serial.read();
    Serial.println(gelenDeger);
    switch(gelenDeger){
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
      default: dur(); 
        break;
    }
  }

  if(sensorlerAktifMi){
    if(!geriSayimYapildiMi)
      geriSayimiBaslat();
    cizgiTakipEt(); 
  }
}

void cizgiTakipEt(){
  sensorSolDeger = digitalRead(SENSOR_SOL);
  sensorOrtaSolDeger = digitalRead(SENSOR_ORTA_SOL);
  sensorOrtaSagDeger = digitalRead(SENSOR_ORTA_SAG);
  sensorSagDeger = digitalRead(SENSOR_SAG);

  sensorDegerleriniYazdir();
  
  if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    saga();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    hafifSaga();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    saga();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    hafifSola();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 0 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    saga();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    sola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 0 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 0){
    sola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 0 && sensorSagDeger == 1){
    ileri();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 0){
    sola();
  }
  else if(sensorSolDeger == 1 && sensorOrtaSolDeger == 1 && sensorOrtaSagDeger == 1 && sensorSagDeger == 1){
    ileri();
  }
}

void geriSayimiBaslat(){
  for(int i=0; i<5; i++){
    //buzzer
  }
  ileri();
  geriSayimYapildiMi = true;
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
  digitalWrite(SOL_MOTOR_ILERI, HIGH);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, MOTOR_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, HIGH);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, MOTOR_HIZI);
}

void geri(){  
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, HIGH);
  analogWrite(SOL_MOTOR_HIZ, MOTOR_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, HIGH);
  analogWrite(SAG_MOTOR_HIZ, MOTOR_HIZI);
}

void dur(){
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, 0);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, 0);
}

void sola(){
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, HIGH);
  analogWrite(SOL_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, HIGH);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, DIS_TEKER_DONUS_HIZI);
}

void saga(){
  digitalWrite(SOL_MOTOR_ILERI, HIGH);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, DIS_TEKER_DONUS_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, HIGH);
  analogWrite(SAG_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
}

void hafifSola(){
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, 0);
  
  digitalWrite(SAG_MOTOR_ILERI, HIGH);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
}

void hafifSaga(){
  digitalWrite(SOL_MOTOR_ILERI, HIGH);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, 0);
}

void solArkaya(){
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, LOW);
  analogWrite(SOL_MOTOR_HIZ, 0);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, HIGH);
  analogWrite(SAG_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
}

void sagArkaya(){
  digitalWrite(SOL_MOTOR_ILERI, LOW);
  digitalWrite(SOL_MOTOR_GERI, HIGH);
  analogWrite(SOL_MOTOR_HIZ, IC_TEKER_DONUS_HIZI);
  
  digitalWrite(SAG_MOTOR_ILERI, LOW);
  digitalWrite(SAG_MOTOR_GERI, LOW);
  analogWrite(SAG_MOTOR_HIZ, 0);
}

void sensorDegerleriniYazdir(){
  Serial.print(sensorSolDeger);
  Serial.print("-");
  Serial.print(sensorOrtaSolDeger);
  Serial.print("-");
  Serial.print(sensorOrtaSagDeger);
  Serial.print("-");
  Serial.print(sensorSagDeger);
  Serial.println("");
}
