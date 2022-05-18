

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
