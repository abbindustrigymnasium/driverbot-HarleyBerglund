#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define motorPinRightDir  0//D3
#define motorPinRightSpeed 5//D1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


int Strength;

Servo My_servo;

void onConnectionEstablished() {
  client.subscribe("harley@berglun.se/motor", [] (const String & payload1) {
    int Power = payload1.substring(1, payload1.indexOf(',')).toInt();
    int Strength = payload1.substring(payload1.lastIndexOf(',') + 1).toInt();

    //Serial.println(Strength);
    //Serial.println(Power);
    digitalWrite(motorPinRightDir, Power);
    analogWrite(motorPinRightSpeed, Strength);
  });

  client.subscribe("harley@berglun.se/servo", [] (const String & payload2) {
    int SERVO = payload2.substring(1, payload2.indexOf(',')).toInt();

    //Serial.println(SERVO);
    My_servo.write(SERVO);
  });
}


void oledScreen() {

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  // Display static text
  display.println(Strength);
  display.display(); 
}
