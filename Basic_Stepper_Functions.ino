void go(int step_num, int speed){
	stepper1.move(step_num);
	stepper2.move(step_num);
	//stepper1.setSpeed(speed);
	//stepper2.setSpeed(speed);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
}

void go_speed(int step_num, int speed){
	stepper1.move(step_num);
	stepper2.move(step_num);
	stepper1.setSpeed(speed);
	stepper2.setSpeed(speed);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.runSpeedToPosition(); stepper2.runSpeedToPosition(); }
}

void rotate(float degree, int speed){
	int step_num = (int)(degree / 360 * 264);
	stepper1.move(-step_num);
	stepper2.move(step_num);
	//stepper1.setSpeed(-speed);
	//stepper2.setSpeed(speed);
	while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) { stepper1.run(); stepper2.run(); }
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

