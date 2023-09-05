//This code was used the second set of experiments and is able to produce the fourth pattern described in the report. It uses a synthetic heart rate signal rather than the pulse sensor
//In this code the delay times between motor activations (the variable waitTime) is increased by 0.25 seconds based on feedback from exeriment set one.
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

  //The below if statements allow the motor to pulse at specific timed intervals in the experiment time frame. This pattern (4) is explained and detailed in the report (Wearable Robotics for Augmenting Communication)

  if(startTime >= 00000 && startTime < 3750){
    currentBPM = 80;
  }
  if(startTime >= 3750 && startTime < 7000){
    currentBPM = 90;
  }
    if(startTime >= 7000 && startTime < 9750){
    currentBPM = 110;
  }
    if(startTime >= 9750 && startTime < 12000){
    currentBPM = 130;
  }
    if(startTime >= 13750 && startTime < 13750){
    currentBPM = 140;
  }
    if(startTime >= 13750 && startTime < 15000){
    currentBPM = 150;
  }  
  if(startTime >= 15000 && startTime < 16250){
    currentBPM = 150;
  }
  if(startTime >= 16250 && startTime < 18000){
    currentBPM = 140;
  }
    if(startTime >= 18000 && startTime < 20250){
    currentBPM = 130;
  }
    if(startTime >= 20250 && startTime < 23000){
    currentBPM = 110;
  }
  if(startTime >= 23000 && startTime < 26250){
    currentBPM = 90;
  }
  if(startTime >= 26250 && startTime < 30000){
    currentBPM = 80;
  }  
  if(startTime >= 30000){
    currentBPM = 60;
  }


 if((currentTime - priorTime) >= waitTime){ //If the difference between the currentTime and the priorTime is greater than the waitTime then the if statement may be entered
    if((currentBPM - initialBPM) >= 15 && (currentBPM - initialBPM) < 30){ //If the current bpm is higher than the initial bpm by 15 to 29 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 3750; //Set the time to wait between entering the if statement again (and starting the motor) to 3.75 seconds 
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }
    if((currentBPM - initialBPM) >= 30 && (currentBPM - initialBPM) < 45){ //If the current bpm is higher than the initial bpm by 30 to 44 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 3250; //Set the time to wait between entering the if statement again (and starting the motor) to 3.25 seconds 
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 45 && (currentBPM - initialBPM) < 60){ //If the current bpm is higher than the initial bpm by 45 to 59 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second 
        waitTime = 2750; //Set the time to wait between entering the if statement again (and starting the motor) to 2.75 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 60 && (currentBPM - initialBPM) < 75){ //If the current bpm is higher than the initial bpm by 60 to 74 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 2250; //Set the time to wait between entering the if statement again (and starting the motor) to 2.25 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    }  
    if((currentBPM - initialBPM) >= 75 && (currentBPM - initialBPM) < 90){ //If the current bpm is higher than the initial bpm by 75 to 89 beats, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 1750; //Set the time to wait between entering the if statement again (and starting the motor) to 1.75 seconds
        motor.setSpeed(0); //Stop the motor to avoid it running while waiting for the next oppurtunity to enter the if statement
    } 
    if((currentBPM - initialBPM) >= 90){ //If the current bpm is higher than the initial bpm by 90 beats or more, enter this statement 
        motor.run(FORWARD); //Set the motor to run forwards
        motor.setSpeed(200); //Set the motor speed to 200 (see earlier code for reasoning)
        delay(500); //Delay the next command by 0.5 seconds. This allows the motor to run uninterrupted for half a second
        waitTime = 1250; //Set the time to wait between entering the if statement again (and starting the motor) to 1.25 seconds
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