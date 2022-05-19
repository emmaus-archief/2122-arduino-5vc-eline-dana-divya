#include <Wire.h>
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
int DRAAIEN = 2;
int TOESTAND = DRAAIEN;
int snelheid = 75;

void PCF8574Write(byte data);
byte PCF8574Read();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  snelheid = 75;
  analogWrite(PWMA, snelheid);
  analogWrite(PWMB, snelheid);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
}

void loop() {
  bool muurGedetecteerd = false;
  if (TOESTAND == RIJDEN) {
    Serial.println("RIJDEN");
    snelheid = 75;
    analogWrite(PWMA, snelheid);
    analogWrite(PWMB, snelheid);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    if (muurGedetecteerd = true) {
      TOESTAND == REMMEN;
    }
  }

  if (TOESTAND == REMMEN) {
    Serial.println("REMMEN");
    stilstaan();
    if (snelheid = 0) {
      TOESTAND == DRAAIEN;
    }
  }

  if (TOESTAND == DRAAIEN) {
    draaien();
    if (muurGedetecteerd == false) {
      TOESTAND == RIJDEN;
    }
  }
}

void stilstaan() {
  snelheid = 0;
  analogWrite(PWMA, snelheid);
  analogWrite(PWMB, snelheid);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN2, LOW);
}

void draaien() {
  snelheid = 50;
  analogWrite(PWMA, snelheid);
  analogWrite(PWMB, snelheid);
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN2, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
}


void PCF8574Write(byte data)
{
  Wire.beginTransmission(Addr);
  Wire.write(data);
  Wire.endTransmission(); 
}

byte PCF8574Read()
{
  int data = -1;
  Wire.requestFrom(Addr, 1);
  if(Wire.available()) {
    data = Wire.read();
  }
  return data;
}

void muurGedetecteerd() {

}
