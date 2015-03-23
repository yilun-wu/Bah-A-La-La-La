void go(float cm, int speed){
	int step_num = (int)(cm / 9.0 / 3.14159 * 200.0);
	stepper1.move(step_num);
	stepper2.move(step_num);
	stepper1.setMaxSpeed(speed);
	stepper2.setMaxSpeed(speed);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
}

void go_speed(int step_num, int speed){
	stepper1.move(step_num);
	stepper2.move(step_num);
	stepper1.setSpeed(speed);
	stepper2.setSpeed(speed);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.runSpeedToPosition(); stepper2.runSpeedToPosition(); }
}

void rotate(float degree){
	int step_num = (int)(degree / 360.0 * 249.0);
	stepper1.move(-step_num);
	stepper2.move(step_num);
	stepper1.setMaxSpeed(50);
	stepper2.setMaxSpeed(50);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
	delay(100);
}

void turn_right(){
	stepper1.move(-60);
	stepper2.move(60);
	stepper1.setMaxSpeed(200);
	stepper2.setMaxSpeed(200);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
	delay(100);
}

void turn_left(){
	stepper1.move(60);
	stepper2.move(-60);
	stepper1.setMaxSpeed(200);
	stepper2.setMaxSpeed(200);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
	delay(100);
}

void turn_over_l(){
	stepper1.move(120);
	stepper2.move(-120);
	stepper1.setMaxSpeed(200);
	stepper2.setMaxSpeed(200);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
	delay(100);
}

void turn_over_r(){
	stepper1.move(-120);
	stepper2.move(120);
	stepper1.setMaxSpeed(200);
	stepper2.setMaxSpeed(200);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
	delay(100);
}

void go_1(int step_num, int speed){
	stepper1.move(step_num);
	//stepper1.setSpeed(speed);
	while (stepper1.distanceToGo() != 0) { stepper1.run(); }
}

void go_2(int step_num, int speed){
	stepper2.move(step_num);
	//stepper2.setSpeed(speed);
	while (stepper2.distanceToGo() != 0) { stepper2.run(); }
}

