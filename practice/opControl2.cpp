#include "main.cpp"

void opcontrol() {
	Motor lfront(LFRONT);
	Motor rfront(RFRONT);
	Motor lback(LBACK);
	Motor rback(RBACK);
	Motor lintake(LINTAKE);
	Motor rintake(RINTAKE);
	Motor llift(LLIFT);
	Motor rlift(RLIFT);
	Controller master(E_CONTROLLER_MASTER);
	while (true) {
   //get power from left joystick
	 int powerLeft = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);

	 //get turning direction from right joystick
	 int powerRight = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

	 //how much left and right motors move


	 //motors actually move
	 lfront.move(powerLeft);
	 lback.move(powerLeft);
	 rfront.move(powerRight);
	 rback.move(powerRight);

	 //if L2 button is pressed - raise lift
	 if (master.get_digital(E_CONTROLLER_DIGITAL_L2) == 1) {
		 //move lift motor
		 llift.move(40);
		 rlift.move(40);
	 }
	 //if L1 button is pressed - lower lift
	 else if (master.get_digital(E_CONTROLLER_DIGITAL_L1) == 1) {
		 //move lift motor the other way
		 llift.move(-40);
		 rlift.move(-40);
	 }
	 //else stop
	 else {
		 llift.move(0);
		 rlift.move(0);
	 }

	 //if R1 is pressed intake starts
	 if (master.get_digital(E_CONTROLLER_DIGITAL_R1) == 1) {
		 lintake.move(30);
		 rintake.move(30);
	 }
	 //if B is pressed emrgency output
	 else if(master.get_digital(E_CONTROLLER_DIGITAL_B) == 1) {
		 lintake.move(-30);
		 rintake.move(-30);
	}
	//claw does not move
	else {
		lintake.move(0);
		rintake.move(0);
	 }

		//if R2 pressed half speed
		if (master.get_digital(E_CONTROLLER_DIGITAL_R2) == 1) {
			//Go half speed
			lfront.move(powerLeft/2);
			lback.move(powerLeft/2);
			rfront.move(powerRight/2);
			rback.move(powerRight/2);
		}

		delay(2);
	}
}
