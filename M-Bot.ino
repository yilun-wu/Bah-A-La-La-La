#include <AccelStepper.h>
#include <AFMotor.h>

AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);


// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
void forwardstep() {
	motor1.onestep(FORWARD, DOUBLE);
}
void backwardstep() {
	motor1.onestep(BACKWARD, DOUBLE);
}
void forwardstep2() {
	motor2.onestep(FORWARD, DOUBLE);
}
void backwardstep2() {
	motor2.onestep(BACKWARD, DOUBLE);
}
AccelStepper stepper1(forwardstep, backwardstep); // use functions to step
AccelStepper stepper2(forwardstep2, backwardstep2);
#include "QTRSensors.h"
#define NUM_SENSORS             8  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN_D           QTR_NO_EMITTER_PIN
#define TIMEOUT                 2500
unsigned char SENSORS[NUM_SENSORS] = {
	10, 9, 14, 15, 16, 17, 18, 19
};
QTRSensorsRC qtrrc(SENSORS, NUM_SENSORS, TIMEOUT, EMITTER_PIN_D);
unsigned int sensorValues_D[NUM_SENSORS];
void setup()
{
	stepper1.setMaxSpeed(390);
	stepper2.setMaxSpeed(390);
	stepper1.setAcceleration(400);
	stepper2.setAcceleration(400);
	stepper1.setMinPulseWidth(20);
	stepper2.setMinPulseWidth(20);
	//for (int i = 0; i < 200; i++)
	//{// reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
	//	qtrrc.calibrate();
	//}
	Serial.begin(9600);
}

void loop()
{
	
	rr_o();
}
