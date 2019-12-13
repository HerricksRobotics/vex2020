#include "main.h"
#include "math.h"


#define RFRONT 1
#define LFRONT 2
#define RBACK 3
#define LBACK 4
#define RLIFT 5
#define LLIFT 6
#define RINTAKE 7
#define LINTAKE 8
//3600 ticks per rotation of motor, diameter of wheel is 4
double ticksperinch = 3600/(M_PI*4);

void setReverse ()
{
  motor_set_reversed(RFRONT, true);
  motor_set_reversed(RBACK, true);
  motor_set_reversed(RINTAKE, true);
  motor_set_reversed(LINTAKE, true);
}

void reverse(double distance)
{
  motor_move(LFRONT,-distance*ticksperinch);
	motor_move(LBACK, -distance*ticksperinch);
  motor_move(RFRONT,-distance*ticksperinch);
  motor_move(RBACK, -distance*ticksperinch);
}

void turnLeft(double distance)
{
  motor_move(LFRONT,-distance*ticksperinch);
	motor_move(LBACK, -distance*ticksperinch);
  motor_move(RFRONT,distance*ticksperinch);
  motor_move(RBACK, distance*ticksperinch);
}

void turnRight(double distance)
{
  motor_move(LFRONT,distance*ticksperinch);
	motor_move(LBACK, distance*ticksperinch);
  motor_move(RFRONT,-distance*ticksperinch);
  motor_move(RBACK, -distance*ticksperinch);
}

void forward (double distance)
{
  motor_move(LFRONT,distance*ticksperinch);
	motor_move(LBACK, distance*ticksperinch);
  motor_move(RFRONT,distance*ticksperinch);
  motor_move(RBACK, distance*ticksperinch);
}

void intake ()
{
  //This is a guess btw
  motor_move(LINTAKE, 3600);
  motor_move(RINTAKE, 3600);
}

void lift()
{
  motor_move(RARM,600);
  motor_move(LARM,600);
}

void autonomous() {
  setReverse();
  forward(12);
  reverse(-12);
  turnRight(14.137167);
  forward(6);
  intake();
  reverse(-6);
  turnLeft(14.137167);
  forward(12);
  turnLeft(14.137167+9.424778);//63.777 degrees
  forward(52.46);
  intake();
  lift();
  forward(1);
  reverse(1);
}
