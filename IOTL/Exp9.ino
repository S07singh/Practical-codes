// RGB LED control with potentiometers

// LED pins
int redPin = 5;
int greenPin = 6;
int bluePin = 3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read and map potentiometer values directly
  int red = analogRead(A0) / 4;
  int green = analogRead(A2) / 4;
  int blue = analogRead(A3) / 4;
  
  // Set LED color (common-anode LED)
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
  
  delay(100);
}

/*
Problem Statement: 
To change the color of the RGB LED using the input from 3 different potentiometers, using 
Arduino. 
Code: 
const int rPin = 9;      
// PWM pin for Red color 
const int gPin = 10;   // PWM pin for Green color 
const int bPin = 11;   // PWM pin for Blue color 
const int rPotPin = A0;  // Analog input pin for Red potentiometer 
const int gPotPin = A1;  // Analog input pin for Green potentiometer 
const int bPotPin = A2;  // Analog input pin for Blue potentiometer 
void setup() { 
// Set RGB LED pins as output 
pinMode(rPin, OUTPUT); 
pinMode(gPin, OUTPUT); 
pinMode(bPin, OUTPUT); 
Serial.begin(9600); 
} 
void loop() { 
// Read the potentiometer values 
int rValue = analogRead(rPotPin); 
int gValue = analogRead(gPotPin); 
int bValue = analogRead(bPotPin); 
// Map the potentiometer values to a range of 0 to 255 (PWM range) 
rValue = map(rValue, 0, 1023, 0, 255); 
gValue = map(gValue, 0, 1023, 0, 255); 
bValue = map(bValue, 0, 1023, 0, 255); 
// Set the color of the RGB LED using PWM 
analogWrite(rPin, rValue); 
analogWrite(gPin, gValue); 
analogWrite(bPin, bValue); 
// Print values to Serial Monitor 
Serial.print("\n\nRed: "); 
Serial.print(rValue); 
Serial.print("  Green: "); 
Serial.print(gValue); 
Serial.print("  Blue: "); 
Serial.print(bValue); 
delay(50); // Small delay for stability 
}
*/
