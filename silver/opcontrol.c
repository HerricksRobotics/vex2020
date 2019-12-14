#include "main.h"
 //defining motor and port


#define RFRONT 20
#define LFRONT 10
#define RBACK 14
#define LBACK 9
#define CLAW 5
#define LARM 6
#define RARM 18
//#define LINTAKE 8

static int DEADBAND = 10;
static int CLAWDEADBAND = 90;

void opcontrol() {
	while (1) {
		delay(20);

	 //DRIVE TRAIN STUFF
   //get power from left joystick
	 int left = (controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y))/2;

	 //get turning direction from right joystick
	 int right = (controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y))/2;

	 //how much left and right motors move

	 if (abs (right) <= DEADBAND){
		 motor_move(RFRONT, 0);
		 motor_move(RBACK, 0);
	 } else {
		 motor_move(RFRONT, -right);
		 motor_move(RBACK, -right);
	 }

	  if (abs (left) <= DEADBAND){
		 motor_move(LFRONT, 0);
		 motor_move(LBACK, 0);
	 } else {
		 motor_move(LFRONT, left);
		 motor_move(LBACK, left);
	 }

	 int left_claw = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_X);
	 int right_claw = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_X);

	 //CLAW STUFF THAT SHOULD HAVE BEEN DONE EARLIER BUT OK
	 if (abs(right_claw)>=CLAWDEADBAND && abs(left_claw)>=CLAWDEADBAND){
	 	 motor_move(CLAW, left_claw/6);
 	 }
	 if (abs(right_claw)<=CLAWDEADBAND && abs(left_claw)<=CLAWDEADBAND){
		 motor_move(CLAW, 0);
	 }

	 //motors actually move
	 // TURBOOOOOOOOO MODEEEEEEEEEEEEE
	 if (controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1)==1 && controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2)==1){
	 	 motor_move(LFRONT, left);
	 	 motor_move(RFRONT, -right);
	 	 motor_move(RBACK, -right);
	 	 motor_move(LBACK, left);
 	 }
	 else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1) == 1) {
		 //move lift motor
		 motor_move(LARM, 40);
		 motor_move(RARM, -40);

	 } else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2) == 1) {
		 motor_move(LARM, -40);
		 motor_move(RARM, 40);

	 } else {
		 motor_move(RARM, 0);
		 motor_move(LARM, 0);

	 }

/*
		if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L1) == 1) {
			motor_move(LINTAKE, 40);
			motor_move(RINTAKE, -40);
		} else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L2) == 1) {
 		 motor_move(RINTAKE, 40);
 		 motor_move(LINTAKE, -40);
	 } else {
		 motor_move(RINTAKE, 0);
		 motor_move(LINTAKE, 0);
	 }

*/
 }

}
