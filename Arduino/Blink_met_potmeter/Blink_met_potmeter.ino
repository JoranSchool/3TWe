

// declaratie libraries, constanten, objecten, variabelen

//constanten
const int myPins[4] = {2, 6, 9, 11 };
//  index              0  1  2   3
// variabelen
int tijd;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins
  for (int i = 0; i < 4; i++) {
    pinMode(myPins[i], OUTPUT);
  } // end for

  // aanleggen Serial Monitoring
  Serial.begin(115200);
  Serial.println("Start debugging ...");
  Serial.println();
} // end setup



// the loop function runs over and over again forever
void loop() {
  // inlezen Potmeter
  tijd = analogRead(A0);

  // Op SM zetten
  Serial.print("tijd = ");
  Serial.print(tijd);

  // hermappen
  tijd = map(tijd, 0, 1023, 50, 200);

  // Op SM zetten
  Serial.print("\t tijd2 = ");
  Serial.println(tijd);

  // sturen leds
  for (int i = 0; i < 4; i++) {
    blinkLed(myPins[i], tijd);
  } // end for
} // end loop


void blinkLed(int pin, int wachtTijd) {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(wachtTijd);                       // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(wachtTijd);                       // wait for a second
} // end blinkLed
