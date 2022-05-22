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
int TOESTAND = RIJDEN;    // zorgt dat hij begint in toestand rijden
int snelheid = 75;        // basis snelheid voor de alpha bot
int getal = 1;

byte value;
void PCF8574Write(byte data);
byte PCF8574Read();

void setup() {
  // stelt in welke pinnen out en inputs zijn
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
  if (TOESTAND == RIJDEN) {
    Serial.println("RIJDEN");
    snelheid = 75;
    analogWrite(PWMA, snelheid);
    analogWrite(PWMB, snelheid);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    PCF8574Write(0xC0 | PCF8574Read());   //zet de Pin
    value = PCF8574Read() | 0x3F;         //leest de Pin
    if (value != 0xFF)                    // als hij een muur detecteerd gaat hij dus remmen, zo niet blijft hij doorrijden
    {
      TOESTAND = REMMEN;
    }
    else
    {
      TOESTAND = RIJDEN;
    }

  }

  if (TOESTAND == REMMEN) {
    Serial.println("REMMEN");
    stilstaan();
    TOESTAND = DRAAIEN;
  }

  if (TOESTAND == DRAAIEN) {
    Serial.println("DRAAIEN");
    getal = random(1, 2);                 // Dit zou een random getal geven, 1 of 2 zodat hij random kant op kan draaien. Dit proberen we dan met een if-statement in draaien(), maar het werkt niet.
    draaien();
    PCF8574Write(0xC0 | PCF8574Read());   //zet de Pin
    value = PCF8574Read() | 0x3F;         //leest de Pin
    if (value != 0xFF)                    // als hij geen muur meer ziet gaat hij dus weer rijden, maar als de muur er nog is blijft hij draaien
    {
      TOESTAND = DRAAIEN;
    }
    else
    {
      TOESTAND = RIJDEN;
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

  if (getal == 1) {                       // in de loop wordt een random getal gekozen, 1 of 2. Hierdor zou hij steeds een andere kant op draaien ipv alleen naar links. Dit werkt helaas niet.
    analogWrite(PWMA, snelheid);
    analogWrite(PWMB, snelheid);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN2, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
  }

  if (getal == 2) {
    analogWrite(PWMA, snelheid);
    analogWrite(PWMB, snelheid);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN2, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
  }
}

// deze twee zorgen voor het werken van de afstand sensor

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
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}



