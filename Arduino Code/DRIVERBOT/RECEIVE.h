//Define which pin the motor and ledstrip are at. 
#define motorPinRightDir  0//D3
#define motorPinRightSpeed 5//D1
#define LED_Strip 14      //D5

Servo My_servo;

void onConnectionEstablished() {
  client.subscribe("harley@berglun.se/motor", [] (const String & payload1) {      //Subscribe to the motor topic
    //Splits the received string (x,y) and makes it into 2 ints x and y. 
    int Power = payload1.substring(1, payload1.indexOf(',')).toInt();         
    int Strength = payload1.substring(payload1.lastIndexOf(',') + 1).toInt();
    //Using the variables to determin the direction and speed of the motor
    digitalWrite(motorPinRightDir, Power);
    analogWrite(motorPinRightSpeed, Strength);
  });

  client.subscribe("harley@berglun.se/servo", [] (const String & payload2) {      //Subscribe to the servo topic
    //Splits the received string (x) and makes it into a int x. 
    int SERVO = payload2.substring(1, payload2.indexOf(',')).toInt();
    //Using the variable to controle the degree on the servo
    My_servo.write(SERVO);
  });

  client.subscribe("harley@berglun.se/lampa", [] (const String & payload3) {      //Subscribe to the lampa topic
    //Splits the received string (x) and makes it into a int x.
    int LAMPA = payload3.substring(1, payload3.indexOf(',')).toInt();
    //The received value is 1 or 0, so to power the ledstrip it requires 0-1024. 
    //So we map the value from 0-1 to 0-1024.
    int LampVal = map(LAMPA, 0, 1, 0, 1024);
    //Turning on the ledstrip
    analogWrite(LED_Strip, LampVal);
  });
}
