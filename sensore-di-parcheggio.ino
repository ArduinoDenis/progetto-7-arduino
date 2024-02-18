// Parking Sensor

// Define sensor pins
int triggerPort = 7;
int echoPort = 8;
int buzzer = 9;

// Define time variables
unsigned long time;
unsigned long blink_time;
unsigned long pause_time;

void setup() {
  // Set pin modes
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  pinMode(buzzer, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor:");
}

void loop() {
  // Lower trigger pin output
  digitalWrite(triggerPort, LOW);
  
  // Send a 10 microsecond pulse on trigger pin
  digitalWrite(triggerPort, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPort, LOW);
  
  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPort, HIGH);
  
  // Calculate distance based on duration
  long distance = 0.034 * duration / 2;
  
  // Print the results to serial monitor
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(", Distance: ");
  
  if (duration > 38000) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  // Activate buzzer based on distance
  if (distance > 3 && distance <= 200) {
    delay(distance * 10);
    digitalWrite(buzzer, HIGH);
    delay(distance * 10);
  } else if (distance <= 3) {
    digitalWrite(buzzer, HIGH);
    delay(1000);
  }
  
  digitalWrite(buzzer, LOW);
  delay(10);
}
