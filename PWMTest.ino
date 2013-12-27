/*
 Based on Nick Poole's RC PulseIn Joystick
 */
 
int RJX = 6; //Right Joystick X
int LJY = 5; //Left Joystick Y
int RJXVal;
int LJYVal;
//Max right joystick X = 546 
//Low right joystick X = - 521
//Total right joystick X = 1067

//Max left joystick Y = 571
//Low left joystick Y = - 517
//Total left joystick Y = 1088
void setup() {

  pinMode(RJX, INPUT); // Set RSX as an input
  pinMode(LJY, INPUT); // Set LSY as an input
  Serial.begin(9600); // Startup serial
}

void loop() {
  
  RJXVal= pulseIn(RJX, HIGH, 25000); // Read the pulse width of right joystick X
  LJYVal = pulseIn(LJY, HIGH, 25000); // Read the pulse width of left joystick Y
  RJXVal = RJXVal - 1376; // Centers RSXVal
  LJYVal = LJXVal - 1523; // Centers LSYVal
  if(abs(RJXVal) > 50){ //Checks if RJXVal is over 50
    Serial.println("You pressed RJXVal"); //If so then a message is printed
  }
  else{ //Otherwise
    RJXVal = 0; // Set RJXVal to 0
  }
  if(abs(LSYVal) > 50){ //Checks if LJYVal is over 50
    Serial.println("You pressed LSYVal"); //If so then a message is printed
  }
  else{ //Otherwise
    LSYVal = 0; // Set LJYVal to 0
  }
  Serial.print("RJXVal :"); 
  Serial.println(RJXVal);
  Serial.print("LSYVal :");
  Serial.println(LSYVal);
//Serial.println(map(RJXVal, 1000,2000,-500,500)); // center at 0
//Serial.println(map(LSYVal, 1000,2000,-500,500)); // center at 0

Serial.println(); //Prints a line into the serial monitor.

delay(1000);// Waits a second to slow down spam in the serial monitor;
}


