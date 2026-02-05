#include <DHT.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// --- Pulse Sensor Setup ---
#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>

// --- Pin Definitions ---
#define DHTPIN 2
#define DHTTYPE DHT22
#define TRIG_PIN 3
#define ECHO_PIN 4
#define PULSE_PIN A0
#define GPS_RX 8
#define GPS_TX 9

// --- Objects ---
DHT dht(DHTPIN, DHTTYPE);
PulseSensorPlayground pulseSensor;
TinyGPSPlus gps;
SoftwareSerial ss(GPS_RX, GPS_TX); // RX, TX for GPS

void setup() {
  Serial.begin(115200);
  ss.begin(9600); // Most GPS modules use 9600
  
  dht.begin();
  
  pulseSensor.analogInput(PULSE_PIN);
  pulseSensor.setThreshold(550); // Uno threshold is lower than ESP32
  pulseSensor.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("Arduino Uno Pet Monitor Started...");
}

void loop() {
  // 1. Process GPS Data
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }

  // 2. Read Pulse Sensor
  if (pulseSensor.sawStartOfBeat()) {
    // Beat detected
  }

  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 2000) { // Update every 2 seconds
    lastUpdate = millis();

    // --- DHT Readings ---
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    // --- Ultrasonic Distance ---
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2;

    // --- Pulse Rate ---
    int bpm = pulseSensor.getBeatsPerMinute();

    // --- Print to Serial ---
    Serial.println("--- PET DATA ---");
    Serial.print("Temp: "); Serial.print(t); Serial.println("C");
    Serial.print("Hum: "); Serial.print(h); Serial.println("%");
    Serial.print("BPM: "); Serial.println(bpm);
    Serial.print("Dist: "); Serial.print(distance); Serial.println("cm");
    
    Serial.print("Location: ");
    if (gps.location.isValid()) {
      Serial.print(gps.location.lat(), 6);
      Serial.print(", ");
      Serial.println(gps.location.lng(), 6);
    } else {
      Serial.println("Searching for GPS...");
    }
    Serial.println("----------------");
  }
}