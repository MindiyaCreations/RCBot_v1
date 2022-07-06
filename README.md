# RCBot_v1

An Arduino library for Line following and Wall following robots.

```void setMotor(int A1,int A2,int C1,int C2);```<br>
Left Plus/Left Minus/Right Plus/Right Minus

```void setMotors(int A1,int A2,int C1,int C2,int E1,int E2);```<br>
Left Plus/Left Minus/Right Plus/Right Minus/Left PWM/Right PWM

```void setSensor(int s1,int s2,int s3,int s4,int s5,int s6,int s7,int s8);```<br>
Left Sensor to Right Sensor

```void setLineColour(bool color);```<br>
Black = 1/White = 0

```void setMotorSpeed(int max1,int max2,int min1,int min2,int norm1,int norm2);```<br>
Max L/Max R/Min L/Min R/Normal L/Normal R

```int GetLineError();```<br>
int Get error -2/+1

```void setPID(float p,float i,float d);```<br>
P,I,D values

```void Forward(int time);```<br>
Go Forward until the time ends in milliseconds

```void Backward(int time);```<br>
Go Backward until the time ends in milliseconds

```void Right(int time);```<br>
Turn Right until the time ends in milliseconds

```void Left(int time);```<br>
Turn Left until the time ends in milliseconds

```void Stop();```<br>
Stop Moving

```long GetLine();```<br>
Get Line like 10001100

```void LineFollow();```<br>
Line Follow

```void ForwardUntilAllBlack();```<br>
Go Forward until finds line

```void BackwardUntilAllBlack();```<br>
Go Backward until finds line

```void ForwardUntilAllWhite();```<br>
Go Forward until the all of the line is missing

```void BackwardUntilAllWhite();```<br>
Go Backward until the all of the line is missing

```void RightCorretlyToLine();```<br>
Turn Right until the line is found

```void LeftCorrectlyToLine();```<br>
Turn Left until the line is found

```void SonarSet(int trigL,int trigR,int echoL,int echoR,int error,float propotional,int zero);```<br>
trigL = pin of trig Left sensor//trigR = pin of trig Right sensor//echoL = pin of echo Left sensor//echoR = pin of echo Right sensor

```int SonarRaw(int i);```<br>
i == 0 shows left sensor//i == 1 shows right sensor

```void WallFollow(bool right);```<br>
Wall follow
if wall following right wall = true
