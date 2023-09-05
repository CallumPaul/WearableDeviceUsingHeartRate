// This code takes a chosen value for the intial bpm of a theoretical person and their theoretical increase heart rate to observe how the system would react
#include <AFMotor.h>
AF_DCMotor motor(4); //Establish that the 4th motor connection point is the one in use 

float initialBPM = 60; //Set the intial bpm a value. 60 is chosen here as it is within the healthy resting heart range
float currentBPM; //Set the new bpm variable. 60 is chosen here to observe what happens when there is no change in bpm but ay value can be chosen
int waitTime = 0; //Set up the variable waitTime that will be used later

unsigned long currentTime;
unsigned long priorTime; //Set up the avriables that will be used later as counters in the loop function

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);
  motor.run(RELEASE); //Activates the motor in the setup
  currentBPM = 60; //Give the current bpm variable a value. 60 is chosen here to observe what happens when there is no change in bpm but ay value can be chosen
}

void loop() { //Start the loop function
  currentTime = millis(); //Start the clock 

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