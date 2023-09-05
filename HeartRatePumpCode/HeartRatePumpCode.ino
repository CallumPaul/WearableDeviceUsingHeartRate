// This code uses a conversion equation to directly link heart bpm to pulses from the pump
#include <AFMotor.h>
AF_DCMotor motor(4);

float bpm = 60; //This is the synthetic bpm value 
float bps; 
float frequency; 
float delayTime;
float dutyCycle = 0.5; //This variables are all used to produce the final delay time between pulses

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);
  motor.run(RELEASE); //Activates the motor

  bps = bpm/60; //Converts the beats per minute into beats per second
  frequency = 1/bps; //Converts the beats per second into a frequency using the equation f = 1/t (frequency = 1/time)
  delayTime = (frequency*1000*dutyCycle); //Uses the frequency and duty cycle (50%) to make the delay time. The multiplication of 1000 is present as Arduino time is in milliseconds

  Serial.println("The pulse rate is:"); 
  Serial.print(bpm); 
  Serial.print("The delay time between pulses is:")
  Serial.print(delayTime); //These are a series of statements to display certain values. The previously set bpm value is stated as well as the calculated delay time. 
}

void loop() { //Create a looped function that will run indefinitely 

  motor.run(FORWARD); //Set the motor to run forwards. This is arbritary as the motor in use is bi-directional. 

  motor.setSpeed(200); //Sets the motor speed to 200. This speed is scaled from 0 to 255. A speed of 200 was chosen as this would allow the motor to run quickly but would not over-exert it
  delay((delayTime)); //Delay the next command for a time equal to the delay time calculated earlier (keeping the motor running)

  motor.run(RELEASE); //Stop the motor

  motor.setSpeed(0); //Set the motr speed to zero
  delay((delayTime)); //Delay the next command for a time equal to the delay time calculated earlier (keeping the motor stationary)

}