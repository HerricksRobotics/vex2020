#include "main.h"
 //defining motor and port

#define RFRONT 20
#define LFRONT 10
#define RBACK 14
#define LBACK 9
#define RLIFT 5
#define LLIFT 6
#define CLAW 7
#define ARM 8
static int DEADBAND = 35;
static int CLAWDEADBAND = 90;
void opcontrol() {
	while (1) {
		delay(20);

	 //DRIVE TRAIN STUFF
   //get power from left joystick
	 int left = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);

	 //get turning direction from right joystick
	 int right = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);

	 //how much left and right motors move


	  // reverses the right motor

	 //motors actually move
	 motor_move(LFRONT, left/2);
	 motor_move(RFRONT, -right/2);
	 motor_move(RBACK, -right/2);
	 motor_move(LBACK, left/2);

	 if (controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1)==1 && controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2)==1){
	 	 motor_move(LFRONT, left);
	 	 motor_move(RFRONT, -right);
	 	 motor_move(RBACK, -right);
	 	 motor_move(LBACK, left);
 	 }
	 else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1) == 1) {
		 //move lift motor
		 motor_move(ARM, 40);
	 } else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2) == 1) {
		 motor_move(ARM, -40);
	 } else {
		 motor_move(ARM, 0);
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

//LIFT STUFF

		if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L1) == 1) {
			motor_move(LLIFT, 40);
			motor_move(RLIFT, -40);
		} else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L2) == 1) {
 		 motor_move(RLIFT, 40);
 		 motor_move(LLIFT, -40);
	 } else {
		 motor_move(LLIFT, 0);
		 motor_move(RLIFT, 0);
	 }
 }
}
