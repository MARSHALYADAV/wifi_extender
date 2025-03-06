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

This guide explains how to set up and use the WiFi Extender & Hotspot Switch project from scratch. It covers installing the Arduino IDE, adding ESP8266 board support, installing required libraries, wiring the hardware, and configuring the project.

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

## Project Configuration and Usage

1. **Clone or Download the Repository:**
   ```bash
   git clone https://github.com/MARSHALYADAV/wifi_extender.git

