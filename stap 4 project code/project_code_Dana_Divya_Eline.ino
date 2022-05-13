

#define const int Lsnelheid = 6; //Left Motor Speed pin (ENA)
#define const int Lvooruit = A0; //Motor-L forward (IN2).
#define const int Lachteruit = A1; //Motor-L backward (IN1)
#define const int Rsnelheid = 5; //Right Motor Speed pin (ENB)
#define const int Rvooruit = A2; //Motor-R forward (IN3)
#define const int Rachteruit = A3; //Motor-R backward (IN4)
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
const RIJDEN = 0;
const REMMEN = 0;
const DRAAIEN = 0;
int TOESTAND = RIJDEN;

void setup() {
  // put your setup code here, to run once:
  pinMode(Lsnelheid, OUTPUT);
  pinMode(Lvooruit, OUTPUT);
  pinMode(Lachteruit OUTPUT);
  pinMode(Rsnelheid, OUTPUT);
  pinMode(Rvooruit, OUTPUT);
  pinMode(Rachteruit, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if(TOESTAND == RIJDEN) {
      analogWrite(Lsnelheid, 100);
      analogWrite(Lsnelheid, 100);
      digitalWrite(Lvooruit, HIGH)
      digitalWrit(Rvooruit, HIGH);
    }

    if(TOESTAND == REMMEN) {
      
    }

    if(TOESTAND == DRAAIEN) {
      
    }
}
