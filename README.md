# wifi_extender
This project demonstrates a WiFi extender with automatic hotspot reconfiguration using an ESP8266 and an I2C LCD display. The device scans for two pre-configured WiFi networks, connects to the first available network, and dynamically adjusts its SoftAP (hotspot) to reflect the active connection.
Features

Automatic WiFi Scanning:
Scans for two known networks and prioritizes the primary network. If the primary network is unavailable, it automatically connects to the secondary network.
Dynamic Hotspot Configuration:
The device reconfigures its hotspot (SoftAP) based on the active station connection, ensuring the hotspot name matches the network in use.
Real-time Status Display:
An I2C-connected LCD (JHD 162A) displays key system statuses—scanning, connecting, connection details, and hotspot configuration—so users can easily monitor progress.
Automatic Reconnection:
In case the WiFi station connection is lost, the system continuously scans for available networks and reconnects without manual intervention.
Easy Customization:
WiFi credentials and hotspot names are set using simple placeholder variables, allowing users to quickly adapt the code to their own networks.
Requirements

Hardware:
ESP8266-based board (e.g., NodeMCU 1.0)
JHD 162A LCD display with I2C interface
Connecting wires and a breadboard or custom PCB for prototyping
Software:
Arduino IDE
Libraries:
ESP8266WiFi
LiquidCrystal_I2C (or any compatible version)
Wire (included with Arduino IDE)
LWIP, NAPT, and DNS (provided by the ESP8266 core)
Setup & Usage

Clone the Repository:
Use Git to clone the repository to your local machine:
git clone https://github.com/yourusername/WiFi-Extender-Hotspot-Switch.git
Update Credentials:
Open main.ino in the Arduino IDE and update the placeholder values for:
PRIMARY_SSID and PRIMARY_PASS
SECONDARY_SSID and SECONDARY_PASS
Replace these with your own WiFi credentials.
Hardware Connections:
Connect your I2C LCD:
SDA: GPIO4 (adjust in the code if necessary)
SCL: GPIO5
Compile & Upload:
Select the appropriate ESP8266 board (e.g., NodeMCU 1.0) and upload the code.
Monitor the Output:
The attached LCD will display real-time status messages, including scanning status, connection status, IP address, and hotspot configuration.
