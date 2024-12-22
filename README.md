# Esp8266-WebLED-Control
This project demonstrates how to control an LED using a web server hosted on an ESP8266 microcontroller. The ESP8266 connects to a Wi-Fi network and provides a simple web interface for controlling the LED state (ON/OFF).

The interface is built using Bootstrap 5 for styling, making it responsive and user-friendly.

# Hardware Requirements

1. ESP8266 NodeMCU
2. USB Cable (for programming and power)
3. LED (optional) (connected to GPIO if not using the built-in LED)
   
# Software Requirements

1. Arduino IDE (Version 1.8 or later)
2. ESP8266 Board Package (Install via Arduino Board Manager)
3. WiFiClient Library (Default in ESP8266 Core)

# Pin Configuration

Built-in LED on the ESP8266 is connected to GPIO 2

# Setup Instructions

1. Install Arduino IDE (if not already installed).
2. Add ESP8266 Board Support:
Open File > Preferences in Arduino IDE.
Enter this URL in Additional Board Manager URLs:
http://arduino.esp8266.com/stable/package_esp8266com_index.json
Go to Tools > Board > Boards Manager and search for ESP8266.

# Install the package.

3. Connect the ESP8266 to your computer using a USB cable.
4. Install Required Libraries:

Go to Sketch > Include Library > Manage Libraries.
Search for ESP8266WiFi and install it.
5. Upload the Code:
Replace Wi-Fi credentials in the code:
WiFi.begin("Andrul", "12345678");
Enter your SSID and password.
Select the board: NodeMCU 1.0 (ESP-12E Module).
Choose the correct Port under Tools.
Click Upload.
6. Open Serial Monitor (Baud rate: 9600).
Note down the IP Address displayed after successful connection.

# How to Use

1. Connect your device (PC/Mobile) to the same Wi-Fi network as the ESP8266.
2. Open a web browser and enter the IP Address shown in the serial monitor. Example:
http://192.168.1.100
3. You will see the LED Control Panel with ON and OFF buttons.
4. Click ON to turn the LED on, or OFF to turn it off.
   
# Code Explanation

Wi-Fi Setup: Connects ESP8266 to the given Wi-Fi network.
Server Setup: Initializes a web server on port 80.
HTML Page: Built-in Bootstrap for responsive buttons and dynamic LED status.
GET Requests: Controls LED state based on URL endpoints:
/ledon → Turns the LED ON.
/ledoff → Turns the LED OFF.
Dynamic LED Status: Displays whether the LED is currently ON or OFF.

# Example Output
Web Interface:
 (Replace this placeholder with your screenshot)
Serial Monitor Output:
Connected Successfully
192.168.1.100

# Troubleshooting
1. No Wi-Fi Connection:
Double-check SSID and password.
Restart the ESP8266.
2. No Response in Browser:
Ensure the device is connected to the same Wi-Fi network.
Confirm the IP address displayed on the serial monitor.
3. LED Not Working:
Verify wiring if using an external LED.
Check the LED polarity.

# Developed by Dipendra Chaturvedi
Let me know if you'd like any changes!

