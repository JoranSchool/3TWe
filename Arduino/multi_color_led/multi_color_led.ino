// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 12;     // the number of the pushbutton pin

//Our ledPin will now be changed dynamically by the code so we need to 
//remove the 'const' from the start of the declaration
int ledPin =  10;      // the number of the LED pins

//we want a flag to check and see if we need a new random number
//we create it as a 'boolean' rather than an 'int' as it only 
//needs to represent two values, true or false, 0 or 1
boolean flag = 0;
//something to hold our random number
int randNumber = 0;

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pins as outputs, or they will be dim:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  //here we check our flag to see if we need a new random number 
  //and use it to select the right pin 
  if (flag == 0){
    //set the flag so we dont change the ledPin until the button is off
    flag = 1;   
    randNumber = random(3);   //use the 'random function
      //a nested if to select the right pin numbers
      if (randNumber == 0){   
        ledPin = 10; //Red pin
      }
      else if (randNumber == 1){
        ledPin = 9;  //Blue pin
      }
      else{
        ledPin = 6;  //Green pin
      }
  }

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    
    flag = 0;   //reset the flag
  }
}
