//This code was used as a simple way to ensure that the peristaltic pump purchased for the project was 
//operational and could be controlled through the Arduino Uno

const int peristalticPump = 5; //Connect the peristaltic pump to digital pin 5 on the Arduino (a PWM pin)

void setup() { //A set up function for the code prior to the pump running
  pinMode(peristalticPump, OUTPUT); //Makes the peristaltic pump an output pin rather than an input pin
}

void loop() { //A function that will loop indefinitely until told to stop 
  digitalWrite(peristalticPump, HIGH); //Turns the pin to high and the pump on 
  delay(10000); //Delay for 10 seconds, allowing the pump to run for 10 seconds
  digitalWrite(peristalticPump, LOW); //Turns the pin to low and the pump off
  delay(3000); //Delay for 3 seconds, allowing the pump to remain off for 3 seconds
}
