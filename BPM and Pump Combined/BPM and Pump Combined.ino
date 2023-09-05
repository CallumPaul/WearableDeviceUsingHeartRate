//This code uses the pusle sensor with the arduino and the motor driver in order to create a pulse rate for the peristaltic pump equalling that of the pulse sensors wearers heart rate
#include <AFMotor.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h> //Include the libraries and examples developed for the pulse sensor 

PulseSensorPlayground pulseSensor;
const int PulseWire = 5;
const int LED = LED_BUILTIN;
int Threshold = 550; //This establishes the pulse sensor 

AF_DCMotor motor(4); //Activate the motor at output 4

float bpm = 60; //This is the synthetic bpm value 
float bps; 
float frequency; 
float delayTime;
float dutyCycle = 0.5; //This variables are all used to produce the final delay time between pulses
float delayT = 1000; //Initial base delay time in case of fault with the pulse sensor 

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);
  motor.run(RELEASE); //This activates the motor in the set up

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold); //This activates the pulse sensor and its LED

  if (pulseSensor.begin()) { //If the pulse sensor has successfully turned on...
    Serial.println("Pulse sensor activated"); //print a statement notifying of this event
  }
}

void loop() {
  if (pulseSensor.sawStartOfBeat()) {
    bpm = pulseSensor.getBeatsPerMinute(); //Record the bpm detected through the pulse sensor
    Serial.println("Heart Beat detected");
    Serial.print("BPM: ");
    Serial.println(bpm); //Display the pulse sensor users current bpm
    delayT = DelayCalculator(bpm); //calculate the delay time for the next iteration of the loop, using the recorded bpm as the current bpm value
  }

  motor.run(FORWARD); //Set the motor to run in the forwards direction

  motor.setSpeed(200); //set the motor speed to 200
  delay(500); //delay the next command for 0.5 seconds, letting the motor run during that time

  motor.setSpeed(0); //Set motor speed to zero
  delay(delayT); //delay the next loop by time equalling delayT

}

float DelayCalculator(float Beats){ //Function that calculates the delay time. The delay time calculation is expressed in the report and the initial version of the synthetic heart rate code
  bps = Beats/60;
  frequency = 1/bps;
  delayTime = (frequency*1000*dutyCycle);
  return delayTime;
}