/*
  RCBot.h - Library for RCBot.
  Created by Mindiya Karunasinghe, April 13, 2019.
  Private library
*/
#ifndef RCBot_h
#define RCBot_h

#include "Arduino.h"
#include "NewPing.h"

class RCBot
{
  public:
    void setMotor(int A1,int A2,int C1,int C2);//Left Plus/Left Minus/Right Plus/Right Minus
    void setMotors(int A1,int A2,int C1,int C2,int E1,int E2);//Left Plus/Left Minus/Right Plus/Right Minus/Left PWM/Right PWM
    void setSensor(int s1,int s2,int s3,int s4,int s5,int s6,int s7,int s8);//Left Sensor to Right Sensor
    void setLineColour(bool color);//Black = 1/White = 0
    void setMotorSpeed(int max1,int max2,int min1,int min2,int norm1,int norm2);//Max L/Max R/Min L/Min R/Normal L/Normal R
    int GetLineError();//int Get error -2/+1
    void setPID(float p,float i,float d);//P,I,D values
    void Forward(int time);//Go Forward until the time ends in milliseconds
    void Backward(int time);//Go Backward until the time ends in milliseconds
    void Right(int time);//Turn Right until the time ends in milliseconds
    void Left(int time);//Turn Left until the time ends in milliseconds
    void Stop();//Stop Moving
    long GetLine();//Get Line like 10001100
    void LineFollow();//Line Follow
    void ForwardUntilAllBlack();//Go Forward until finds line
    void BackwardUntilAllBlack();//Go Backward until finds line
    void ForwardUntilAllWhite();//Go Forward until the all of the line is missing
    void BackwardUntilAllWhite();//Go Backward until the all of the line is missing
    void RightCorretlyToLine();//Turn Right until the line is found
    void LeftCorrectlyToLine();//Turn Left until the line is found
    void SonarSet(int trigL,int trigR,int echoL,int echoR,int error,float propotional,int zero);//trigL = pin of trig Left sensor//trigR = pin of trig Right sensor//echoL = pin of echo Left sensor//echoR = pin of echo Right sensor
    int SonarRaw(int i);//i == 0 shows left sensor//i == 1 shows right sensor
    void WallFollow(bool right);//Wall follow //if wall following right wall = true//if wall following left wall
  private:
    int LP,LM,RP,RM,Enable1,Enable2;
    int MaxL,MaxR,MinL,MinR,NormalL,NormalR;
    bool motorType;
    int S1,S2,S3,S4,S5,S6,S7,S8;
    bool LineBlack;
    int Threshold;
    float P,I,D;
    int Errors,PID,prevErrors;
    int Error;
    long LinePos;
    void run(int M1,int M2,int M3,int M4,int M5,int M6);//Motor Left Plus/Motor Left Minus/Motor Right Plus/Motor Right Minus/Left PWM/Right PWM
    unsigned long prevTime,Time;
    int SpeedL,SpeedR;
    int ErrorSonar,ErrorCurrentSonar,SonarP,NoSonar;
    int TrigL,TrigR,EchoR,EchoL;
};

#endif