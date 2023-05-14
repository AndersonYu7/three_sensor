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



int main() {
  int i;
  printf("hello nios II\n");
  while (1) {
//    for (i = -10; i < 10; i++) { //檢查pwm在0-255時
//      motor_ctrl(i);
//      //motor_ctrl_2(0, i); // motor a
//      //motor_ctrl_2(1, i); // motor b
//      printf("duty_num = %d\n", i);
//      usleep(500000);
//    }
	  //motor_ctrl(15);
//	  motor_ctrl_2(0, 150);
//	  motor_ctrl_2(1, -40);
	  motor(-150, 40);

  }
  return 0;
}
