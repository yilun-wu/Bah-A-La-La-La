void tb_y1(){
	rotate(45);
	go(28.28, 300);
	rotate(-45);
	go(17, 100);
	delay(500);
	go(-17, 100);
	rotate(45);
	go(-28.28, 300);
	rotate(-45);
}

void tb_y2(){
	rotate(-45);
	go(28.28, 300);
	rotate(45);
	go(17, 100);
	delay(100);
	go(-17, 100);
	rotate(-45);
	go(-28.28, 300);
	rotate(45);
}

void tb_y3(){
	go(17, 100);
	go(-17, 300);
}

void tb_y4(){
	rotate(26.56);//original 26.56
	go(22.36, 300);
	rotate(-26.56);
	go(17, 100);
	delay(100);
	go(-17, 300);
	rotate(26.56);
	go(-22.36, 300);
	rotate(-26.56);
}

void tb_y5(){
	rotate(-26.56);
	go(22.36, 300);
	rotate(26.56);
	go(17, 100);
	delay(100);
	go(-17, 300);
	rotate(-26.56);
	go(-22.36, 300);
	rotate(26.56);
}