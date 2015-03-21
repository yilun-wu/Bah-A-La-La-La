#include <AFMotor.h>


AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // motor #2
AF_DCMotor motor3(3, MOTOR12_64KHZ); // motor #3
AF_DCMotor motor4(4, MOTOR12_64KHZ); // motor #4

void setup(){
  Serial.begin(9600);
  //go();
}

void loop(){
  go();
}

void go() {
  Serial.println("All motors ahead - fast");  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);  
  motor1.setSpeed(255); 
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void backup() {
  Serial.println("All motors backward - fast");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(255); 
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void left() {
  Serial.println("Pivot left");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255);  
  motor3.setSpeed(255); 
  motor4.setSpeed(255);
}

void right() {
  Serial.println("Pivot right");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255);  
  motor3.setSpeed(255); 
  motor4.setSpeed(255);
}

void halt() {
  uint8_t i;
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i);
    delay(10);
    }
   Serial.println("All motors stop");
   motor1.run(RELEASE);
   motor2.run(RELEASE);
   motor3.run(RELEASE);
   motor4.run(RELEASE);   
}

void avoidLeft() {
  halt();
  backup();
  delay(1500);
  left();
  delay(900);
}

void avoidRight() {
  halt();
  backup();
  delay(1500);
  right();
  delay(900);

}
