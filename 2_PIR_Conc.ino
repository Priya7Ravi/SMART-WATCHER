int led = 13;                // the pin that the LED is atteched to
int sensor1 = 2;
int sensor2 = 3;// the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);// initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  int val1 = digitalRead(sensor1);
  int val2 = digitalRead(sensor2); // read sensor value
  if (val1 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected 01 !"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else if (val2 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected 02!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(10);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped !");
        state = LOW;       // update variable state to LOW
    }
  }
}
