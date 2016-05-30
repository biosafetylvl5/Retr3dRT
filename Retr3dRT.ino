#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING

void activateStep(){
  
    digitalWrite(X_STEP_PIN    , HIGH);
    digitalWrite(Y_STEP_PIN    , HIGH);
    digitalWrite(Z_STEP_PIN    , HIGH);
    digitalWrite(E_STEP_PIN    , HIGH);
    digitalWrite(Q_STEP_PIN    , HIGH);     
    delay(5);
    
    digitalWrite(X_STEP_PIN    , LOW);
    digitalWrite(Y_STEP_PIN    , LOW);
    digitalWrite(Z_STEP_PIN    , LOW);
    digitalWrite(E_STEP_PIN    , LOW);
    digitalWrite(Q_STEP_PIN    , LOW);     
    delay(5);
    
    digitalWrite(X_STEP_PIN    , HIGH);
    digitalWrite(Y_STEP_PIN    , HIGH);
    digitalWrite(Z_STEP_PIN    , HIGH);
    digitalWrite(E_STEP_PIN    , HIGH);
    digitalWrite(Q_STEP_PIN    , HIGH);     
    delay(5);
    
    digitalWrite(X_STEP_PIN    , LOW);
    digitalWrite(Y_STEP_PIN    , LOW);
    digitalWrite(Z_STEP_PIN    , LOW);
    digitalWrite(E_STEP_PIN    , LOW);
    digitalWrite(Q_STEP_PIN    , LOW);   
    delay(5);
}

void setup() {
  
  Serial.begin(9600);
  Serial.println("Remember to have 12v supplied to the board when testing");
  Serial.println("Failure to do so will produce faulty results\n");  //2, 3, 4, 5, 6, 11, 14, 15, 16, 17, 23, 25, 27, 31, 32, 33, 35, 37, 38, 41};
  const int pins[] = {//2, 3, 4, 5, 6, 11, 14, 15, 16, 17, 23, 25, 27, 31, 32, 33, 35, 37, 38, 41};
                      16, 17, 23, 25,
                      2,  3,  14, 15,
                      4,  5,  6,  11,
                      35, 37, 38, 41,
                      27, 31, 32, 33
                      };

  char* names[]={"E0:1", "E0:2", "E0:3", "E0:4",
                     "E1:1", "E1:2", "E1:3", "E1:4",
                     "X:1 ",  "X:2 ",  "X:3 ",  "X:4 ",
                     "Y:1 ",  "Y:2 ",  "Y:3 ",  "Y:4 ",
                     "Z:1 ",  "Z:2 ",  "Z:3 ",  "Z:4 ",
                     };

  int oldValues[19];
  int newValues[19];
  int i=0;
  
  pinMode(32 , INPUT);
  
  pinMode(FAN_PIN , OUTPUT);
  pinMode(HEATER_0_PIN , OUTPUT);
  pinMode(HEATER_1_PIN , OUTPUT);
  pinMode(LED_PIN  , OUTPUT);
  
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);
  
  pinMode(E_STEP_PIN  , OUTPUT);
  pinMode(E_DIR_PIN    , OUTPUT);
  pinMode(E_ENABLE_PIN    , OUTPUT);
  
  pinMode(Q_STEP_PIN  , OUTPUT);
  pinMode(Q_DIR_PIN    , OUTPUT);
  pinMode(Q_ENABLE_PIN    , OUTPUT);
  
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);
  digitalWrite(E_ENABLE_PIN    , LOW);
  digitalWrite(Q_ENABLE_PIN    , LOW);
  digitalWrite(X_DIR_PIN    , LOW);
  digitalWrite(Y_DIR_PIN    , LOW);
  digitalWrite(Z_DIR_PIN    , LOW);
  digitalWrite(E_DIR_PIN    , LOW);
  digitalWrite(Q_DIR_PIN    , LOW);

  activateStep();
  
  i=0;
  for (i = 0; i < 20; i = i + 1) { oldValues[i]=digitalRead(pins[i]); }
  
  activateStep();
  
  i=0;
  for (i = 0; i < 20; i = i + 1) { newValues[i]=digitalRead(pins[i]); }
  
  i=0;
  for (i = 0; i < 20; i = i + 1) {
    if(!(oldValues[i]==newValues[i])){
      Serial.print(names[i]);
      Serial.println(" Working");
    }else{
      Serial.print(names[i]);
      Serial.println(" Faulty");
      }
  }
  
  analogWrite(A13, 0);
  analogWrite(A14, 0);
  analogWrite(A15, 0);
  int zero = analogRead(A9);
  int one = analogRead(A10);
  int two = analogRead(A11);
  if(zero<700){ Serial.println("T0:  Working"); }else{Serial.println("T0:  Faulty"); }
  if(one<700){  Serial.println("T1:  Working"); }else{Serial.println("T1:  Faulty"); }
  if(two<700){  Serial.println("T2:  Working"); }else{Serial.println("T2:  Faulty"); }
}





void loop () {
  
  if (millis() %1000 <500) 
    digitalWrite(LED_PIN, HIGH);
  else
   digitalWrite(LED_PIN, LOW);
  
  if (millis() %1000 <300) {
    digitalWrite(HEATER_0_PIN, HIGH);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
  } else if (millis() %1000 <600) {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, HIGH);
    digitalWrite(FAN_PIN, LOW);
  } else  {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, HIGH);
  }
   activateStep();
  delay(50);
}

