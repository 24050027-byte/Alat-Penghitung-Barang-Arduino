#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Inisialisasi LCD I2C dengan alamat 0x27, sesuaikan jika berbeda
LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo myServo;

const int sensor1Pin = 2;
const int sensor2Pin = 3;
const int buzzerPin = 8;
const int servoPin = 9;

int itemCount = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  myServo.attach(servoPin);
  
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Item Count: ");
  lcd.setCursor(0, 1);
  lcd.print(itemCount);
}

void loop() {
  if (digitalRead(sensor1Pin) == LOW) { // Asumsikan sensor membaca LOW saat objek terdeteksi
    itemCount++;
    updateLCD();
    soundBuzzer();
    moveServo();
    delay(500); // Debounce delay
  }
}

void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Kosongkan baris
  lcd.setCursor(0, 1);
  lcd.print(itemCount);
}

void soundBuzzer() {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}

void moveServo() {
  myServo.write(90); // Putar servo ke 90 derajat
  delay(1000);
  myServo.write(0);  // Kembali ke 0 derajat
}
