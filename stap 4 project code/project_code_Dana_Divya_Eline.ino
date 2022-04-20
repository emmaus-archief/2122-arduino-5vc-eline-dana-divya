

#define const int PWMA = 6; //Left Motor Speed pin (ENA)
#define const int AIN2 = A0; //Motor-L forward (IN2).
#define const int AIN1 = A1; //Motor-L backward (IN1)
#define const int PWMB = 5; //Right Motor Speed pin (ENB)
#define const int BIN1 = A2; //Motor-R forward (IN3)
#define const int BIN2 = A3; //Motor-R backward (IN4)
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
/* wat is output en wat is input */

}

void loop() {
  // put your main code here, to run repeatedly:
    if(TOESTAND == RIJDEN) {
      
    }

    if(TOESTAND == REMMEN) {
      
    }

    if(TOESTAND == DRAAIEN) {
      
    }
}
