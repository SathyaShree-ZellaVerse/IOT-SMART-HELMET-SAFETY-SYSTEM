🪖 IoT-Based Smart Helmet for Two-Wheeler Rider Safety

📌 About the Project

The IoT-Based Smart Helmet for Two-Wheeler Rider Safety is an IoT-based safety project designed to improve rider safety by detecting helmet presence, alcohol consumption, and vibration.

The system uses an Arduino Uno with sensors and alert components to identify unsafe conditions and provide warnings.

🎯 Objectives

- Detect helmet presence using an IR sensor.
- Detect alcohol using an MQ-3 alcohol sensor.
- Detect vibration using an SW-420 sensor.
- Alert the rider using a buzzer.
- Control a relay module and servo motor based on safety conditions.
- Support Bluetooth communication using the HC-05 module.

🛠️ Hardware Components

- Arduino Uno
- MQ-3 Alcohol Sensor
- SW-420 Vibration Sensor
- IR Sensor
- Buzzer
- Relay Module
- Servo Motor
- HC-05 Bluetooth Module
- Rocker Switch
- Breadboard and Connecting Wires

⚙️ Working Principle

1. The rocker switch activates the system.
2. The IR sensor checks helmet presence.
3. The MQ-3 sensor detects alcohol-related changes.
4. The SW-420 sensor detects vibration.
5. When an unsafe condition is detected, the system activates the buzzer and controls the relay and servo according to the programmed logic.
6. The HC-05 module provides Bluetooth communication capability.

💻 Software Requirements

- Arduino IDE
- Arduino Uno board support
- Servo library
- SoftwareSerial library

🔌 Pin Configuration

Component| Arduino Pin
IR Sensor| D2
SW-420 Sensor| D3
Relay Module| D4
Servo Motor| D5
HC-05 TXD| D6
HC-05 RXD| D7
Buzzer| D8
Rocker Switch| D9
MQ-3 Analog Output| A0

Note: Verify the pin configuration and sensor logic with the actual circuit before powering the system.

🌟 Key Features

- Helmet presence detection
- Alcohol detection
- Vibration detection
- Audible warning system
- Relay and servo control
- Bluetooth communication support

🚀 How to Run

1. Clone or download this repository.
2. Open "SmartHelmet.ino" in Arduino IDE.
3. Connect the Arduino Uno to your computer.
4. Select Arduino Uno under Tools → Board.
5. Select the correct COM port.
6. Verify and upload the code.
7. Connect the components according to the circuit diagram.
8. Test the sensors and calibrate their thresholds.

🔮 Future Enhancements

- GPS-based location tracking
- GSM-based emergency alerts
- Mobile application integration
- Improved accident detection
- Real-time monitoring

🎓 Domain

Electrical and Electronics Engineering | Internet of Things (IoT) | Embedded Systems | Rider Safety

👩‍💻 Developed By

Sathya Shree
Third-Year B.E. Electrical and Electronics Engineering
V.S.B Engineering College, Karur

⚠️ Disclaimer

This is an educational prototype and is not a certified safety device. Sensor readings and control logic must be tested with the actual hardware. Do not connect the relay to a real motorcycle ignition system without appropriate engineering design and safety validation.
