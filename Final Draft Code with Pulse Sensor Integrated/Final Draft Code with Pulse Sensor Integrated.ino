// This code uses the final synthetic heart rate code with the pulse sensor modules included. The pulse of the wearer is averaged at the start in order to achieve a better system
//as the pulse sensor needs to intialise after being switched on and can produce inaccurate readings.
#include <AFMotor.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h> //Include the libraries and examples developed for the pulse sensor 

PulseSensorPlayground pulseSensor;
const int PulseWire = 5;
const int LED = LED_BUILTIN;
int Threshold = 550; //This establishes the pulse sensor 

AF_DCMotor motor(4); //Activate the motor at output 4

float bpm; 
float initialBPM = 60;
float bps;
float frequency;
float delayTime = 2000;
float dutyCycle = 0.5;
float currentBPM = 60;
float currentDelay;
float scaleFactor;
int averageBPM;
int totalBPM;
int tag; //Establish the variables needed for this system to work

unsigned long startTime;
unsigned long currentTime;
unsigned long priorTime;
int waitTime = 0; //Create timers that can be used in the main loop 


void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);
  motor.run(RELEASE); //Activate the motor in the set up

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold); //Activate the pulse sensor and its LED

  if (pulseSensor.begin()) {
    Serial.println("Pulse sensor activated"); //Display a print statement notifying if the pulse sensor has successfully turned on
  } 
}

void loop(){ //Start the main loop
  
  startTime = millis(); //Begin counting 

  if((startTime <= 15000) && (startTime > 5000)){ //Enter here after 5 seconds and keep looping in this statement until 15 seconds have elapsed since the timer began
    if (pulseSensor.sawStartOfBeat()) { //If the pulse sensor successfully detected a heartbeat
      tag = tag + 1; //Create a counter that increases on each iteration of the loop
      bpm = pulseSensor.getBeatsPerMinute(); //Set the bpm value to be equal to the perceived heart rate of the wearer
      Serial.println("Heart Beat detected");  
      Serial.print("BPM: ");
      Serial.println(bpm); //Dispaly the heart beat detected
      totalBPM = totalBPM + bpm; //Add the new bpm value recorded to the total bpm value
      initialBPM = totalBPM/tag; ///Average the total bpm value using the counter to find the average heart rate of the wearer. This is far more accurate than simply recording the first value that appears on the sensor
      Serial.print(initialBPM); //Display the current average value (as this may change over time)
    }
  }

  if(startTime > 15000){ //After 15 seconds, enter this statment and repeat it for each iteration of the loop

    currentTime = millis();

//The below if statement is used to record the wearers heart rate on every iteration of the loop. It compares this value to the average determined earlier and the difference 
//is used to determine which band the code will enter on the next iteration. 
    if (pulseSensor.sawStartOfBeat()) { 
      currentBPM = pulseSensor.getBeatsPerMinute();
      Serial.println("Heart Beat detected");
      Serial.println("BPM: ");
      Serial.print(currentBPM);
      Serial.println("Average starting BPM: ");
      Serial.print(initialBPM);
    }

// The below sectin of code is fully explained and detailed in other sections such as in the experiment 2 variations and the final draft code for synthetic heart rate
//It uses the same principles of running the motor for 0.5 seconds before having to wait a set amount of time specified in the relative banded bpm increase. 

    if((currentTime - priorTime) >= waitTime){

      if((currentBPM - initialBPM) >= 15 && (currentBPM - initialBPM) < 30){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 3500;
          motor.setSpeed(0);
      }
      if((currentBPM - initialBPM) >= 30 && (currentBPM - initialBPM) < 45){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 3000;
          motor.setSpeed(0);
      }  
      if((currentBPM - initialBPM) >= 45 && (currentBPM - initialBPM) < 60){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 2500;
          motor.setSpeed(0);
      }  
      if((currentBPM - initialBPM) >= 60 && (currentBPM - initialBPM) < 75){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 2000;
          motor.setSpeed(0);
      }  
      if((currentBPM - initialBPM) >= 75 && (currentBPM - initialBPM) < 90){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 1500;
          motor.setSpeed(0);
      } 
      if((currentBPM - initialBPM) >= 90){
          motor.run(FORWARD);
          motor.setSpeed(200);
          delay(500);
          waitTime = 1000;
          motor.setSpeed(0);
      }
      if(currentBPM - initialBPM < 15){
          motor.run(FORWARD);
          motor.setSpeed(0);
          waitTime = 0;
      }

        priorTime = currentTime;  
      }
  }
}