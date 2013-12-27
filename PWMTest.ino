/*
 RC PulseIn Joystick
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */

int rightJoystickX;
int leftJoystickY;
//Max rightJoystickX = 546 
//Low rightJoystickX = - 521
//rightJoystickX total = 1067

//Max leftJoystickY = 571
//Low leftJoystickY = - 517
//leftJoystickY total = 1088
void setup() {

pinMode(6, INPUT); // Set our input pins as such
pinMode(5, INPUT); // Set our input pins as such
Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {
  
  rightJoystickX = pulseIn(6, HIGH, 25000); // Read the pulse width of 
  leftJoystickY = pulseIn(5, HIGH, 25000); // Read the pulse width of  
  rightJoystickX = rightJoystickX - 1376;
  leftJoystickY = leftJoystickY - 1523;
  if(abs(rightJoystickX) > 50){
    Serial.println("You pressed rightJoystickX");
  }
  else{
    rightJoystickX = 0;
  }
  if(abs(leftJoystickY) > 50){
    Serial.println("You pressed leftJoystickY");
  }
  else{
    leftJoystickY = 0;
  }
  Serial.print("rightJoystickX :"); 
  Serial.println(rightJoystickX);
  Serial.print("leftJoystickY :");
  Serial.println(leftJoystickY);
//Serial.println(map(rightJoystickX, 1000,2000,-500,500)); // center at 0
//Serial.println(map(leftJoystickY, 1000,2000,-500,500)); // center at 0

Serial.println(); //make some room

delay(1000);// I put this here just to make the terminal 
           // window happier
}


