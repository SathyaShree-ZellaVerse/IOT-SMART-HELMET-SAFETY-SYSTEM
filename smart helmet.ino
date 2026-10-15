#include <Servo.h>
#include <SoftwareSerial.h>

// Sensor and module pins
#define IR_SENSOR 2
#define VIBRATION_SENSOR 3
#define RELAY 4
#define SERVO_PIN 5
#define BUZZER 8
#define SWITCH_PIN 9
#define ALCOHOL_SENSOR A0

// Bluetooth: Arduino RX, TX
SoftwareSerial bluetooth(6, 7);

Servo safetyServo;

// Adjust after testing your MQ-3 sensor
int alcoholThreshold = 650;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(IR_SENSOR, INPUT);
  pinMode(VIBRATION_SENSOR, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);

  safetyServo.attach(SERVO_PIN);
  safetyServo.write(0);

  // Assumed active-low relay
  digitalWrite(RELAY, HIGH);
  digitalWrite(BUZZER, LOW);

  Serial.println("Smart Helmet System Ready");
  bluetooth.println("Smart Helmet Ready");
}

void loop() {
  // Switch ON when connected to GND
  if (digitalRead(SWITCH_PIN) == HIGH) {
    digitalWrite(BUZZER, LOW);
    digitalWrite(RELAY, HIGH);
    safetyServo.write(0);
    delay(200);
    return;
  }

  // Assumed IR output LOW means helmet detected
  bool helmetDetected = (digitalRead(IR_SENSOR) == LOW);

  // Assumed SW-420 output HIGH means vibration detected
  bool vibrationDetected =
      (digitalRead(VIBRATION_SENSOR) == HIGH);

  int alcoholValue = analogRead(ALCOHOL_SENSOR);
  bool alcoholDetected = (alcoholValue >= alcoholThreshold);

  bool unsafeCondition =
      !helmetDetected || alcoholDetected || vibrationDetected;

  Serial.print("Helmet: ");
  Serial.print(helmetDetected ? "Detected" : "Not Detected");
  Serial.print(" | Alcohol: ");
  Serial.print(alcoholValue);
  Serial.print(" | Vibration: ");
  Serial.println(vibrationDetected ? "Detected" : "No");

  if (unsafeCondition) {
    digitalWrite(BUZZER, HIGH);

    // Assumed active-low relay
    digitalWrite(RELAY, LOW);
    safetyServo.write(90);

    bluetooth.println("WARNING: Unsafe condition detected!");

    if (!helmetDetected)
      bluetooth.println("Helmet not detected");

    if (alcoholDetected)
      bluetooth.println("Alcohol threshold exceeded");

    if (vibrationDetected)
      bluetooth.println("Vibration detected");
  } else {
    digitalWrite(BUZZER, LOW);
    digitalWrite(RELAY, HIGH);
    safetyServo.write(0);

    bluetooth.println("Status: SAFE");
  }

  delay(500);
}
