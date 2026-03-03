# 🐾 Smart IoT Pet Monitoring System

## Real-Time Health, Environment, and Location Tracking
---

## 📌 Problem Statement

Pets are highly vulnerable to environmental and physiological risks that often go unnoticed until it is too late.  
Traditional pet care methods fail to provide:

- Continuous real-time health monitoring  
- Environmental awareness (temperature & humidity risks)  
- Immediate alerts during abnormal conditions  
- Remote location tracking  

This lack of data and delayed response can lead to severe health issues or loss of pets.

---

## 💡 Proposed Solution

A **Smart IoT-based Pet Monitoring System** that continuously tracks:

- Heart Rate (BPM)
- Temperature & Humidity
- Motion / Activity
- GPS Location

The system transmits sensor data in real time using **MQTT** and visualizes it on a **Node-RED Dashboard**, triggering alerts when thresholds are breached.

---

## 🏗 System Architecture

The system is built on three main layers:

### 1. Wearable Device (Edge Layer)
- ESP32 microcontroller  
- Pulse Sensor (Heart Rate)  
- DHT22 (Temperature & Humidity)  
- Ultrasonic Sensor (Motion / Proximity)  
- NEO-6M GPS Module  

### 2. Communication Layer
- MQTT Protocol  
- Lightweight JSON payloads  
- Wi-Fi connectivity via ESP32  

### 3. Cloud & Visualization Layer
- Node-RED Engine  
- Real-time dashboard  
- Alert and notification system  

---

## 🔌 Hardware Components

| Component | Purpose |
|---------|--------|
| ESP32 | Main controller with Wi-Fi |
| Pulse Sensor | Heart rate monitoring |
| DHT22 | Temperature & humidity sensing |
| Ultrasonic Sensor | Motion/activity detection |
| NEO-6M GPS | Location tracking |
| Breadboard | Prototyping |

<img width="911" height="467" alt="image" src="https://github.com/user-attachments/assets/547da53d-fa37-46f2-a798-f664fc549282" />


---

## 🔁 Data Flow (Node-RED)

1. `mqtt in` node subscribes to sensor topic  
2. `json` node parses incoming payload  
3. Data routed to dashboard widgets  
4. Function node evaluates alert conditions  
5. Notification & email alerts triggered  

---

## 🧠 Node-RED Flow Diagram

<img width="981" height="501" alt="image" src="https://github.com/user-attachments/assets/f9ecac7d-bb59-48f3-b294-3798d80a2e7e" />


---

## ⚙️ Setup Instructions


1. Flash the ESP32 with the firmware code  
2. Configure Wi-Fi credentials and MQTT broker details  
3. Start MQTT broker (local or cloud)  
4. Import Node-RED flow  
5. Deploy dashboard

<img width="622" height="492" alt="image" src="https://github.com/user-attachments/assets/4d807edc-2f30-4e1d-b870-061cd37e143e" />


---

## 📈 Results & Analysis

### Result 1: Resting State
- BPM: 60–80 (Normal)
- Motion: No movement
- GPS: Static location  
- Status: Green  
- Alert triggered if BPM < 40

<img width="1270" height="408" alt="image" src="https://github.com/user-attachments/assets/f5c6abb6-b4d5-472f-a1c2-a0f9833c1047" />


### Result 2: High Activity State
- BPM: 120–160
- Motion: Continuous activity  
- Status: Yellow/Orange  
- Alert triggered if BPM > 180

<img width="1250" height="409" alt="image" src="https://github.com/user-attachments/assets/e40b341d-3f28-4fa6-ae99-7b6b74650951" />


### Result 3: Walking State
- BPM: 90–110
- Motion: Intermittent  
- GPS: Continuous path tracking  
- Status: Normal  

<img width="1261" height="425" alt="image" src="https://github.com/user-attachments/assets/76ba0191-6fdc-48e4-9d55-d1c064e2397b" />


## ✅ Conclusion

The system successfully demonstrates a full-stack IoT solution for real-time pet health and location monitoring.  
Integration of ESP32, MQTT, and Node-RED enables reliable visualization, alerting, and tracking.

The system accurately classifies pet activity states and responds instantly to abnormal conditions.

---

## 🚀 Future Enhancements

- Improved battery optimization  
- Miniaturized wearable collar design  
- Machine learning-based behavior analysis  
- Mobile app integration  

---
