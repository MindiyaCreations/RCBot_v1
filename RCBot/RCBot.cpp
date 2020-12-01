/*
  RCBot.h - Library for RCBot.
  Created by Mindiya Karunasinghe, April 13, 2019.
  Private library
*/
#include "Arduino.h"
#include "RCBot.h"
#include "NewPing.h"

void RCBot::setMotor(int A1,int A2,int C1,int C2){
	pinMode(A1,OUTPUT);
	pinMode(A2,OUTPUT);
	pinMode(C1,OUTPUT);
	pinMode(C2,OUTPUT);
	LP = A1;
	LM = A2;
	RP = C1;
	RM = C2;
	motorType = 0;
}

void RCBot::setMotors(int A1,int A2,int C1,int C2,int E1,int E2){
	pinMode(A1,OUTPUT);
	pinMode(A2,OUTPUT);
	pinMode(C1,OUTPUT);
	pinMode(C2,OUTPUT);
	pinMode(E1,OUTPUT);
	pinMode(E2,OUTPUT);
	LP = A1;
	LM = A2;
	RP = C1;
	RM = C2;
	Enable1 = E1;
	Enable2 = E2;
	motorType = 1;
}

void RCBot::setSensor(int s1,int s2,int s3,int s4,int s5,int s6,int s7,int s8){
	pinMode(s1,INPUT);
	pinMode(s2,INPUT);
	pinMode(s3,INPUT);
	pinMode(s4,INPUT);
	pinMode(s5,INPUT);
	pinMode(s6,INPUT);
	pinMode(s7,INPUT);
	pinMode(s8,INPUT);
	S1 = s1;
	S2 = s2;
	S3 = s3;
	S4 = s4;
	S5 = s5;
	S6 = s6;
	S7 = s7;
	S8 = s8;
}

void RCBot::setLineColour(bool color){
	LineBlack = color;
}

void RCBot::setPID(float p,float i,float d){
	P = p;
	I = i;
	D = d;
}

void RCBot::setMotorSpeed(int max1,int max2,int min1,int min2,int norm1,int norm2){
	MaxL = max1;
	MaxR = max2;
	MinL = min1;
	MinR = min2;
	NormalL = norm1;
	NormalR = norm2;
}

long RCBot::GetLine(){
	LinePos = 0;
	if(LineBlack == 1){
		if(analogRead(S1) > Threshold){
			LinePos = LinePos + 10000000;
		}
		if(analogRead(S2) > Threshold){
			LinePos = LinePos + 1000000;
		}
		if(analogRead(S3) > Threshold){
			LinePos = LinePos + 100000;
		}
		if(analogRead(S4) > Threshold){
			LinePos = LinePos + 10000;
		}
		if(analogRead(S5) > Threshold){
			LinePos = LinePos + 1000;
		}
		if(analogRead(S6) > Threshold){
			LinePos = LinePos + 100;
		}
		if(analogRead(S7) > Threshold){
			LinePos = LinePos + 10;
		}
		if(analogRead(S8) > Threshold){
			LinePos = LinePos + 1;
		}
	}
	else{
		if(analogRead(S1) < Threshold){
			LinePos = LinePos + 10000000;
		}
		if(analogRead(S2) < Threshold){
			LinePos = LinePos + 1000000;
		}
		if(analogRead(S3) < Threshold){
			LinePos = LinePos + 100000;
		}
		if(analogRead(S4) < Threshold){
			LinePos = LinePos + 10000;
		}
		if(analogRead(S5) < Threshold){
			LinePos = LinePos + 1000;
		}
		if(analogRead(S6) < Threshold){
			LinePos = LinePos + 100;
		}
		if(analogRead(S7) < Threshold){
			LinePos = LinePos + 10;
		}
		if(analogRead(S8) < Threshold){
			LinePos = LinePos + 1;
		}
	}
	return LinePos;
}

void RCBot::run(int M1,int M2,int M3,int M4,int M5,int M6){
	if(motorType){
		digitalWrite(LP,M1);
		digitalWrite(LM,M2);
		digitalWrite(RP,M3);
		digitalWrite(RM,M4);
		analogWrite(Enable1,M5);
		analogWrite(Enable2,M6);
	}
	else{
		if(M1 == 1){
			analogWrite(LP,M5);
			analogWrite(LM,0);
		}
		else{
			analogWrite(LP,0);
			analogWrite(LM,M5);
		}
		if(M3 == 1){
			analogWrite(RP,M6);
			analogWrite(RM,0);
		}
		else{
			analogWrite(RP,0);
			analogWrite(RM,M6);
		}
	}
}

void RCBot::Forward(int time){
	run(1,0,1,0,NormalL,NormalR);
	delay(time);
}

void RCBot::Backward(int time){
	run(0,1,0,1,NormalL,NormalR);
	delay(time);
}

void RCBot::Right(int time){
	run(1,0,0,1,NormalL,NormalR);
	delay(time);
}

void RCBot::Left(int time){
	run(0,1,1,0,NormalL,NormalR);
	delay(time);
}

void RCBot::Stop(){
	run(1,1,1,1,255,255);
}

void RCBot::ForwardUntilAllBlack(){
	while(GetLine() != 11111111){
		run(1,0,1,0,NormalL,NormalR);
	}
}

void RCBot::BackwardUntilAllBlack(){
	while(GetLine() != 11111111){
		run(0,1,0,1,NormalL,NormalR);
	}
}

void RCBot::ForwardUntilAllWhite(){
	while(GetLine() != 00000000){
		run(1,0,1,0,NormalL,NormalR);
	}
}

