// This code uses identical principles to that of the code "Final Draft of Synthetic Heart Rate" with the exception of timed events occuring in the loop
// It was used for the first set of experiments conducted on "demo day", described in the report. It uses a synthetic heart rate rather than the pulse sensor
#include <AFMotor.h> //Include the motor shield library for the DC motors
AF_DCMotor motor(4); //Establish that the 4th motor connection point is the one in use 

float initialBPM = 60; //Set the intial bpm a value. 60 is chosen here as it is within the healthy resting heart range
float currentBPM; //Set the new bpm variable. 60 is chosen here to observe what happens when there is no change in bpm but ay value can be chosen
int waitTime = 0; //Set up the variable waitTime that will be used later

unsigned long startTime;
unsigned long currentTime;
unsigned long priorTime; //Set up the variables that will be used later as counters in the loop function

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);
  motor.run(RELEASE); //Activates the motor in the setup
  currentBPM = 60; //Give the current bpm variable a value. 60 is the chosen starting value for this set of experiments 
}

void loop() {
  startTime = millis(); //Establish a timer for the timed events 
  currentTime = millis(); //Establish a timer for the motor control if statement

  if(startTime >= 00000 && startTime < 10000){ //If the startTime of the loop is greater than 0 seconds and less than 10 seconds, enter this statement 
    currentBPM = 80; //Set the current bpm to be equal to 80 (a 20 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 10000 && startTime < 20000){ //If the startTime of the loop is greater than 10 seconds and less than 20 seconds, enter this statement 
    currentBPM = 100; //Set the current bpm to be equal to 100 (a 40 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 20000 && startTime < 30000){ //If the startTime of the loop is greater than 20 seconds and less than 30 seconds, enter this statement 
    currentBPM = 120; //Set the current bpm to be equal to 120 (a 60 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 30000 && startTime < 35000){ //If the startTime of the loop is greater than 30 seconds and less than 35 seconds, enter this statement 
    currentBPM = 140; //Set the current bpm to be equal to 140 (a 80 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 35000 && startTime < 40000){ //If the startTime of the loop is greater than 35 seconds and less than 40 seconds, enter this statement 
    currentBPM = 150; //Set the current bpm to be equal to 150 (a 90 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 40000 && startTime < 45000){ //If the startTime of the loop is greater than 40 seconds and less than 45 seconds, enter this statement 
    currentBPM = 155; //Set the current bpm to be equal to 155 (a 95 bpm increase) to allow it to enter the fastest band of motor control
  }
  if(startTime >= 45000 && startTime < 50000){ //If the startTime of the loop is greater than 45 seconds and less than 50 seconds, enter this statement 
    currentBPM = 120; //Set the current bpm to be equal to 120 (a 60 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 50000 && startTime < 55000){ //If the startTime of the loop is greater than 50 seconds and less than 55 seconds, enter this statement 
    currentBPM = 90; //Set the current bpm to be equal to 90 (a 30 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 55000 && startTime < 60000){ //If the startTime of the loop is greater than 55 seconds and less than 60 seconds, enter this statement 
    currentBPM = 80; //Set the current bpm to be equal to 80 (a 20 bpm increase) to allow it to enter a different band of motor control
  }
  if(startTime >= 60000){ //If the startTime of the loop is greater than 60 seconds, enter this statement 
    currentBPM = 60; //Set the current bpm to be equal to 60 to stop the motor from activating again (as the intial and current bpm values are equal)
  }

  if((currentTime - priorTime) >= waitTime){ //If the difference between the currentTime and the priorTime is greater than the waitTime then the if statement may be entered
    if((currentBPM - initialBPM) >= 15 && (currentBPM - initialBPM) < 30){ //If the current bpm is higher than the initial bpm by 15 to 29 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 3500; //Set the time to wait between entering the if statement again (and starting the motor) to 3.5 seconds 
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }
    if((currentBPM - initialBPM) >= 30 && (currentBPM - initialBPM) < 45){ //If the current bpm is higher than the initial bpm by 30 to 44 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 3000; //Set the time to wait between entering the if statement again (and starting the motor) to 3 seconds 
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 45 && (currentBPM - initialBPM) < 60){ //If the current bpm is higher than the initial bpm by 45 to 59 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second 
        waitTime = 2500; //Set the time to wait between entering the if statement again (and starting the motor) to 2.5 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 60 && (currentBPM - initialBPM) < 75){ //If the current bpm is higher than the initial bpm by 60 to 74 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 2000; //Set the time to wait between entering the if statement again (and starting the motor) to 2 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 75 && (currentBPM - initialBPM) < 90){ //If the current bpm is higher than the initial bpm by 75 to 89 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 1500; //Set the time to wait between entering the if statement again (and starting the motor) to 1.5 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    } 
    if((currentBPM - initialBPM) >= 90){ //If the current bpm is higher than the initial bpm by 90 beats or more, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 1000; //Set the time to wait between entering the if statement again (and starting the motor) to 1 second
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }
    if(currentBPM - initialBPM < 15){ //If the current bpm is less than 15 beats greater than the initial bpm, enter this statement
        motor.run(RELEASE); //Stop the motor 
        motor.setSpeed(0); //Set the motor speed to zero
        waitTime = 0; //Wait time is zero as there is nothing to wait for
    }
    priorTime = currentTime; //Set the priorTime to currentTime. This creates a counting system that can be used to repeat an action when desired by the code
  }  
}