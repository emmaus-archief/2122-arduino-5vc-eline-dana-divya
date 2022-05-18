const int PWMA = 6;           //Left Motor Speed pin (ENA)
const int AIN2 = A0;         //Motor-L forward (IN2).
const int AIN1 = A1;          //Motor-L backward (IN1)
const int PWMB = 5;           //Right Motor Speed pin (ENB)
const int BIN1 = A2;          //Motor-R forward (IN3)
const int BIN2 = A3;          //Motor-R backward (IN4)
const int Clock = 13;
const int Address = 12;
const int DataOut = 11;
const int CS = 10;
/* const int TRSensors_h = ; */
const int QTR_EMITTERS_OFF = 0;
const int QTR_EMITTERS_ON = 1;
const int QTR_EMITTERS_ON_AND_OFF = 2;
const int QTR_NO_EMITTER_PIN = 255;
const int QTR_MAX_SENSORS = 16;
const int ECHO = 2;
const int TRIG = 3;
const int Addr = 0x20;
int RIJDEN = 0;
int REMMEN = 1;
int  DRAAIEN = 2;
int TOESTAND = RIJDEN;
  
void setup() {
  // put your setup code here, to run once:
   
  
}

void loop() {
  // put your main code here, to run repeatedly:
if (TOESTAND == RIJDEN) {
  /* zorgen dat hij rechtdoor rijdt */
    if (muurGedetecteerd = true) {
    TOESTAND == REMMEN;
    }
}

if(TOESTAND == REMMEN) {
  /* speed verlagen */
    if (speed = 0) {
    TOESTAND == DRAAIEN;
  }
}

if(TOESTAND == DRAAIEN) {
  /* draaien naar links of rechts */
    if (muurGedetecteerd = false) {
    TOESTAND == RIJDEN;
    }
  }
  
}
