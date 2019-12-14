#include "main.h"
#include "math.h"

#define RFRONT 20
#define LFRONT 10
#define RBACK 14
#define LBACK 9
#define RLIFT 5
#define LLIFT 6
#define CLAW 7
#define ARM 8


//used for distance calculations

//resetting the encoders in the motors to 0
static double ticksperinch = 286.476723050;
void reset_encoders() {
	motor_tare_position(RFRONT);
	motor_tare_position(LFRONT);
	motor_tare_position(RBACK);
	motor_tare_position(LBACK);
	motor_tare_position(ARM);
	motor_tare_position(CLAW);
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
  reset_encoders();
	motor_move_absolute(RFRONT,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(RBACK,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LBACK,-(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LFRONT,-(ticksperinch*2*M_PI*9)*(degrees/360), 100);
}
//turn right a set amount of degrees
void turn_right(int degrees){
  reset_encoders();
	motor_move_absolute(RFRONT,-(ticksperinch*2*M_PI*9)*(degrees/360), -100);
	motor_move_absolute(RBACK,-(ticksperinch*2*M_PI*9)*(degrees/360), -100);
	motor_move_absolute(LBACK,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
	motor_move_absolute(LFRONT,(ticksperinch*2*M_PI*9)*(degrees/360), 100);
}

void lift(int distance){
//move lift up
  if (distance==1) {
	reset_encoders();
	motor_move_absolute(LLIFT, 900, 100);
	motor_move_absolute(RLIFT, 900, -100);
}
//move lift down to 0 position
if (distance==-1){
	reset_encoders();
	motor_move_absolute(LLIFT, -900, 100);
	motor_move_absolute(RLIFT,-900, -100);
 }
}
void move_arm (int direction) {
  reset_encoders();
  //moves the arm up to drop blocks on robot
  if (direction==1) {
    motor_move_absolute(ARM, 1650, 100);
  }
  //moves arm down to be in a position to grab block
  if (direction==-1) {
    motor_move_absolute(ARM, -1650, -100);
  }
}

void move_claw (int direction) {
  reset_encoders();
//opens claw
  if (direction==1) {
    motor_move_absolute(CLAW, ticksperinch*3, 100);
  }
//closes claw
  if (direction == -1){
   motor_move_absolute(CLAW, ticksperinch*-3, -100);
  }
}
void autoB2(){
  reset_encoders();
  move_claw(1); //puts preloaded claw in the lift
  move_distance(-12); //moves the robot bakcwards to begin to align with next target
  turn_left(90); //turns left to face the target
  move_arm(-1); //moves claw into position to grab block
  move_claw(1); //preps claw to grab blck
  move_distance(20); //moves robot close enough to grab target
  move_claw(-1); //grabs target block
  move_arm(1); //swings the claw and block up to position above lift
  move_claw(1); //drops block in lift
  move_distance(-20); //robot moves bakcwards towards goal zone
  turn_left(90);
  move_distance(-36);
  lift(1); //drops blocks in goal zone: mission accomplished
  lift(-1); //puts lift back in position
}
void autoR2(){
  reset_encoders();
  move_claw(1); //puts preloaded claw in the lift
  move_distance(-12); //moves the robot bakcwards to begin to align with next target
  turn_right(90); //turns left to face the target
  move_arm(-1); //moves claw into position to grab block
  move_claw(1); //preps claw to grab blck
  move_distance(20); //moves robot close enough to grab target
  move_claw(-1); //grabs target block
  move_arm(1); //swings the claw and block up to position above lift
  move_claw(1); //drops block in lift
  move_distance(-20); //robot moves bakcwards towards goal zone
  turn_right(90);
  move_distance(-36);
  lift(1); //drops blocks in goal zone: mission accomplished
  lift(-1); //puts lift back in position
}
void autonomous() {
  autoR2();// for running from position R2
  //autoB2();//for running from position B2
}
