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


   # Detailed Setup and Usage Guide

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installing the Arduino IDE](#installing-the-arduino-ide)
- [Adding ESP8266 Board Support](#adding-esp8266-board-support)
- [Installing Required Libraries](#installing-required-libraries)
- [Hardware Setup and Wiring](#hardware-setup-and-wiring)
- [Project Configuration and Usage](#project-configuration-and-usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Prerequisites

- A computer with an internet connection.
- Basic knowledge of Arduino programming.
- **Hardware:**
  - ESP8266-based board (e.g., NodeMCU 1.0)
  - JHD 162A LCD display with I2C interface
  - Jumper wires and a breadboard (or custom PCB)
  
## Installing the Arduino IDE

1. **Download the Arduino IDE:**
   - Visit the [Arduino Software page](https://www.arduino.cc/en/software) and download the version suitable for your operating system.
2. **Install the Arduino IDE:**
   - Follow the installation instructions for your OS (Windows, macOS, or Linux).

## Adding ESP8266 Board Support

1. **Open the Arduino IDE.**
2. **Open Preferences:**
   - Navigate to `File` > `Preferences`.
3. **Add the ESP8266 URL:**
   - In the "Additional Boards Manager URLs" field, add:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
4. **Install ESP8266 Boards:**
   - Go to `Tools` > `Board` > `Boards Manager...`
   - Search for "ESP8266" and click **Install** on the "esp8266 by ESP8266 Community" package.
5. **Select Your Board:**
   - Go to `Tools` > `Board` and choose "NodeMCU 1.0 (ESP-12E Module)".

## Installing Required Libraries

1. **LiquidCrystal_I2C Library:**
   - In the Arduino IDE, navigate to `Sketch` > `Include Library` > `Manage Libraries...`
   - Search for "LiquidCrystal I2C" (versions by John Rickman or Frank de Brabander work well) and click **Install**.
2. **ESP8266WiFi Library:**
   - This library comes with the ESP8266 board package.
3. **Wire Library:**
   - This library is included with the Arduino IDE core.
4. **Additional Libraries:**
   - If your project uses LWIP, NAPT, or NetDump, these are typically included with the ESP8266 core or provided by the respective library.

## Hardware Setup and Wiring

### Components

- **ESP8266 Board:** (e.g., NodeMCU 1.0)
- **I2C LCD Display:** (e.g., JHD 162A with I2C adapter)
- **Connecting Wires and Breadboard**

### Wiring Instructions

- **LCD Display:**
  - **VCC:** Connect to 3.3V (or 5V if your module supports it; check your LCD specifications).
  - **GND:** Connect to Ground.
  - **SDA:** Connect to GPIO4 (D2 on NodeMCU; modify in the code if using a different pin).
  - **SCL:** Connect to GPIO5 (D1 on NodeMCU; modify in the code if using a different pin).

- **ESP8266 Board:**
  - Ensure the board is powered (via USB) and properly connected to your computer for code uploading.
## LCD Display Details

The project uses an I2C-connected LCD to provide real-time status updates. Below is a breakdown of the information you can expect to see on the display during different phases of operation:

- **Startup:**  
  - **Line 1:** "WiFi Extender"  
  - **Line 2:** "Starting..."  
  This indicates that the device is booting up and initializing its components.

- **Scanning for WiFi:**  
  - **Line 1:** "Scanning for"  
  - **Line 2:** Displays the primary network SSID (e.g., "YOUR_PRIMARY_WIFI_SSID")  
  The device scans for the primary WiFi network and updates the display with the target SSID.

- **Waiting for Network:**  
  - **Line 1:** "Waiting for"  
  - **Line 2:** Displays the primary network SSID  
  If the primary network is not detected immediately, this message appears while the device continues to scan.

- **Connecting to WiFi:**  
  - **Line 1:** "Connecting to"  
  - **Line 2:** Displays the SSID being connected to  
  This message appears once the device starts the connection process.

- **Connected Status:**  
  - **Line 1:** "Connected:"  
  - **Line 2:** Shows the assigned IP address (e.g., "192.168.x.x")  
  Once a successful connection is made, the LCD displays the IP address of the ESP8266.

- **Hotspot (SoftAP) Configuration:**  
  - **Line 1:** "Hotspot:"  
  - **Line 2:** Displays the AP name (e.g., "AP_PRIMARY" or "AP_SECONDARY")  
  After connecting to the WiFi network, the device configures its own hotspot. This message indicates the name of the active SoftAP.

- **NAT Activation:**  
  - **Line 1:** "NAT active on"  
  - **Line 2:** Displays the AP name  
  This confirms that NAT (Network Address Translation) has been successfully initialized and is active on the hotspot.

- **Reconnection Attempts:**  
  - **Line 1:** "WiFi lost!" or "Reconnect"  
  - **Line 2:** Displays status messages like "Scanning nets..." or "failed"  
  If the station connection is lost, the LCD updates with reconnection status messages, guiding you through the reconnection process.

## Project Configuration and Usage

1. **Clone or Download the Repository:**
   ```bash
   git clone https://github.com/MARSHALYADAV/wifi_extender.git

