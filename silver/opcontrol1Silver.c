#include "main.h"
 //defining motor and port

#define RFRONT 2
#define LFRONT 3
#define RBACK 6
#define LBACK 7
#define LIFTMOTOR 4
#define CLAWMOTOR 5

void initialize(){
	motor_set_reversed(RFRONT, true);
	motor_set_reversed(RBACK, true);
}
/*
	This is the test code for operator control, and will be used for team silver, as it has code for a claw.
	The buttons and speeds may be changed later to suit the driver.
*/

void opcontrol() {
	while (1) {
		delay(20);


   //get power from left joystick
	 int powerLeft = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);

	 //get turning direction from right joystick
	 int powerRight = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);

	 //how much left and right motors move
	 int left = powerLeft;
	 int right = powerRight;


	 //motors actually move
	 motor_move(LFRONT, left);
	 motor_move(LBACK, left);
	 motor_move(RFRONT, right);
	 motor_move(RBACK, right);

	 //if L2 button is pressed - raise lift
	 if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_L2) == 1) {
		 //move lift motor
		 motor_move(LIFTMOTOR, 40);
	 }
	 //if L1 button is pressed - lower lift
	 else if ( controller_get_digital(CONTROLLER_MASTER,  E_CONTROLLER_DIGITAL_L1) == 1) {
		 //move lift motor the other way
		 motor_move(LIFTMOTOR, -40);
	 }
	 //else stop
	 else {
		 motor_move(LIFTMOTOR, 0);
	 }

	 //if l2 is pressed open claw
	 if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_UP) == 1) {
		 //move the claw motor
		 motor_move(CLAWMOTOR, -30);
	 }
	 //if L1 is pressed close claw
	 else if( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_DOWN) == 1) {
		 //move the claw motor
		 motor_move(CLAWMOTOR, 30);
	}
	//claw does not move
	else {
		 motor_move(CLAWMOTOR, 0);
	 }

		//if R2 pressed half speed
		if ( controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_R2) == 1) {
			//Go half speed
			motor_move(LFRONT, (left)/2);
	 	 	motor_move(RFRONT, (right)/2);
	 	 	motor_move(RBACK, (right)/2);
	 	 	motor_move(LBACK, (left)/2);
		}

	}

}
