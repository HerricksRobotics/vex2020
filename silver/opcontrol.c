#include "main.h"
 //defining motor and port


#define RFRONT 20
#define LFRONT 10
#define RBACK 14
#define LBACK 9
#define RLIFT 5
#define LLIFT 6
#define RINTAKE 7
#define LINTAKE 8


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
	 motor_move(LFRONT, left);
	 motor_move(RFRONT, -right);
	 motor_move(RBACK, -right);
	 motor_move(LBACK, left);
	 if (controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1)==1 && controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2)==1){
	 	 motor_move(LFRONT, (left)/2);
	 	 motor_move(RFRONT, (-right)/2);
	 	 motor_move(RBACK, (-right)/2);
	 	 motor_move(LBACK, (left)/2);
 	 }
	 else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R1) == 1) {
		 //move lift motor
		 motor_move(RLIFT, -40);
		 motor_move(LLIFT, 40);
	 } else if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2) == 1) {
		 motor_move(RLIFT, 40);
		 motor_move(LLIFT, -40);
	 } else {
		 motor_move(RLIFT, 0);
		 motor_move(LLIFT, 0);
	 }





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


 }

}
