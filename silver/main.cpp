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
// Drivetrain           drivetrain    1, 2, 9, 8
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "vision.h"
using namespace vex;
using brake = brakeType;

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
  if (bumperA.pressing()) {
    Brain.Screen.print("bumper");
  }
  if (limitB.pressing()) {
    Brain.Screen.print("limit");
  }
}
/*while (1) {
    VISION7.takeSnapshot(PURPLECUBE);
    if (VISION7.objectCount > 0) {
      if (VISION7.largestObject.width > 10 && VISION7.largestObject.height > 10)
{ Brain.Screen.print(VISION7.objectCount);
        Brain.Screen.print(VISION7.largestObject.centerX);
        Brain.Screen.print(VISION7.largestObject.centerY);
        while (VISION7.objectCount > 0) {
          RightDriveSmart.setVelocity(60, percent);
          RightDriveSmart.spin(reverse);
          LeftDriveSmart.setVelocity(60, percent);
          LeftDriveSmart.spin(forward);
        }
      }
    } else {
      RightDriveSmart.setVelocity(60, percent);
      RightDriveSmart.spinFor(forward, 45, degrees);
      LeftDriveSmart.setVelocity(60, percent);
      LeftDriveSmart.spinFor(reverse, 45, degrees);
    }
}
*/

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
  // User control code here, inside the loop
  bool DrivetrainLNeedsToBeStopped_Controller1 = true;
  bool DrivetrainRNeedsToBeStopped_Controller1 = true;
  static int deadband = 35;
  while (1) {
    // calculate the drivetrain motor velocities from the controller joystick
    // axies left = Axis3 + Axis1 right = Axis3 - Axis1

    if (bumperA.pressing()) {
      Brain.Screen.drawRectangle(0, 0, 500, 400, green);
    }
    if (limitB.pressing()) {
      Brain.Screen.drawRectangle(0, 0, 500, 400, blue);
      vexDelay(1000);
      Brain.Screen.clearScreen();
    }

    Brain.Screen.print(RangeFinderC.distance(mm) / 25.4);
    vexDelay(200);
    Brain.Screen.clearLine();

    int ArmSpeed = Controller1.Axis2.position();

    if (abs(ArmSpeed) > deadband) {
      ArmSmart.setVelocity(ArmSpeed/2, percent);
      ArmSmart.spin(forward);
    } else {
      ArmSmart.setVelocity(0, percent);
      ArmSmart.stop(brake::hold);
    }

    int ClawSpeed = 60;

    if (Controller1.ButtonL1.pressing() == true) {
      ClawSmart.setVelocity(ClawSpeed, percent);
      ClawSmart.spin(forward);
    } else if (Controller1.ButtonL2.pressing() == true) {
      ClawSmart.setVelocity(ClawSpeed, percent);
      ClawSmart.spin(reverse);
    }
    else {
      ClawSmart.setVelocity(0, percent);
      LeftDriveSmart.stop(brake::hold);
    } 


    int drivetrainLeftSideSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position();
    int drivetrainRightSideSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();
    // check if the value is inside of the deadband range
    if (abs(drivetrainLeftSideSpeed) > deadband) {
      // check if the left motor has already been stopped
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        // stop the left drive motor
        LeftDriveSmart.stop(brake::hold);
        // tell the code that the left motor has been stopped
        DrivetrainLNeedsToBeStopped_Controller1 = false;
      }
    } else {
      // reset the toggle so that the deadband code knows to stop the left motor
      // next time the input is in the deadband range
      DrivetrainLNeedsToBeStopped_Controller1 = true;
    }
    // check if the value is inside of the deadband range
    if (abs(drivetrainRightSideSpeed) > deadband) {
      // check if the right motor has already been stopped
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        // stop the right drive motor
        RightDriveSmart.stop(brake::hold);
        // tell the code that the right motor has been stopped
        DrivetrainRNeedsToBeStopped_Controller1 = false;
      }
    } else {
      // reset the toggle so that the deadband code knows to stop the right
      // motor next time the input is in the deadband range
      DrivetrainRNeedsToBeStopped_Controller1 = true;
    }
    // only tell the left drive motor to spin if the values are not in the
    // deadband range
    if (DrivetrainLNeedsToBeStopped_Controller1) {
      LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
      LeftDriveSmart.spin(forward);
    }
    // only tell the right drive motor to spin if the values are not in the
    // deadband range
    if (DrivetrainRNeedsToBeStopped_Controller1) {
      RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
      RightDriveSmart.spin(forward);
    }
    /*VISION7.takeSnapshot(PURPLECUBE);
    if (VISION7.objectCount > 0) {
      if (VISION7.largestObject.width > 10 && VISION7.largestObject.height > 10)
    { Brain.Screen.print(VISION7.objectCount);
        Brain.Screen.print(VISION7.largestObject.centerX);
        Brain.Screen.print(VISION7.largestObject.centerY);
      }
    }*/
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
