# 🤖 HUSH – A Smart Cradle and Baby Monitoring System 🧒

|| Research paper accepted in **SoCTA Conference 2025 (10th International Conference)** !!


## 🧠 Overview

**HUSH** is an Internet of Things (IoT)-based smart cradle and baby monitoring system designed to help parents remotely monitor and ensure the well-being of their infants — whether at home, work, or in healthcare facilities. It leverages sensors, microcontrollers, and a live video feed to track key parameters like **temperature**, **humidity**, **wetness**, **sound**, and **motion**, ensuring a safe and responsive environment for the baby.

---

## 🎯 Aim & Target Audience

- **Aim:** To build an affordable and intelligent cradle system that automates infant monitoring and notifies parents about any discomfort or environmental anomalies without manual intervention.
- **Target Users:**
  - Parents with newborns, especially working couples.
  - Caregivers in hospitals and neonatal care units.
  - Daycare and crèche facilities needing automated monitoring.

---

## ⚙️ Features

- 🔊 **Sound Detection:** Alerts if the baby is crying or if loud noise is detected.
- 🌡️ **Temperature & Humidity Monitoring:** Notifies parents if ambient conditions are uncomfortable. Also triggers an auto-cooling fan if needed.
- 💧 **Wetness Detection:** Detects if the baby’s bedding is wet due to urination or vomiting.
- 🎥 **Live Streaming:** ESP32-CAM provides a real-time video feed of the baby via a mobile app.
- 👣 **Motion Detection:** Identifies unusual motion or potential intruders using PIR sensors.
- 📱 **Mobile App Integration:** Built with Blynk for real-time updates, control, and historical data visualization.

---

## 🛠️ Tech Stack

### 📡 Hardware

- **NodeMCU ESP8266** – Microcontroller with Wi-Fi
- **ESP32-CAM** – Camera module for live video
- **DHT11 Sensor** – Measures temperature and humidity
- **Wetness Sensor** – Detects moisture in bedding
- **PIR Motion Sensor** – Detects baby/intruder movements
- **Sound Sensor Module** – Detects noise level
- **Relay + Mini Fan** – Cools environment if temperature rises
- **DC Power Source** – Powers the system
- **Custom Wooden Cradle**

### 💻 Software

- **Arduino IDE** – Coding and firmware upload
- **Blynk App** – Android/iOS app for live monitoring and alerts
- **Platform:** Windows 7/10/11

---

## 🧪 How It Works

1. **Sensor Monitoring:**
   - Periodically reads temperature, humidity, sound, wetness, and motion data.
   - If thresholds are exceeded, alerts are triggered and sent to the mobile app.

2. **Live Camera Feed:**
   - ESP32-CAM streams video over Wi-Fi, viewable through Blynk.

3. **Mobile App:**
   - Controls cradle functionalities and provides live statistics.
   - Displays graphs of temperature/humidity over time.

4. **Automation Example:**
   - If temp > 30°C → Turn ON mini fan
   - If sound > 85db → Send alert to app
   - If wetness detected → Notify caregiver

---

## 📊 Results Snapshot

- 📈 Mobile dashboard graphs for temperature and humidity  
  <img src="https://github.com/user-attachments/assets/f2d26c27-7cad-401d-9d7c-e6bc50045feb" alt="blynk_setup" width="40%" />
  <br>

- ✅ Real-time alerts on baby's crying, wetness, high temperature, or intrusions  
  <div style="display: flex; gap: 10px;">
    <img src="https://github.com/user-attachments/assets/b2374d78-2049-4e9f-89b5-0b94005fca35" alt="blynk_ss3" width="45%" />
    <img src="https://github.com/user-attachments/assets/6fe3422b-d159-46d5-8dbd-f0c90dba6d40" alt="blynk_ss4" width="45%" />
  </div>
  <br>

- 📷 Live video feed accessible anytime through the app (snapshot of the image from app) (VERY LOW RES image ALERT)
  <img src="https://github.com/user-attachments/assets/d91980de-f11e-4507-8669-06d496b87f06" alt="blynk_ss5" width="40%" />
  <br>

- 📲 All components tested successfully with minimal latency and high accuracy.
