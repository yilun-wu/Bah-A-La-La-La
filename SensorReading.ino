unsigned int sensorValues[NUM_SENSORS];
void sensorRaw(){
	qtrrc.read(sensorValues);

	// print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
	// 1023 means minimum reflectance
	for (unsigned char i = 0; i < NUM_SENSORS; i++)
	{
		Serial.print(sensorValues[i]);
		Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
	}
	Serial.println();

	delay(250);
}
