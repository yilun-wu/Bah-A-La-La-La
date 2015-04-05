#include <AccelStepper.h>
#include <AFMotor.h>
#include <Keypad\Keypad.h>

const byte ROWS = 1; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
		{ '1', '2', '3' }
};
byte rowPins[ROWS] = { 13 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 2, 1, 0 }; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

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
	stepper1.setAcceleration(300);
	stepper2.setAcceleration(300);
	stepper1.setMinPulseWidth(20);
	stepper2.setMinPulseWidth(20);
	//Serial.begin(9600);
	
	char codes[7];
	for (unsigned int i = 0; i < 6; i++){
		char customKey = customKeypad.getKey();
		while (!customKey) customKey = customKeypad.getKey();
		codes[i] = customKey;
	}
	codes[6] = '\0'; 
	char start = customKeypad.getKey();
	while (!start) start = customKeypad.getKey();
	//leave s-bot
	go(-52, 300);
	turn_right();
	go(-10, 300);
	fine_align_l();
	rotate(-137);
	go(12.5, 300);
	go(-12.5, 300);


	//test();


	if (String(codes) == "111311") p110310();
	if (String(codes) == "111312") p110311();
	if (String(codes) == "111321") p110320();
	if (String(codes) == "111322") p111321();
	if (String(codes) == "112311") p111310();
	if (String(codes) == "112312") p111311();
	if (String(codes) == "112321") p111320();
	if (String(codes) == "112322") p111321();
	if (String(codes) == "121311") p120310();
	if (String(codes) == "121312") p120311();
	if (String(codes) == "121321") p120320();
	if (String(codes) == "121322") p120321();
	if (String(codes) == "122311") p121310();
	if (String(codes) == "122312") p121311();
	if (String(codes) == "122321") p121320();
	if (String(codes) == "122322") p121321();
	if (String(codes) == "211211") p210210();
	if (String(codes) == "211212") p210211();
	if (String(codes) == "211221") p210220();
	if (String(codes) == "211222") p210221();
	if (String(codes) == "212211") p211210();
	if (String(codes) == "212212") p211211();
	if (String(codes) == "212221") p211220();
	if (String(codes) == "212222") p211221();
	if (String(codes) == "221212") p220211();
	if (String(codes) == "221221") p220220();
	if (String(codes) == "221222") p220221();
	if (String(codes) == "222211") p221210();
	if (String(codes) == "222221") p221220();
	if (String(codes) == "222222") p221221();
	if (String(codes) == "311111") p310110(); 
	if (String(codes) == "311112") p310111();
	if (String(codes) == "311121") p310120();
	if (String(codes) == "311122") p310121(); 
	if (String(codes) == "312111") p311110(); 
	if (String(codes) == "312112") p311111();
	if (String(codes) == "312121") p311120();
	if (String(codes) == "312122") p311121(); 
	if (String(codes) == "321111") p320110(); 
	if (String(codes) == "321112") p320111();
	if (String(codes) == "321121") p320120();
	if (String(codes) == "321122") p320121();
	if (String(codes) == "322111") p321110();
	if (String(codes) == "322112") p321111();
	if (String(codes) == "322121") p321120();
	if (String(codes) == "322122") p321121();
	
}

void loop()
{
	//sensorRaw();
}
