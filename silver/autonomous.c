#include "main.h"

#define RFRONT 20
#define LFRONT 10
#define RBACK 14
#define LBACK 9
#define RLIFT 5
#define LLIFT 6
#define RINTAKE 7
#define LINTAKE 8


//used for distance calculations

//resetting the encoders in the motors to 0
static double ticksperinch = 286.476723050;
void reset_encoders() {
	motor_tare_position(RFRONT);
	motor_tare_position(LFRONT);
	motor_tare_position(RBACK);
	motor_tare_position(LBACK);
	motor_tare_position(RINTAKE);
	motor_tare_position(LINTAKE);
	motor_tare_position(RLIFT);
	motor_tare_position(LLIFT);

}
//move a set distance
void move_distance(int distance){
	reset_encoders();
	motor_move_absolute(RFRONT, -distance*ticksperinch, -100);
	motor_move_absolute(LFRONT, distance*ticksperinch, 100);
	motor_move_absolute(RBACK, -distance*ticksperinch, -100);
	motor_move_absolute(LBACK, distance*ticksperinch, 100);
}
//turn left a set amount of degrees
void turn_left(int degrees){
	motor_move_absolute(RFRONT,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(RBACK,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LBACK,-(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LFRONT,-(ticksperinch*2*M_PI*9)*(degrees/360), 100);


}
//turn right a set amount of degrees
void turn_right(int degrees){
	motor_move_absolute(RFRONT,-(ticksperinch*2*M_PI*9)*(degrees/360), -100);
	motor_move_absolute(RBACK,-(ticksperinch*2*M_PI*9)*(degrees/360), -100);
	motor_move_absolute(LBACK,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LFRONT,(ticksperinch*2*M_PI*9)*(degrees/360), 100);

}
//turn intake on, 1 is inward, -1 is outward
void intake_on(int direction){
	if (direction == 1) {
		motor_move(LINTAKE, 40);
		motor_move(RINTAKE, -40);
	}else if (direction == -1) {
		motor_move(LINTAKE, -40);
		motor_move(RINTAKE, 40);
	}

}
//turn intake off
void intake_off(){
	motor_move(LINTAKE, 0);
	motor_move(RINTAKE, 0);
}
//move lift up
void lift_up(distance){
	reset_encoders();
	motor_move_absolute(LLIFT, distance*ticksperinch, 100);
	motor_move_absolute(RLIFT, distance*ticksperinch, -100);
}
//move lift down to 0 position
void lift_down(distance){
	reset_encoders();
	motor_move_absolute(LLIFT, -distance*ticksperinch, 100);
	motor_move_absolute(RLIFT,-distance*ticksperinch, -100);
}

void blue_square(){ // starting place is the blue square

	reset_encoders();
	intake_on(1); // turns on intake pulls block
	delay(500);
	intake_off();//turns off intake with block
	move_distance(23); //moves forward 23 inches
	intake_on(-1); //flips intake releases the block
	delay(500);
	intake_off();
	move_distance(-28); //moves back 28 inches
	turn_left(90); // turns left 90 degrees
	intake_on(1); //turns on the intake
	move_distance(23); //moves forward 23 inches and picks up block
	intake_off(); // turns off intake
	move_distance(-23); //move back 23 inches
	turn_right(90);//turns 90 right
	move_distance(28);//moves forward 28 inches
	intake_on(-1); //flips intake releases the block
	move_distance(-23); //moves back 23 inches to start position
	intake_off(); //turns off intake

}

void red_square(){ // starting place is the red square

	reset_encoders();
	intake_on(1); // turns on intake pulls block
	delay(500);
	intake_off();//turns off intake with block
	move_distance(23); //moves forward 23 inches
	intake_on(-1); //flips intake releases the block
	delay(500);
	intake_off();
	move_distance(-28); //moves back 28 inches
	turn_right(90); // turns right 90 degrees
	intake_on(1); //turns on the intake
	move_distance(23); //moves forward 23 inches and picks up block
	intake_off(); // turns off intake
	move_distance(-23); //move back 23 inches
	turn_left(90);//turns 90 left
	move_distance(28);//moves forward 28 inches
	intake_on(-1); //flips intake releases the block
	move_distance(-23); //moves back 23 inches to start position
	intake_off(); //turns off intake

}
void autonomous() {

	//blue_square(); starting from blue square
	//red_square(); starting from red_square

}
