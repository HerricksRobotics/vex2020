//files we are using in the main program
#include "main.h"
#include "math.h"
#include "opControl.cpp"
PROS_USE_SIMPLE_NAMES
//namespaces to shorten code
using namespace std;
using namespace pros;
using namespace c;

//defining motor objects
#define RFRONT 2
#define LFRONT 3
#define RINTAKE 4
#define LINTAKE 5
#define RBACK 6
#define LBACK 7
#define RLIFT 8
#define LLIFT 9

Motor lfront_initializer(LFRONT,E_MOTOR_GEARSET_18,false,E_MOTOR_ENCODER_DEGREES);
Motor rfront_initializer(RFRONT,E_MOTOR_GEARSET_18,true,E_MOTOR_ENCODER_DEGREES);
Motor lback_initializer(LBACK,E_MOTOR_GEARSET_18,false,E_MOTOR_ENCODER_DEGREES);
Motor rback_initializer(RBACK,E_MOTOR_GEARSET_18,true,E_MOTOR_ENCODER_DEGREES);
Motor lintake_initializer(LINTAKE,E_MOTOR_GEARSET_18,false,E_MOTOR_ENCODER_DEGREES);
Motor rintake_initializer(RINTAKE,E_MOTOR_GEARSET_18,true,E_MOTOR_ENCODER_DEGREES);
Motor llift_initializer(LLIFT,E_MOTOR_GEARSET_18,false,E_MOTOR_ENCODER_DEGREES);
Motor rlift_initializer(RLIFT,E_MOTOR_GEARSET_18,true,E_MOTOR_ENCODER_DEGREES);

//used for distance calculations


//assigning motors to ports and reversing right motors, also creating a controller




/**
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
*/


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	}
	else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * to keep execution time for this mode under a few seconds.
 * All other competition modes are blocked by initialize; it is recommended
 */

void initialize() {
	lcd::initialize();
	lcd::set_text(1, "Hello PROS User!");
	lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
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

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol();
