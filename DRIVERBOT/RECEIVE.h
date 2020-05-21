#define motorPinRightDir  0//D3
#define motorPinRightSpeed 5//D1

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
  oledScreen();
}
