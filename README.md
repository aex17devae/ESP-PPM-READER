# ESP32 PPM Signal Reader

## Overview
The ESP32 PPM Signal Reader project utilizes an ESP32 microcontroller to capture raw PWM (Pulse Width Modulation) signals from an FS-i6 receiver. By decoding the incoming PPM signal through precise timing and interrupt handling, this project extracts channel values and allows for remote control data analysis and integration with various systems.

## Features
- Captures and processes PPM signals from FS-i6 receiver
- Utilizes interrupt handling for accurate pulse duration measurement
- Supports up to 6 PPM channels
- Real-time monitoring and visualization of captured PPM values through serial output

## Hardware Requirements
- ESP32 development board
- FS-i6 receiver
- Jumper wires for signal connection

## Software Setup
1. Ensure the ESP32 board is properly set up on the Arduino IDE or PlatformIO.
2. Load the provided code onto the ESP32.
3. Connect the PPM signal output from the FS-i6 receiver to the specified pin on the ESP32.
4. Open the serial monitor to observe the captured PPM values.

## Code Structure
- **Main Sketch (ppm_signal_reader.ino):** Contains setup and loop functions, interrupt handling for PPM signal processing.
- **Libraries:** Utilizes basic Arduino libraries for serial communication and interrupt handling.

## Configuration
- Define the PPM signal pin and adjust the number of expected channels in the code as needed.
- Further customization can be done to incorporate additional functionalities based on specific project requirements.

## Usage
- The captured PPM values can be used to control various devices, such as drones, RC cars, or other remote-controlled systems.
- Explore the potential of the PPM signal reader for integrating remote control capabilities into your projects.

## Contributions
Contributions are welcome! Feel free to submit issues or pull requests for any enhancements or bug fixes.



## Author
- ae17devae(https://github.com/aex17devae)

## Acknowledgements
- This project was inspired by the need for accurate remote control signal processing in hobbyist and robotics projects.
- Special thanks to the ESP32 and Arduino communities for their valuable resources and support.
