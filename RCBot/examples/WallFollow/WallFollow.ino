// ---------------------------------------------------------------------------
// Example RCBot library sketch that Wall Follow.
// ---------------------------------------------------------------------------

#include <RCBot.h>
RCBot rcbot;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see results.
  //rcbot.setMotor(2,3,4,5);//Motor Left Plus,Motor Left Minus,Motor Right Plus,Motor Right Minus
  rcbot.setMotors(2,3,4,5,6,7);//Motor Left Plus,Motor Left Minus,Motor Right Plus,Motor Right Minus,Motor Left Enable,Motor Right Enable
  rcbot.setMotorSpeed(255,255,100,100,150,150);//Left High Speed,Right High Speed,Left Low Speed,Right Low Speed,Left Normal Speed,Right Normal Speed
  rcbot.SonarSet(8,9,10,11,6,10,20);//Left Sonar Trigger,Right Sonar Trigger,Left Sonar Echo,Right Sonar Echo,The difference between the robot and wall,Kp,if wall is not detected the error
}

void loop() {
  Serial.println(rcbot.SonarRaw(1)); // prints wall and robots distance//Right Sensor
  rcbot.WallFollow(1);//Follows Right Wall
  //Serial.println(rcbot.SonarRaw(0)); // prints wall and robots distance//Left Sensor
  //rcbot.WallFollow(0);//Follows Left Wall
}
