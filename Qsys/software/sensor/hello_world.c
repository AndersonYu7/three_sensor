#include <io.h> 	/* 系統I/O函式庫*/
#include <stdio.h> 	/* 系統標準輸出入函式庫 */
#include <system.h> /* 系統函式庫 */
#include <unistd.h> /* 宣告usleep函數 */
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void motor_ctrl(int duty_num)
{
	int dir;
	if(duty_num<0) dir = 1; //01 反轉
	else dir = 2; //10 正轉

	IOWR(MOTORB_DUTY_BASE, 0, abs(duty_num));
	IOWR(MOTORB_DIR_BASE, 0, dir);
}

void motor_ctrl_2(bool motor_num, int duty_num)
{
	int dir;
	if(duty_num<0) dir = 1; //01 反轉
	else dir = 2; //10 正轉

	if(!motor_num){
		IOWR(MOTORA_DUTY_BASE, 0, abs(duty_num));
		IOWR(MOTORA_DIR_BASE, 0, dir);
	} else{
		IOWR(MOTORB_DUTY_BASE, 0, abs(duty_num));
		IOWR(MOTORB_DIR_BASE, 0, dir);
	}

}

void motor(int duty_num1, int duty_num2)
{
	int dir1, dir2;
	if(duty_num1<0) dir1 = 1; //01 反轉
	else dir1 = 2; //10 正轉
	if(duty_num2<0) dir2 = 1; //01 反轉
	else dir2= 2; //10 正轉

	IOWR(MOTORA_DUTY_BASE, 0, abs(duty_num1));
	IOWR(MOTORA_DIR_BASE, 0, dir1);
	IOWR(MOTORB_DUTY_BASE, 0, abs(duty_num2));
	IOWR(MOTORB_DIR_BASE, 0, dir2);

}

void sensor_ctrl()
{
	int sensor = IORD(INFRA_SENSOR_BASE, 0);
	printf("sensor: %d\n", sensor);
}
//1:black, 0:white
//001 L: 0, M: 0, R: 1
//010 L: 0, M: 0, R: 1
//011 L: 0, M: 0, R: 1
//100 L: 0, M: 0, R: 1
//101 L: 0, M: 0, R: 1
//110 L: 0, M: 0, R: 1
//111 L: 0, M: 0, R: 1

int main() {
  int i;
  printf("hello nios III\n");
  int right = 0, left = 0, go = 1, back_right = 0, back_left = 0;
  int sensor;
  while (1) {
	  if(right){
		  if(sensor == 2 ||  sensor == 7){ //010 011 110 111
			  right = 0;
			  go = 1;
		  }
//		 else if(sensor == 4 || sensor == 6){ // 100 110
//			 left = 1;
//			 right = 0;
//		 }
		  motor(140, -120);
		  sensor = IORD(INFRA_SENSOR_BASE, 0);
//		  printf("right ");
//		  sensor_ctrl();
//		  usleep(10000);
	  }
	  else if(left){
		 if(sensor == 2 || sensor == 7){ //010 011 110 111
			  left = 0;
			  go = 1;
		  }
//		 else if(sensor == 1 || sensor == 3){ // 001 011
//			 right = 1;
//			 left = 0;
//		 }
		  sensor = IORD(INFRA_SENSOR_BASE, 0);
//		  printf("left ");
//		  sensor_ctrl();
		  motor(-120, 140);
//		  usleep(10000);
	  }
	  else if(go){
		  if(!(sensor == 0)){
			  if(sensor == 4 || sensor == 6){ //100 110
				  left = 1;
				  go = 0;
				  //motor(0, 0);
				  //usleep(20000);
			  }
			  else if(sensor == 1 || sensor == 3){ //001 011
				  right = 1;
				  go = 0;
				  //motor(0, 0);
				  //usleep(20000);
			  }
		  }
		  sensor = IORD(INFRA_SENSOR_BASE, 0);
//		  printf("go ");
//		  sensor_ctrl();
		  motor(150, 150);
	  }
	  else{
		  motor(0, 0);
	  }

	  usleep(10000);

  }
  return 0;
}
