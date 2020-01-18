#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;
using brake = brakeType;
// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
//left drive initialization
motor LFRONT = motor(PORT1, ratio18_1, false);
motor LBACK = motor(PORT2, ratio18_1, false);
motor_group LDRIVE = motor_group(LFRONT, LBACK);

//right drive initialization
motor RFRONT = motor(PORT11, ratio18_1, true); 
motor RBACK = motor(PORT12, ratio18_1, true); 
motor_group RDRIVE = motor_group(RFRONT, RBACK);

//intake initialization
motor LINTAKE = motor(PORT9, ratio18_1, false);
motor RINTAKE = motor(PORT10, ratio18_1, true);
motor_group INTAKE = motor_group(RINTAKE,LINTAKE);

//arm initialization
motor RLIFT = motor(PORT16, ratio18_1, true); 
motor LLIFT = motor(PORT17, ratio18_1, false); 
motor_group LIFT = motor_group(RLIFT, LLIFT);

//sensor initialization
vision VISION7 = vision(PORT7, 50);
bumper bumperA = bumper(Brain.ThreeWirePort.A);
limit limitB = limit(Brain.ThreeWirePort.B);
sonar RangeFinderC = sonar(Brain.ThreeWirePort.C);

//drivetrain initialization
drivetrain Drivetrain = drivetrain(LDRIVE, RDRIVE, 319.19, 457.2, 10.921999999999999, mm, 1);

//controller initialization
controller Controller1 = controller(primary);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  LIFT.stop(brake::hold);
  LDRIVE.stop(brake::hold);
  RDRIVE.stop(brake::hold);
}