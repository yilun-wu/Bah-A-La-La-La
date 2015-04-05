#define TOTAL_TH 6000
#define S0_TH 1000 //Rightmost sensor
#define S7_TH 1000 //Leftmost sensor
#define BACKWARD_DISTANCE -4.5
void intersect_detect(){
	int tilt_dir = 2; //2 for none, 1 for left, 3 for right
	qtrrc.read(sensorValues_D);
	long stepper_init = stepper1.currentPosition();
	while (QTRtotal(sensorValues_D) < TOTAL_TH){
		go_speed(3, 50);
		qtrrc.read(sensorValues_D);
		if (stepper1.currentPosition > stepper_init + 70) {
			while (QTRtotal(sensorValues_D) < TOTAL_TH){
				go_speed(-3, -50);
				qtrrc.read(sensorValues_D);
			}
			go(-3, 300);
			break;
		}
	}
	while (QTRtotal(sensorValues_D) < TOTAL_TH){
		go_speed(3, 50);
		qtrrc.read(sensorValues_D);
		delay(50);
	}
	if (sensorValues_D[0]>S0_TH && sensorValues_D[NUM_SENSORS - 1] < S7_TH) tilt_dir = 3;
	if (sensorValues_D[0]<S0_TH && sensorValues_D[NUM_SENSORS - 1] > S7_TH) tilt_dir = 1;
	if (sensorValues_D[0]>S0_TH && sensorValues_D[NUM_SENSORS - 1] > S7_TH) tilt_dir = 2;
	if (tilt_dir == 1){
		while (sensorValues_D[0] < S0_TH && sensorValues_D[NUM_SENSORS - 1] > S7_TH){
			go_1(1, 20);
			qtrrc.read(sensorValues_D);
		}
	}
	if (tilt_dir == 3){
		while (sensorValues_D[NUM_SENSORS - 1] < S7_TH && sensorValues_D[0] > S0_TH){
			go_2(1, 20);
			qtrrc.read(sensorValues_D);
		}
	}
	qtrrc.read(sensorValues_D);
	if (sensorValues_D[0] > S0_TH && sensorValues_D[NUM_SENSORS - 1] > S7_TH) return;
	else { go(BACKWARD_DISTANCE, 100); intersect_detect(); }
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

void align(){
	go(-4, 200);
	intersect_detect();
	long prev_stepper2 = stepper2.currentPosition();
	alignment_l();
	delay(100);
	long prev_stepper1 = stepper1.currentPosition();
	alignment_r();
	/*qtrrc.read(sensorValues_D);
	if (QTRtotal(sensorValues_D) < TOTAL_TH){
		stepper1.runToNewPosition(prev_stepper1);
		stepper2.runToNewPosition(prev_stepper2);
		align();
	}*/
	delay(100);
}
//
void alignment_l(){
	qtrrc.read(sensorValues_D);
	while (sensorValues_D[0] > S0_TH){
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
	while (sensorValues_D[0] > S0_TH){
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
	while (sensorValues_D[NUM_SENSORS - 1] > S7_TH){
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
	while (sensorValues_D[NUM_SENSORS - 1] > S7_TH){
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

