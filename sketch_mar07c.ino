#define TRIGGER_PIN_1 2
#define ECHO_PIN_1 3
#define TRIGGER_PIN_2 4
#define ECHO_PIN_2 5

#define RED_PIN 6
#define GREEN_PIN 7
#define BLUE_PIN 8

void setup() {
  Serial.begin(115200);

  // Ultrasonic sensor 1
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  // Ultrasonic sensor 2
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  // RGB LED
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Measure distance from Ultrasonic Sensor 1
  int distance1 = getDistance(TRIGGER_PIN_1, ECHO_PIN_1);

  // Measure distance from Ultrasonic Sensor 2
  int distance2 = getDistance(TRIGGER_PIN_2, ECHO_PIN_2);

  // Print distances to Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Turn on RGB LED when both sensors detect an object
  if (distance1 < 20 || distance2 < 20) {
    setColorRGB(255, 0, 0);  // White
  } else {
    setColorRGB(0, 255, 0);  // Turn off the LED
  }

  delay(1000); // Adjust the delay as needed
}

int getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void setColorRGB(int red, int green, int blue) {
  analogWrite(RED_PIN, 255 - red);
  analogWrite(GREEN_PIN, 255 - green);
  analogWrite(BLUE_PIN, 255 - blue);
}
  
