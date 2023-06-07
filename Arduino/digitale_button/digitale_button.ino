//constants won't change:
const int buttonPin =2;
const int ledPin = 13;

//variables will change:
int buttonState = 0;

void setup() {
  // intilaze the LED pin as an output:
  pinMode(ledPin, OUTPUT);;
  // intilaze the LED pin as an output
  pinMode(buttonPin, INPUT);

}

void loop() {
  // read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed
  if (buttonState == LOW){
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin,LOW);
  }

}
