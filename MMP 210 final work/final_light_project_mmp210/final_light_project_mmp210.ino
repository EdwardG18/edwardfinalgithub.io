//behavior of each LED at each timer state
int led2[] = {1, 0, 0, 0, 0, 0};
int led3[] = {0, 1, 0, 0, 0, 1};
int led4[] = {0, 0, 1, 0, 1, 0};
int led5[] = {0, 0, 0, 1, 0, 0};

//current position in cycle
int cyclePos = 0;

//length of cycle
int cycleLength = 6;

//millis timer vars
unsigned long currentMillis = 0;
unsigned long prevMillis = 0;
int duration = 90;

//button pin
const int buttonPin = 2; // Change this to the actual pin number you are using for the button

//button state variables
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  // not used in this example, but if you want to use serial, you'll need this
  Serial.begin(9600);

  // set pin modes (LEDs connected to pins 9 through 13 with current limiting resistors)
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  // set button pin mode
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // only update the LED cycle if the button is not pressed
  if (buttonState != HIGH) {
    currentMillis = millis();
  }
    if (currentMillis > prevMillis + duration) {
      cyclePos++;
      prevMillis = currentMillis;
    }

    // reset back to the first state in the cycle
    if (cyclePos >= cycleLength) {
      cyclePos = 0;
    }

    // write values from the array to the LEDs
    digitalWrite(9, led2[cyclePos]);
    digitalWrite(11, led3[cyclePos]);
    digitalWrite(12, led4[cyclePos]);
    digitalWrite(13, led5[cyclePos]);

if (buttonState== HIGH){
  if (cyclePos == 0 || cyclePos == 2 || cyclePos == 3 || cyclePos == 4){
    Serial.println("2");
  }
  if (cyclePos == 1 || cyclePos == 5){
  Serial.println("1");
  }
}
else{
  Serial.println("0");
}

//if (buttonState== HIGH && cyclePos == 1){
//  Serial.println("1");
//}
//else if (buttonState== HIGH && cyclePos == 2){
//  Serial.println("2");
//}
//
//else if( cyclePos == 0 || cyclePos==2){
//  if (buttonState == HIGH){
//    Serial.println("2");
//  }
//}
//
//else if( cyclePos == 0 || cyclePos==2){
//  if (buttonState == HIGH){
//    Serial.println("2");
//  }
//
//}
//
//else {
//  Serial.println("0");
//}




      // Print the state to


//  } else {
//    // If the button is pressed, turn off all LEDs
//    digitalWrite(9, LOW);
//    digitalWrite(11, LOW);
//    digitalWrite(12, LOW);
//    digitalWrite(13, LOW);
//  }
}
