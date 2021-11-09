#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

// LEDs
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 7;
const int LED5 = 8;

// Buttons
const int button1 = 12;
const int button2 = 13;

// Button values
int button1Presses = 0; // keep track of how many times button 1 is pressed
boolean button2Pressed = false;

const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;

// Potentimeter values
int pot1Val;
int pot1Angle;
int pot2Val;
int pot2Angle;
int pot3Val;
int pot3Angle;

// Array to hold 5 positions of each servo
int servo1Pos[5];
int servo2Pos[5];
int servo3Pos[5];

void setup() {
  // put your setup code here, to run once:

  // Set up servos
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);

  // Set up pin modes
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read pot values and use the map function to map the value to be between 0-179 to be used in the servo
  pot1Val = analogRead(pot1);
  pot1Angle = map(pot1Val, 0, 1023, 0, 179);
  pot2Val = analogRead(pot2);
  pot2Angle = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);

  // Move the servos to the mapped values
  servo1.write(pot1Angle);
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);

  // Depending on how many times button 1 is pressed, it will save the positions the array
  if (digitalRead(button1) == HIGH) {
    button1Presses++;
    switch(button1Presses) {
      case 1:
        servo1Pos[0] = pot1Angle;
        servo2Pos[0] = pot2Angle;
        servo3Pos[0] = pot3Angle;
        digitalWrite(LED1, HIGH);
        Serial.println("Position 1 Saved");
        break;
      case 2:
        servo1Pos[1] = pot1Angle;
        servo2Pos[1] = pot2Angle;
        servo3Pos[1] = pot3Angle;
        digitalWrite(LED2, HIGH);
        Serial.println("Position 2 Saved");
        break;
      case 3:
        servo1Pos[2] = pot1Angle;
        servo2Pos[2] = pot2Angle;
        servo3Pos[2] = pot3Angle;
        digitalWrite(LED3, HIGH);
        Serial.println("Position 3 Saved");
        break;
      case 4:
        servo1Pos[3] = pot1Angle;
        servo2Pos[3] = pot2Angle;
        servo3Pos[3] = pot3Angle;
        digitalWrite(LED4, HIGH);
        Serial.println("Position 4 Saved");
        break;
      case 5:
        servo1Pos[4] = pot1Angle;
        servo2Pos[4] = pot2Angle;
        servo3Pos[4] = pot3Angle;
        digitalWrite(LED5, HIGH);
        Serial.println("Position 5 Saved");
        break;
    }
  }

  if(digitalRead(button2) == HIGH)
    button2Pressed = true;

  // If button 2 is pressed, servos run through all the saved positions
  if(button2Pressed) {
    for (int i = 0; i < 5; i++) {
      servo1.write(servo1Pos[i]);
      servo2.write(servo2Pos[i]);
      servo3.write(servo3Pos[i]);
      Serial.println("Potentimeter Angles: ");
      Serial.println(servo1Pos[i]);
      Serial.println(servo2Pos[i]);
      Serial.println(servo3Pos[i]);
      delay(1050);
    }
  }
  delay(100);
}
