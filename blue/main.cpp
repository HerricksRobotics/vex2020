/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 11, 12
// Claw                 motor_group   16, 17
// Arm                  motor         9
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "vision.h"
using namespace vex;

// A global instance of competition
vex::competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  while (RangeFinderC.distance(mm) / 25.4 > 5) {
    LDRIVE.spin(forward);
    RDRIVE.spin(forward);
    LDRIVE.setVelocity(90, percent);
    RDRIVE.setVelocity(90, percent);
  }
  LDRIVE.setVelocity(0, percent);
  RDRIVE.setVelocity(0, percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code
  static int DEADBAND = 35;
  while (1) {
    Brain.Screen.clearLine();

    // arm movement based on controller right joystick y axis
    int ArmSpeed = Controller1.Axis2.position();

    if (abs(ArmSpeed) > DEADBAND) {
      ARM.setVelocity(ArmSpeed, percent);
      ARM.spin(forward);
    } else {
      ARM.setVelocity(0, percent);
    }

    int ClawSpeed = 30;

    // claw movement using L1 and L2
    if (Controller1.ButtonL1.pressing() == true) {
      CLAW.setVelocity(ClawSpeed, percent);
      CLAW.spin(forward);
    } else if (Controller1.ButtonL2.pressing() == true) {
      CLAW.setVelocity(ClawSpeed, percent);
      CLAW.spin(reverse);
    } else {
      CLAW.setVelocity(0, percent);
    }

    int drivetrainLeftSideSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position();
    int drivetrainRightSideSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();

    // check if the value is inside of the DEADBAND range
    if (abs(drivetrainLeftSideSpeed) > DEADBAND) {
      LDRIVE.setVelocity(drivetrainLeftSideSpeed, percent);
      LDRIVE.spin(forward);
    } else {
      LDRIVE.setVelocity(0, percent);
    }

    // check if the value is inside of the DEADBAND range
    if (abs(drivetrainRightSideSpeed) > DEADBAND) {

      RDRIVE.setVelocity(drivetrainRightSideSpeed, percent);
      RDRIVE.spin(forward);

    } else {

      RDRIVE.setVelocity(0, percent);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
