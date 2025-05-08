String input = "";
bool done = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      done = true;
    } else {
      input += c;  //input = input + c
    }
  }
  
  if (done) {
    int num = input.toInt();
    int square = num * num;
    Serial.print("Square of ");
    Serial.print(num);
    Serial.print(" is ");
    Serial.println(square);
    
    input = "";
    done = false;
    Serial.println("Enter a number:");
  }
}

// int n; 
// void setup() { 
// Serial.begin(9600); 
// Serial.print("\nEnter the number:"); 
// } 
// void loop() { 
// if (Serial.available() > 0) { 
// String input = Serial.readStringUntil('\n'); 
// n = input.toInt(); 
// Serial.print("\nThe square of "); 
// Serial.print(n); 
// Serial.print(" is : "); 
// Serial.print(n * n); 
// delay(500); 
// Serial.print("\nEnter the number:"); 
// } 
// } 