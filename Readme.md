🐾 IoT Pet Monitoring & Tracking SystemAn end-to-end IoT solution designed to monitor a pet’s health (BPM), environment (Temp/Humidity), activity (Ultrasonic), and real-time location (GPS). Data is transmitted via MQTT and visualized on a dynamic Node-RED dashboard.

🚀 Features
Real-time Health Tracking: Monitor heart rate (BPM) using a Pulse Sensor.
Environmental Monitoring: Track ambient temperature and humidity via DHT22.
Activity/Presence Detection: Ultrasonic sensor to detect if the pet is in a "safe zone."
Live Location Mapping: Integrated GPS tracking (NEO-6M) displayed on a world map.
Smart Alerts: Automated notifications in Node-RED for dangerous temperature or heart rate levels.

🏗️ System Architecture
The project follows a modular IoT pipeline:
Perception Layer: Sensors collect physical data from the pet's environment.
Processing Layer: ESP32 processes raw signals and packages them into JSON format.
Transport Layer: Data is published via the MQTT protocol over local Wi-Fi.
Application Layer: A Node-RED instance (Broker + Dashboard) parses the data and provides a UI for the user.

💻 Software Setup
1. Arduino IDE
Install the following libraries via the Library Manager:
PubSubClient (by Nick O'Leary)
DHT sensor library (by Adafruit)
PulseSensor Playground
TinyGPS++

2. Node-RED
Install node-red-dashboard for gauges and charts.
Install node-red-contrib-web-worldmap for location tracking.
Import the provided JSON flow to set up the dashboard instantly.

📊 Dashboard PreviewThe Node-RED dashboard includes:
Vitals Section: Gauges for Temperature, Humidity, and Heartbeat.
Map Section: A live-updating OpenStreetMap view showing the pet's current coordinates.
Alert Logs: Visual notifications when sensor thresholds are breached.

📝 Modular Design & Scalability
This project is built with modular architecture in mind. By separating the sensor logic from the transmission logic, the system can be scaled to:
Support multiple pets by adding unique MQTT Client IDs.
Integrate with Cloud services (AWS IoT/Azure) for remote access.
Add more specialized sensors (e.g., Accelerometers for gait analysis) without rewriting the core network code.