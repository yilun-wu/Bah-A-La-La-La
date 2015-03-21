int lastError = 0;
const float KP = 0.01;
const byte KD = 10;//5
const unsigned int MB = 300;
#define NUM_SENSORS 8
void linefollow()
{
	unsigned int sensorValues[NUM_SENSORS];
	int position = qtrrc.readLine(sensorValues);
	int error = position - 3500;
	if (QTRtotal(sensorValues_D) > 4000 || position == 0 || position == 7000) error = lastError;
	int motorSpeed = KP * error + KD * (error - lastError);
	lastError = error;


	int m1Speed = MB + motorSpeed;
	int m2Speed = MB - motorSpeed;

	if (m1Speed < 275)
		m1Speed = 275;
	if (m1Speed > 325)
		m1Speed = 325;
	if (m2Speed < 275)
		m2Speed = 275;
	if (m2Speed > 325)
		m2Speed = 325;

	stepper1.setSpeed(m1Speed);
	stepper1.runSpeed();
	stepper2.setSpeed(m2Speed);
	stepper2.runSpeed();
}

unsigned int QTRtotal(unsigned int *sensor_values){
	unsigned int total = 0;
	for (unsigned int i = 0; i < NUM_SENSORS; i++){
		total = total + sensor_values[i];
	}
	return total;
}