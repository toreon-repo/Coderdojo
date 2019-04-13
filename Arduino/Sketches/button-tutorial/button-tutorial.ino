/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPinLEDBoard = 6;     // the number of the pushbutton pin
const int buttonPinLEDChipR = 3;     // the number of the pushbutton pin
const int buttonPinLEDChipG = 4;     // the number of the pushbutton pin
const int buttonPinBuzzer = 5;     // the number of the pushbutton pin
const int buttonPotentiometer = A2; // draaiknop

const int ledPinBoard =  13;      // the number of the LED pin
const int ledPinChipB = 13;     // the number of the pushbutton pin
const int ledPinChipR =  12;      // GEEN PWN the number of the LED pin
const int ledPinChipG =  11;      // PWN the number of the LED pin
const int buzzerPin =  9;      // the number of the LED pin

// variables will change:
int buttonStateLEDBoard = 0;         // variable for reading the pushbutton status
int buttonStateLEDChipR = 0;         // variable for reading the pushbutton status
int buttonStateLEDChipG = 0;         // variable for reading the pushbutton status
int buttonStateBuzzer = 0;         // variable for reading the pushbutton status

// for potentiometer
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {

  Serial.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPinChipB, OUTPUT);
  pinMode(ledPinBoard, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinLEDBoard, INPUT);
  // initialize the LED pin as an output:

  pinMode(ledPinChipR, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinLEDChipR, INPUT);

  pinMode(ledPinChipG, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinLEDChipG, INPUT);

  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinBuzzer, INPUT);

  // add potentiometer
   pinMode(buttonPotentiometer, INPUT);

}

void loop() {

  // read the analog in value:
  sensorValue = analogRead(buttonPotentiometer);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
 
   // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(5);
  
  
  // BUTTON 1
  // read the state of the pushbutton value:
  buttonStateLEDBoard = digitalRead(buttonPinLEDBoard);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateLEDBoard == HIGH) {
    // turn LED on:
    digitalWrite(ledPinBoard, HIGH);
    analogWrite(ledPinChipB, outputValue);
  } else {
    // turn LED off:
    digitalWrite(ledPinBoard, LOW);
  }
    
  // BUTTON 2
  // read the state of the pushbutton value:
  buttonStateLEDChipR = digitalRead(buttonPinLEDChipR);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateLEDChipR == HIGH) {
    // turn LED on:
    analogWrite(ledPinChipR, outputValue);
  } else {
    // turn LED off:
    analogWrite(ledPinChipR, 0);
  
  }

  // BUTTON 3
  // read the state of the pushbutton value:
  buttonStateLEDChipG = digitalRead(buttonPinLEDChipG);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateLEDChipG == HIGH) {
    // turn LED on:
    analogWrite(ledPinChipG, outputValue);
  } else {
    // turn LED off:
    analogWrite(ledPinChipG, 0);
  
  }

  // BUTTON 4
  // read the state of the pushbutton value:
  buttonStateBuzzer = digitalRead(buttonPinBuzzer);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateBuzzer == HIGH) {
    // turn buzzer on:
    analogWrite(buzzerPin, outputValue);
  } else {
    // turn buzzer off:
    analogWrite(buzzerPin, 0);
  
  }

}
