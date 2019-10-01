#include "main.h"
 //defining motor and port

#define RFRONT 2
#define LFRONT 3
#define RBACK 6
#define LBACK 7
#define LIFTMOTOR 4
#define CLAWMOTOR 5

void opcontrol() {
	while (1) {
		delay(20);

	 //DRIVE TRAIN STUFF
   //get power from left joystick
	 int powerLeft = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);

	 //get turning direction from right joystick
	 int powerRight = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);

	 //how much left and right motors move
	 int left = powerLeft;
	 int right = powerRight;

	  // reverses the right motor
	 right *= -1;

	 //motors actually move
	 motor_move(LFRONT, left);
	 motor_move(RFRONT, right);
	 motor_move(RBACK, right);
	 motor_move(LBACK, left);

	 //if r2 is pressed - raise lift
	 if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_LEFT) == 1) {
		 //move lift motor
		 motor_move(LIFTMOTOR, 40);
	 } else {
		 motor_move(LIFTMOTOR, 0);
	 }

	 //if r1 is pressed - lower lift
	 if ( controller_get_digital(CONTROLLER_MASTER,  E_CONTROLLER_DIGITAL_RIGHT) == 1) {
		 //move lift motor the other way
		 motor_move(LIFTMOTOR, -40);
	 } else {
		 motor_move(LIFTMOTOR, 0);
	 }

	 //if l2 is pressed move claw
	 if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_LEFT) == 1) {
		 //move the claw motor
		 motor_move(CLAWMOTOR, -30);
	 } else {
		 motor_move(CLAWMOTOR, 0);
	 }
	 //if L1 is pressed move claw backwards
	 if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L1) == 1) {
		 //move the claw motor
		 motor_move(CLAWMOTOR, 30);
	 } else {
		 motor_move(CLAWMOTOR, 0);
	 }
		//if A pressed half speed
		if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_A) == 1) {
			//Go half speed
			motor_move(LFRONT, (left)/2);
	 	 	motor_move(RFRONT, right/2);
	 	 	motor_move(RBACK, (right)/2);
	 	 	motor_move(LBACK, (left)/2);
		}

	}

}
