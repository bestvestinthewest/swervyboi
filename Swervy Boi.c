#pragma config(Motor,  port1,           LFrontDrive,   tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port2,           LFrontRotate,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           RFrontDrive,   tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RFrontRotate,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           LBackDrive,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           LBackRotate,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           RBackDrive,    tmotorVex393, openLoop)
#pragma config(Motor,  port8,           RBackRotate,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           claw,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          armRotate,     tmotorVex393, openLoop)

task main(){

	while(true) {
		motor[port1] = -vexRT(Ch2);
		motor[port3] = -vexRT(Ch2);
		motor[port5] = -vexRT(Ch2);
		motor[port7] = -vexRT(Ch2);

		switch (vexRT(Ch1)) {
		case 127:
			motor[port2] = 63.5;
			motor[port4] = -63.5;
			motor[port6] = -63.5;
			motor[port8] = 63.5;
			wait1Msec(100);
			motor[port1] = 117;
			motor[port3] = -117;
			motor[port5] = -117;
			motor[port7] = 117;
			break;
		case -128:
			motor[port2] = 63.5;
			motor[port4] = -63.5;
			motor[port6] = -63.5;
			motor[port8] = 63.5;
			wait1Msec(100);
			motor[port1] = -117;
			motor[port3] = 117;
			motor[port5] = 117;
			motor[port7] = -117;
		default:
			motor[port1] = 0;
			motor[port3] = 0;
			motor[port5] = 0;
			motor[port7] = 0;
			motor[port2] = 0;
			motor[port4] = 0;
			motor[port6] = 0;
			motor[port8] = 0;
		}

		if (vexRT(Ch3) < 1 && vexRT(Ch4) > 1) {
			motor[port2] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port4] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port6] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port8] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
		}

		else if (vexRT(Ch3) < 1 && vexRT(Ch4) < 1) {
			motor[port2] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port4] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port6] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port8] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
		}
		else if (vexRT(Ch3) > 20 && vexRT(Ch4) < 1) {
			motor[port2] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port4] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port6] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			motor[port8] = (atan2(-vexRT(Ch3), vexRT(Ch4))) / (PI/2) * 127;
			bMotorFlippedMode[port1] = true;
			bMotorFlippedMode[port3] = true;
			bMotorFlippedMode[port5] = true;
			bMotorFlippedMode[port7] = true;
		}

		else if (vexRT(Ch3) > 20 && vexRT(Ch4) > 1) {
			motor[port2] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port4] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port6] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			motor[port8] = (atan2(-vexRT(Ch3), vexRT(Ch4))) + PI / (PI) * 127;
			bMotorFlippedMode[port1] = true;
			bMotorFlippedMode[port3] = true;
			bMotorFlippedMode[port5] = true;
			bMotorFlippedMode[port7] = true;
		}

		else {
			motor[port2] = 0;
			motor[port4] = 0;
			motor[port6] = 0;
			motor[port8] = 0;
			motor[port3] = 0;
			motor[port5] = 0;
			motor[port7] = 0;
			motor[port1] = 0;
			bMotorFlippedMode[port1] = false;
			bMotorFlippedMode[port3] = false;
			bMotorFlippedMode[port5] = false;
			bMotorFlippedMode[port7] = false;
		}

		if (vexRT(Btn5U) == 1) {
			motor[armRotate] = 127;
		}
		else if (vexRT(Btn5D) == 1) {
			motor[armRotate] = -127;
		}
		else {
			motor[armRotate] = 0;
		}

		if(vexRT[Btn6U] == 1)
		{
			motor[claw] = 127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[claw] = -127;
		}
		else
		{
			motor[claw] = 0;
		}
	}
}
