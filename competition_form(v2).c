#pragma config(Motor,  port1,           BL_BASE,       tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           FL_BASE,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           TL_LIFT,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           CLAW,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           TR_LIFT,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FR_BASE,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          BR_BASE,       tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

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

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  //AUTON WILL BE ADDED LATER
  AutonomousCodePlaceholderForTesting();
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

task usercontrol()
{
// Variables to help out with choosing the drive control. Drive control is defaulted to Tank Control
int tank = 1;
int arcade = 0;
  while (true)
  {

		//THIS IS FOR THE NEW ROBOT

		/*CHANGE LOG:

		9/20/2018: Changed the condition in the while loop from 1==1 to true- it's a matter of personal preference, but either works.
		Changed the control structure from if/else if/else form to a if/else if/else form. Changed commands in lift to mirror the control
		of the base. Are the units in the wait command seconds? Debating the removal of the stopMotor/motor = 0 and commands from within
		the up and down functions for the lift. Removed the == 1 from the button control, its uneccesary. No auton yet.
		Adding code for the claw.

		9/25/2018: Moved the main driver code into a competition template to get started on auton as soon as possible.
		Added a new way to access between Tank Control and Arcade Control with a switch of a button. Button 7L == Arcade
		while button 7R == Tank.
		Adjusted the speed of the motors for the lift and for the claw. The speeds should be controllable enough to start
		close looping the claw a little more.
		Also changed the if else statement to a if statement so there will be less of a pause while moving the robot.

		9/27/2018: The toggle between tank and arcade control is a good addition, though Kolby is ok with just tank.
		Changed the names of the variables in the tank/arcade toggle to be more self-explanatory.
		Not too worried about functionality that can be fixed with testing yet.
		Changed the format back to if/else if/else because the current  setup will cause the robot to be unable to move the lift upwards,
		as the second if/else statement will cause the motor speeds to always be negative or 0.
		Made changes to the claw code as well.

		*/


	//NOTE: this is for DRIVER CONTROL
		if(vexRT[Btn7R]==1)
			{
			tank=1;
			arcade=0;
			}
if(vexRT[Btn7L]==1)
		{
		tank=0;
		arcade=1;
		}
// This is Tank Control
if(tank)
		{
		motor[BL_BASE] = vexRT[Ch3];
		motor[FL_BASE] = vexRT[Ch3];
		motor[BR_BASE] = vexRT[Ch2];
		motor[FR_BASE] = vexRT[Ch2];
		}

//This is Arcade Control
if(arcade)
		{
		motor[BL_BASE] = (vexRT[Ch3]+vexRT[Ch4])/2;
		motor[FL_BASE] = (vexRT[Ch3]+vexRT[Ch4])/2;
		motor[BR_BASE] = (vexRT[Ch3]-vexRT[Ch4])/2;
		motor[FR_BASE] = (vexRT[Ch3]-vexRT[Ch4])/2;
		}


		//start of LIFT CONTROL
		if(vexRT[Btn8U])//moves lift up
		{
			motor[TL_LIFT] = 63.5;
			motor[TR_LIFT] = 63.5;
		}
		else if(vexRT[Btn8D])//moves lift down
		{
			motor[TL_LIFT] = -63.5;
			motor[TR_LIFT] = -63.5;
		}
		else//sets speed of lift motors to zero
		{
			motor[TL_LIFT] = 0;
			motor[TR_LIFT] = 0;
		}
		//end of LIFT control


		//start of CLAW control
			if(vexRT[Btn6U]==1)
	  {
				motor[CLAW] = 37.5;
		}

		else if(vexRT[Btn6D]){
			motor[CLAW] = -37.5;
		}

		else
		{
			motor[CLAW] = 0;
		}
		//end of CLAW control

  }
}
