# LockSystem
LockSystem is a simple security system based on Arduino that uses sequential code entry via push-buttons. After 3 unsuccessful attempts to enter the password the system locks for 10s. There are 2 versions available for this project.
## Versions
### Version 1
In this version every command is displayed via Serial Monitor in Arduino IDE.
### Version 2
In this version every command is displayed via parallel LCD display.
## Components
### Hardware
#### Version 1
- Arduino UNO
- Resistors:
  - 330Ω (6x)
  - 10kΩ (4x)
- LEDs:
  - White LEDs (4x)
  - RGB diode with common cathode
- Push-Buttons (4x)
- Passive Piezo-Buzzer (HPM14AX)
#### Version 2
- Arduino UNO
- Resistors:
  - 330Ω (2x)
  - 10kΩ (4x)
- LEDs:
  - RGB diode with common cathode
- Push-Buttons (4x)
- Passive Piezo-Buzzer (HPM14AX)
- Parallel LCD Display
### Software
- IDE: Arduino IDE
## Connection
### Version 1
![Connection Diagram 1](https://github.com/kolszewska16/Arduino-Projects/blob/c25baeabd2f12f8c439911fe74f707208f45a5b4/LockSystem/LockSystem_ver1/connection_ver1.png)
### Version 2
![Connection Diagram 2](https://github.com/kolszewska16/Arduino-Projects/blob/c25baeabd2f12f8c439911fe74f707208f45a5b4/LockSystem/LockSystem_ver2/connection_ver2.png)