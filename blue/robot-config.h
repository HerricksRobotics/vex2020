using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices externed to be used in all other files in the project
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor_group LDRIVE;
extern motor_group RDRIVE;
extern motor_group ARM;
extern motor CLAW;
extern signature VISION7__ORANGECUBE;
extern signature VISION7__PURPLECUBE;
extern vision VISION7;
extern bumper bumperA;
extern limit limitB;
extern sonar RangeFinderC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );