# WiFi Extender & Hotspot Switch

This project demonstrates a WiFi extender with automatic hotspot reconfiguration using an ESP8266 and an I2C LCD display. The device scans for two pre-configured WiFi networks, connects to the first available network, and dynamically adjusts its SoftAP (hotspot) to reflect the active connection.

## Features

- **Automatic WiFi Scanning:**  
  Scans for two known networks and prioritizes the primary network. If the primary network is unavailable, it automatically connects to the secondary network.

- **Dynamic Hotspot Configuration:**  
  The device reconfigures its hotspot (SoftAP) based on the active station connection, ensuring the hotspot name matches the connected network.

- **Real-time Status Display:**  
  An I2C-connected LCD (JHD 162A) displays key statuses—scanning, connecting, connection details, and hotspot configuration—allowing users to easily monitor progress.

- **Automatic Reconnection:**  
  If the WiFi station connection is lost, the system continuously scans for available networks and reconnects automatically.

- **Easy Customization:**  
  WiFi credentials and hotspot names are set using simple placeholder variables, making it straightforward for users to adapt the code to their own networks.

## Requirements

- **Hardware:**  
  - ESP8266-based board (e.g., NodeMCU 1.0)  
  - JHD 162A LCD display with I2C interface  
  - Connecting wires, breadboard or custom PCB for prototyping

- **Software:**  
  - Arduino IDE  
  - Required libraries:
    - [ESP8266WiFi](https://github.com/esp8266/Arduino)
    - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) (or any compatible version)
    - Wire (included with Arduino IDE)
    - LWIP, NAPT, and DNS (provided with the ESP8266 core)

## Setup & Usage

1. **Clone the Repository:**  
   ```bash
   git clone https://github.com/MARSHALYADAV/wifi_extender.git
