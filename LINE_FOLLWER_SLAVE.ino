#include <Wire.h>
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int x= 1 ;
void setup() {

  // Start the I2C Bus as Slave on address 9
  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  motor1.setSpeed(255);
motor2.setSpeed(255);
motor3.setSpeed(255);
motor4.setSpeed(255);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms
  if (x == 1) {
    motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
  }
  //If value received is 3 blink LED for 400 ms
  


  if (x == 2)
  { motor1.run(BACKWARD);
motor2.run(FORWARD);
motor3.run(BACKWARD);
motor4.run(FORWARD);
  }


  if (x == 3)
  { motor1.run(FORWARD);
motor2.run(BACKWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
  }



  if (x == 4)
  {
    motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
  }
}
