#pragma config(Motor,  port1,           FR,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           flip,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//THIS IS FOR NEW ROBOT

//NOTE: HAVE DIFFERENT AUTONS DEPENDING ON THE SIDE OF THE FIELD
//each square has a width of two feet
/*CHANGE LOG:
9/20/2018: First time more code other than potentiometer has been added. The convertToPot function has been coded.
NEED TO MEASURE RADIUS OF WHEEL TO CONVERT CIRCULAR MOTION INTO LINEAR MOTION!!! The idea is to have all required PID
within functions to keep the running code itself as clean as possible.

9/28/2018: Primary question is whether or not we will actually have sensors. Adding in some PID pseudocode to some of the various void functions (driveDistanceInInches, )
Changing auton now that I have a better understanding of the flippy mechanism*/

//AUTON SELECT WILL PROBABLY BE COMPLETED THROUGH LED METHOD

//NOTE: Potentiometers can turn approx 265 degrees, not 360! Output values 0-4095 to VEX Cortex
//Pre-Condition: given a float number of degrees
//Post-condition: number of degrees is converted to potentiometer units
float convertToPot(float degree){
		return (degree*265)/4095;
}

/*NOTE: uses encoders! 360 degrees in one turn in the wheel, need to measure approx how far the robot goes in one rotation of the
the wheel. Currently is basic, but will implement some PID with this beautiful baby later.
*/
//Pre-Condition: robot is somewhere on the field and given a distance != 0
//Post-Condition: robot has driven forward/backward distance inches
void driveDistanceInInches(float distance){
	/*PSEUDO CODE (until wheel is measured):

	//CONVERSION OF DISTANCE INTO SENSOR UNITS
	//value = (distance*360)/circumference of wheel


	if(distance > 0){//positive distance, robot drives forward distance in inches
		while(SensorValue[encoder] != value){
			motor[FL] = 127;
			motor[FR] = 127;
			motor[BR] = 127;
			motor[BL] = 127;
		}
	}

	//negative distance, robot drives backward distance in inches
	else{
		while(SensorValue[encoder] != value){
			motor[FL] = -127;
			motor[FR] = -127;
			motor[BR] = -127;
			motor[BL] = -127;
		}
		SensorValue[encoder] = 0; //resets encoder value so it can be used again without errors
	}

	*/
}

//Pre-condition: disc is in claw
//Post-Condition: disc is flipped over
void flipClaw(){


}

//Pre-Condition: claw is closed
//Post-Condition: claw is opened
void openClaw(){

}

//pre-Condition:claw is open
//post-condition: claw is closed around a cone
void closeClaw(){

}

//IMPLEMENT PID
//pre-condition: robot is facing any direction
//post-condition: robot is facing degrees degrees away from previous point, counterclockwise (right = negative, left = positive)
void turn(float degrees){
	//CONVERSION OF DEGREES OF A ROBOT'S INTO LINEAR DISTANCE
	//value = (degrees*circumference)/360;
	if(degrees > 0){//when given a positive degree, turning LEFT
		/*
		while(SensorValue[encoder] != value){
			motor[FR] = 127;
			motor[BR] = 127;
		}
		*/

}
	else{//when given a negative degree, turning RIGHT
		/*
		while(SensorValue[encoder] != -value){
			motor[FL] = 127;
			motor[BL] = 127;
		}
		*/
}
	//SensorValue[encoder] = 0;
}


task main()
{


while(true){
			//blue
				//if disc is directly diagonal
						//***ALGORITHM***
						//1. make sure robot is aligned facing cone, done on field
						//2. move foward approximately two feet (until discy boi is secured), uses only base motors
						//3. secure disc with claw, uses claw motor
						//4. flip that boi, uses flip motor
						//5. Release disc in claw
						//6. your job is done. go home
						//***PSEUDO CODE***
						//1. Step is completed physically on field, no corresponding code
						//2. driveDistanceInInches(24);
						//3. flipClaw();
						//4. mission complete
				//else
						//***ALGORITHM***
						//1. orient the robot facing away from the net
						//2. move fwd two feet, using base motors
						//3. turn the robot to the right 90 degrees with base motors- probs gonna be the hardest part
						//4. go forward six feet
						//5. secure cone with claw, uses claw motor
						//6. flip that boi, uses flip motor
						//7. release disc
						//8. your job is done. go home
						//***PSEUDO CODE***
						//1. Step is completely physical
						//2. driveDistanceInInches(24);
						//3. turn(-90);
						//4. driveDistanceInInches(72);
						//5. flipClaw();
						//6. mission is complete
			//red is just everything but opposite
	}
}
