void tb_y1(){
	rotate(45);
	go(28.28, 300);
	rotate(-45);
	go(20, 100);
	delay(500);
	go(-20, 100);
	rotate(45);
	go(-28.28, 300);
	rotate(-45);
}

void tb_y2(){
	go(-3, 300);
	rotate(-45);
	go(28.28, 300);
	rotate(45);
	go(23, 100);
	delay(100);
	go(-23, 100);
	rotate(-45);
	go(-28.28, 300);
	rotate(45);
	go(3, 300);
}

void tb_y3(){
	go(20, 100);
	go(-20, 300);
}

void tb_y4(){
	rotate(26.56);//original 26.56
	go(22.36, 300);
	rotate(-26.56);
	go(20, 100);
	delay(100);
	go(-20, 300);
	rotate(26.56);
	go(-22.36, 300);
	rotate(-26.56);
}

void tb_y5(){
	rotate(-26.56);
	go(22.36, 300);
	rotate(26.56);
	go(20, 100);
	delay(100);
	go(-20, 300);
	rotate(-26.56);
	go(-22.36, 300);
	rotate(26.56);
}