void RCBot::BackwardUntilAllWhite(){
	while(GetLine() != 00000000){
		run(0,1,0,1,NormalL,NormalR);
	}
}

void RCBot::RightCorretlyToLine(){
	while(GetLine() != 00011000){
		run(1,0,0,1,NormalL,NormalR);
	}
}

void RCBot::LeftCorrectlyToLine(){
	while(GetLine() != 00011000){
		run(0,1,1,0,NormalL,NormalR);
	}
}

int RCBot::GetLineError(){
	Error = 0;
	if(LineBlack == 1){
		if(analogRead(S1) > Threshold){
			Error = Error + 4;
		}
		if(analogRead(S2) > Threshold){
			Error = Error + 3;
		}
		if(analogRead(S3) > Threshold){
			Error = Error + 2;
		}
		if(analogRead(S4) > Threshold){
			Error = Error + 1;
		}
		if(analogRead(S5) > Threshold){
			Error = Error - 1;
		}
		if(analogRead(S6) > Threshold){
			Error = Error - 2;
		}
		if(analogRead(S7) > Threshold){
			Error = Error - 3;
		}
		if(analogRead(S8) > Threshold){
			Error = Error - 4;
		}
	}
	else{
		if(analogRead(S1) < Threshold){
			Error = Error + 4;
		}
		if(analogRead(S2) < Threshold){
			Error = Error + 3;
		}
		if(analogRead(S3) < Threshold){
			Error = Error + 2;
		}
		if(analogRead(S4) < Threshold){
			Error = Error + 1;
		}
		if(analogRead(S5) < Threshold){
			Error = Error - 1;
		}
		if(analogRead(S6) < Threshold){
			Error = Error - 2;
		}
		if(analogRead(S7) < Threshold){
			Error = Error - 3;
		}
		if(analogRead(S8) < Threshold){
			Error = Error - 4;
		}
	}
	return Error;
}

void RCBot::LineFollow(){
	if ((GetLine() == 00011111) || (GetLine() == 00001111))
	{
		RightCorretlyToLine();
	}
	else if ((GetLine() == 11111000) || (GetLine() == 11110000))
	{
		LeftCorrectlyToLine();
	}
	else{
		PID = 0;
		Errors = GetLineError();
		Time = millis();
		PID = Errors * P;
		PID = PID + (((prevErrors - Errors) * ((prevTime - Time) / 1000)) * I);
		PID = PID + ((prevErrors - Errors) * D);
		if((NormalL - PID) < MinL){
			SpeedL = MinL;
		}
		else if((NormalL - PID) > MaxL){
			SpeedL = MaxL;
		}
		else{
			SpeedL = NormalL + PID;
		}
		if((NormalR + PID) < MinR){
			SpeedR = MinR;
		}
		else if((NormalR + PID) > MaxR){
			SpeedR = MaxR;
		}
		else{
			SpeedR = NormalR + PID;;
		}
		run(1,0,1,0,SpeedL,SpeedR);
		prevErrors = Errors;
		prevTime = Time;
	}
}

void RCBot::SonarSet(int trigL,int trigR,int echoL,int echoR,int error,float propotional,int zero){
	TrigL = trigL;
	TrigR = trigR;
	EchoL = echoL;
	EchoR = echoR;
	ErrorSonar = error;
	SonarP = propotional;
	NoSonar = zero;
}

int RCBot::SonarRaw(int i){
	NewPing LeftSonar(TrigL, EchoL, 100);
	NewPing RightSonar(TrigR, EchoR, 100);
	if(i == 0){
		return LeftSonar.ping_cm();
	}
	else{
		return RightSonar.ping_cm();
	}
}

void RCBot::WallFollow(bool right){
	if (right)
	{
		if(SonarRaw(1) == 0){
			run(1,0,1,0,SpeedL + NoSonar,SpeedR);
		}
		else{
			ErrorCurrentSonar = (SonarRaw(1) - ErrorSonar) * SonarP;
			if((NormalL + ErrorCurrentSonar) < MinL){
				SpeedL = MinL;
			}
			else if((NormalL + ErrorCurrentSonar) > MaxL){
				SpeedL = MaxL;
			}
			else{
				SpeedL = NormalL + ErrorCurrentSonar;
			}
			if((NormalR - ErrorCurrentSonar) < MinR){
				SpeedR = MinR;
			}
			else if((NormalR - ErrorCurrentSonar) > MaxR){
				SpeedR = MaxR;
			}
			else{
				SpeedR = NormalR - ErrorCurrentSonar;
			}
			run(1,0,1,0,SpeedL,SpeedR);
		}
	}
	else{
		if(SonarRaw(0) == 0){
			run(1,0,1,0,SpeedL,SpeedR + NoSonar);
		}
		else{
			ErrorCurrentSonar = (SonarRaw(0) - ErrorSonar) * SonarP;
			if((NormalL - ErrorCurrentSonar) < MinL){
				SpeedL = MinL;
			}
			else if((NormalL - ErrorCurrentSonar) > MaxL){
				SpeedL = MaxL;
			}
			else{
				SpeedL = NormalL - ErrorCurrentSonar;
			}
			if((NormalR + ErrorCurrentSonar) < MinR){
				SpeedR = MinR;
			}
			else if((NormalR + ErrorCurrentSonar) > MaxR){
				SpeedR = MaxR;
			}
			else{
				SpeedR = NormalR + ErrorCurrentSonar;
			}
			run(1,0,1,0,SpeedL,SpeedR);
		}
	}
}