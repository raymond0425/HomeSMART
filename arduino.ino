int LED = 13;
int ECHO_PIN = 4;
int TRIG_PIN = 5;
char message;

void setup() {
  pinMode(LED, OUTPUT); 
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {
  if (Serial.available()){
    delay(300);
    message = Serial.read();
    Serial.print(message);
    if(message=='1'){digitalWrite(LED, HIGH);}
    else if(message=='2'){digitalWrite(LED, LOW);}
  }
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH); // Pulse for 10ms to trigger ultrasonic detection 
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW); 
  duration = pulseIn(ECHO_PIN, HIGH); // Read receiver pulse time 
  distance = (duration / 2) / 29.1;
  if ((distance >= 200) || (distance <=0)) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance); //Ourput distance
    Serial.println(" cm");
  }
  delay(500);
  
}
