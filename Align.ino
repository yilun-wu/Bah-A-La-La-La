void intersect_detect(){
	int tilt_dir = 2; //2 for none, 1 for left, 3 for right
	qtrrc.read(sensorValues_D);
	while (QTRtotal(sensorValues_D) < 4000){
		go_speed(3, 50);
		qtrrc.read(sensorValues_D);
	}
	delay(100);
	if (sensorValues_D[0]>300 && sensorValues_D[NUM_SENSORS - 1] < 300) tilt_dir = 3;
	if (sensorValues_D[0]<300 && sensorValues_D[NUM_SENSORS - 1] > 300) tilt_dir = 1;
	if (sensorValues_D[0]>300 && sensorValues_D[NUM_SENSORS - 1] > 300) tilt_dir = 2;
	if (tilt_dir == 1){
		while (sensorValues_D[0] < 300 && sensorValues_D[NUM_SENSORS - 1] > 300){
			go_1(1, 20);
			qtrrc.read(sensorValues_D);
		}
	}
	if (tilt_dir == 3){
		while (sensorValues_D[NUM_SENSORS - 1] < 300 && sensorValues_D[0] > 300){
			go_2(1, 20);
			qtrrc.read(sensorValues_D);
		}
	}
	qtrrc.read(sensorValues_D);
	if (sensorValues_D[0] > 300 && sensorValues_D[NUM_SENSORS - 1] > 300) return;
	else { go(-1.5, 100); intersect_detect(); }
	delay(100);
}

char on_intersect(unsigned int total){
	if (total> 5000) return 1;
	else return 0;
}


void fine_align(){
	align();
	turn_left();
	align();
	turn_right();
	//align();
}

void fine_align_l(){
	align();
	turn_left();
	align();
}

void fine_align_r(){
	align();
	turn_right();
	align();
}

char align(){
	go(-4, 200);
	intersect_detect();
	alignment_l();
	delay(100);
	alignment_r();
	delay(100);
}
//
void alignment_l(){
	qtrrc.read(sensorValues_D);
	while (sensorValues_D[0] > 300){
		Serial.println(sensorValues_D[0]);
		stepper1.move(1);
		stepper1.setSpeed(50);
		while (stepper1.distanceToGo() != 0)stepper1.runSpeedToPosition();
		qtrrc.read(sensorValues_D);
	}
	long front_line = stepper1.currentPosition();
	delay(50);
	stepper1.move(-4);
	stepper1.runToPosition();
	qtrrc.read(sensorValues_D);
	while (sensorValues_D[0] > 300){
		stepper1.move(-1);
		stepper1.setSpeed(-50);
		while (stepper1.distanceToGo()!=0)stepper1.runSpeedToPosition();
		qtrrc.read(sensorValues_D);
	}
	long behind_line = stepper1.currentPosition();
	stepper1.moveTo((behind_line + front_line) / 2);
	stepper1.runToPosition();
	Serial.println("Complete");
}

void alignment_r(){
	qtrrc.read(sensorValues_D);
	while (sensorValues_D[NUM_SENSORS - 1] > 300){
		Serial.println(sensorValues_D[0]);
		stepper2.move(1);
		stepper2.setSpeed(50);
		while (stepper2.distanceToGo() != 0)stepper2.runSpeedToPosition();
		qtrrc.read(sensorValues_D);
	}
	long front_line = stepper2.currentPosition();
	delay(50);
	stepper2.move(-4);
	stepper2.runToPosition();
	qtrrc.read(sensorValues_D);
	while (sensorValues_D[NUM_SENSORS - 1] > 300){
		stepper2.move(-1);
		stepper2.setSpeed(-50);
		while (stepper2.distanceToGo() != 0)stepper2.runSpeedToPosition();
		qtrrc.read(sensorValues_D);
	}
	long behind_line = stepper2.currentPosition();
	stepper2.moveTo((behind_line + front_line) / 2);
	stepper2.runToPosition();
	Serial.println("Complete");
}

void align_trans(){
	go(20, 30);
	char deviation = 1; //0 for left; 1 for middle; 2 for right
	int error = qtrrc.readLine(sensorValues_D) - 3500;
	if (abs(error) <2600) return;
	int last_error = error;
	while (abs(error)>500){
		last_error = error;
		if (error < 0) trans_l();
		else if (error > 0) trans_r();
		else return;
		error = qtrrc.readLine(sensorValues_D) - 2500;
		if (error == -3500) error = last_error;
		Serial.println(error);
		Serial.println(last_error);
	}
	go(-20, -30);
	Serial.println("Complete");
}




void trans_l(){
	stepper2.move(15);
	stepper2.setSpeed(60);
	stepper2.runToPosition();
	delay(10);
	stepper1.move(15);
	stepper1.setSpeed(60);
	stepper1.runToPosition();
	delay(10);
	stepper2.move(-15);
	stepper2.setSpeed(-60);
	stepper2.runToPosition();
	delay(10);
	stepper1.move(-15);
	stepper1.setSpeed(-60);
	stepper1.runToPosition();
	delay(5);
}

void trans_r(){
	stepper1.move(15);
	stepper1.setSpeed(60);
	stepper1.runToPosition();
	delay(10);
	stepper2.move(15);
	stepper2.setSpeed(60);
	stepper2.runToPosition();
	delay(10);
	stepper1.move(-15);
	stepper1.setSpeed(-60);
	stepper1.runToPosition();
	delay(10);
	stepper2.move(-15);
	stepper2.setSpeed(-60);
	stepper2.runToPosition();
	delay(5);
}

