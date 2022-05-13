

#define PWMA   6           //Left Motor Speed pin (ENA)
#define AIN2   A0          //Motor-L forward (IN2).
#define AIN1   A1          //Motor-L backward (IN1)
#define PWMB   5           //Right Motor Speed pin (ENB)
#define BIN1   A2          //Motor-R forward (IN3)
#define BIN2   A3          //Motor-R backward (IN4)
#define const int Clock = 13;
#define const int Address = 12;
#define const int DataOut = 11;
#define const int CS = 10;
#define const int TRSensors_h = ;
#define const int QTR_EMITTERS_OFF = 0;
#define const int QTR_EMITTERS_ON = 1;
#define const int QTR_EMITTERS_ON_AND_OFF = 2;
#define const int QTR_NO_EMITTER_PIN = 255;
#define const int QTR_MAX_SENSORS = 16;
#define const int ECHO = 2;
#define const int TRIG = 3;
#define const int Addr = 0x20;
int RIJDEN = 0;
int REMMEN = 0;
int  DRAAIEN = 0;
int TOESTAND = RIJDEN;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);  
  
}

void loop() {
  // put your main code here, to run repeatedly:
if (TOESTAND == RIJDEN) {
  analogWrite(PWMA,50);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMB,50);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2,HIGH);
}

 if(TOESTAND == REMMEN) {
      
    }

    if(TOESTAND == DRAAIEN) {
      
    }
}
