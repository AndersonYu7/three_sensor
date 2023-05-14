#include <io.h> 	/* �t��I/O�禡�w*/
#include <stdio.h> 	/* �t�μзǿ�X�J�禡�w */
#include <system.h> /* �t�Ψ禡�w */
#include <unistd.h> /* �ŧiusleep��� */
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


void motor_ctrl(int duty_num)
{
	int dir;
	if(duty_num<0) dir = 1; //01 ����
	else dir = 2; //10 ����

	IOWR(MOTORB_DUTY_BASE, 0, abs(duty_num));
	IOWR(MOTORB_DIR_BASE, 0, dir);
}

void motor_ctrl_2(bool motor_num, int duty_num)
{
	int dir;
	if(duty_num<0) dir = 1; //01 ����
	else dir = 2; //10 ����

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
	if(duty_num1<0) dir1 = 1; //01 ����
	else dir1 = 2; //10 ����
	if(duty_num2<0) dir2 = 1; //01 ����
	else dir2= 2; //10 ����

	IOWR(MOTORA_DUTY_BASE, 0, abs(duty_num1));
	IOWR(MOTORA_DIR_BASE, 0, dir1);
	IOWR(MOTORB_DUTY_BASE, 0, abs(duty_num2));
	IOWR(MOTORB_DIR_BASE, 0, dir2);

}



int main() {
  int i;
  printf("hello nios II\n");
  while (1) {
//    for (i = -10; i < 10; i++) { //�ˬdpwm�b0-255��
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
