//goes from starting point, gets the right rear hopper ball and proceed towards the central point
# define PICK 7.5
//untested
void start_o1(){
	rotate(45);
	go(-100, 300);
	fine_align_l();
	go(-60, 300);
	turn_left();
}

void start_o3(){
	//go(20, 300);
	//fine_align_l();
	//rotate(-45);
	//go(PICK, 300);
	//go(-PICK, 300);
	go(-113.14, 300);
	rotate(-135);
	fine_align();
}

void start_o2(){
	rotate(-135);
	align();

	go(80, 300);
	turn_left();
	align();
	go(40, 300);
	fine_align_r();
}

void start_o4(){
	rotate(11.3);
	go(-72, 300);
	rotate(-29.7);
	go(-44.7, 300);
	rotate(-26.5);
	fine_align_l();
}

void start_o5(){
	rotate(-45);
	go(-100, 300);
	turn_left();
	go(80, 300);
	turn_right();
	go(20, 300);
	turn_left();
}