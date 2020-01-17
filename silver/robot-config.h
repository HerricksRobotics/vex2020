using namespace vex;

extern brain Brain;

using signature = vision::signature;
// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern motor_group ArmSmart;
extern motor_group ClawSmart;
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
