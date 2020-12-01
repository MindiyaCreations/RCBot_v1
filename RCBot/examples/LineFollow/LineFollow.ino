// ---------------------------------------------------------------------------
// Example RCBot library sketch that Line Follows in black line.
// ---------------------------------------------------------------------------

#include <RCBot.h>
RCBot rcbot;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see results.
  //rcbot.setMotor(2,3,4,5);//Motor Left Plus,Motor Left Minus,Motor Right Plus,Motor Right Minus
  rcbot.setMotors(2,3,4,5,6,7);//Motor Left Plus,Motor Left Minus,Motor Right Plus,Motor Right Minus,Motor Left Enable,Motor Right Enable
  rcbot.setSensor(0,1,2,3,4,5,6,7);//Analog pin numbers for Sensors(Left to Right.There should be 8 sensors.
  rcbot.setMotorSpeed(255,255,100,100,150,150);//Left High Speed,Right High Speed,Left Low Speed,Right Low Speed,Left Normal Speed,Right Normal Speed
  rcbot.setPID(1.2,3.2,13.5);//Kp,Ki,Kd
  rcbot.setLineColour(1);//Set line colour to Black
}

void loop() {
  Serial.println(rcbot.GetLine()); // prints robots position
  rcbot.LineFollow();
}
