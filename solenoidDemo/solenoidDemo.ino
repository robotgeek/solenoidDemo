/*

Controlling a Solenoid with Arduino

This demo shows how to control a solenoid using pushbuttons and a relay with
your Arduino compatable controller.
 - The first button will hold the solenoid/relay on while it is held
 - The second button will hold the solenoid/relay on for 2 seconds
 
 
 The circuit:
 * RobotGeek Pushbutton - Digital Pin 2
 * RobotGeek Pushbutton - Digital Pin 4
 * RobotGeek Relay - Digital Pin 7
 
Products Used in this demo:
 - http://www.robotgeek.com/solenoids
 - http://www.robotgeek.com/robotgeek-geekduino-sensor-kit
 - http://www.robotgeek.com/robotGeek-pushbutton
 - http://www.robotgeek.com/robotgeek-relay

 */

// constants won't change. They're used here to set pin numbers:
const int button1Pin = 2;     // the number of the pushbutton1 pin
const int button2Pin = 4;     // the number of the pushbutton2 pin
const int relayPin =  7;      // the number of the Relay pin

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status

void setup() { 
  
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);     
  pinMode(button2Pin, INPUT);    
  // initialize the relay pin as an output:
  pinMode(relayPin, OUTPUT);    
   
}

void loop(){
  
  // read the state of the pushbutton values:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if the pushbutton1 is pressed.
  // if it is we turn on the relay/solenoid
  if (button1State == HIGH) {     
    // turn relay on:    
    digitalWrite(relayPin, HIGH);  
  } 
  // When we let go of the button, turn off the relay
  else if ((button1State == LOW) && (digitalRead(relayPin) == HIGH)) {
    // turn relay off
    digitalWrite(relayPin, LOW); 
  }  
  
  
  // For the second button, we just activate the solenoid/relay for two seconds
  if (button2State == HIGH) {     
    // turn relay on   
    digitalWrite(relayPin, HIGH); 
    delay(2000);    // waits for 2 seconds
    //turn relay off
    digitalWrite(relayPin, LOW); 
  } 

}
