//files we are using in the main program
#include "main.h"
#include "math.h"
#include "main.cpp"
PROS_USE_SIMPLE_NAMES
//namespaces to shorten code



//used for distance calculations

//resetting the encoders in the motors to 0
static double ticksperinch = 286.476723050;
void reset_encoders() {
	llift.tare_position();
	rlift.tare_position();
	rintake.tare_position();
	lintake.tare_position();
	lfront.tare_position();
	rfront.tare_position();
	rback.tare_position();
	lback.tare_position();
}
//move a set distance
void move_distance(int distance){
	reset_encoders();
	lfront.move_absolute(distance*ticksperinch, 95);
	lback.move_absolute(distance*ticksperinch, 95);
	rfront.move_absolute(distance*ticksperinch, 95);
	rback.move_absolute(distance*ticksperinch, 95);
}
//turn left a set amount of degrees
void turn_left(int degrees){
	lfront.move_absolute(-(ticksperinch*2*M_PI*9)*(degrees/360), -95);
	lback.move_absolute(-(ticksperinch*2*M_PI*9)*(degrees/360), -95);
	rfront.move_absolute((ticksperinch*2*M_PI*9)*(degrees/360), 95);
	rback.move_absolute((ticksperinch*2*M_PI*9)*(degrees/360), 95);
}
//turn right a set amount of degrees
void turn_right(int degrees){
	lfront.move_absolute((ticksperinch*2*M_PI*9)*(degrees/360), -95);
	lback.move_absolute((ticksperinch*2*M_PI*9)*(degrees/360), -95);
	rfront.move_absolute(-(ticksperinch*2*M_PI*9)*(degrees/360), 95);
	rback.move_absolute(-(ticksperinch*2*M_PI*9)*(degrees/360), 95);
}
//turn intake on, 1 is inward, -1 is outward
void intake_on(int direction){
	lintake.move_velocity(50*direction);
	rintake.move_velocity(50*direction);
}
//turn intake off
void intake_off(){
	lintake.move_velocity(0);
	rintake.move_velocity(0);
}
//move lift up
void lift_up(){
	llift.move_absolute(100*ticksperinch, 30);
	rlift.move_absolute(100*ticksperinch, 30);
}
//move lift down to 0 position
void lift_down(){
	while(rlift.tare_position()>0||llift.tare_position()>0){
		llift.move_velocity(-30);
		rlift.move_velocity(-30);
	}
	llift.move_velocity(0);
	rlift.move_voltage(0);
}

void autonomous() {
	/**
	reset_encoders();
	intake_on(1);
	move_distance(23);
	intake_on(-1);
	move_distance(-28);
	intake_off();
	turn_left(90);
	intake_on(1);
	move_distance(23);
	intake_off();
	move_distance(-23);
	turn_right(90);
	move_distance(28);
	intake_on(-1);
	move_distance(-5);
	intake_off();
	*/
}
