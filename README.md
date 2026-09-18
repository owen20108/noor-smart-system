# noor-smart-system
Interactive Visitor Station &amp; Heritage Protection Hub for WRO 2026
# Noor Smart System | نظام نور الذكي
Interactive Visitor Station & Heritage Protection Hub | WRO 2026 (Robots Meet Culture)

## 📌 About the Project (فكرة المشروع)
**Noor Smart System** is an interactive, hybrid physical-digital visitor station designed to protect delicate historical mudbrick structures (such as Diriyah Palace) from the wear and tear of direct human traffic. 

Instead of allowing large crowds inside fragile ancient sites, visitors interact with a physical cardboard model connected via IoT sensors. This triggers a real-time immersive 3D digital experience (Three.js), environmental monitoring, and localized audio narration—providing a sustainable and engaging tourism solution.

---

## 👥 Team Members (أعضاء الفريق)
* **تركي بن خالد بن محمد العمير** (Turki Al-Omair)
* **عبدالرحمن بن محمد الدوسري** (Abdulrahman Al-Dosari)

---

## ⚙️ System Architecture (هندسة النظام)
The project integrates hardware microcontrollers with modern web technologies:

1. **Hardware (العتاد):**
   * **Arduino Microcontroller:** Main processing unit for sensors and actuators.
   * **Ultrasonic Sensors (HC-SR04):** Placed on the physical model to detect visitor proximity and zone selection.
   * **DHT11 Sensor:** Monitors ambient temperature and humidity for preventive conservation.
   * **Servo Motor & RGB LED:** Provide physical motion (e.g., flag or indicator) and visual feedback.

2. **Software & Web Interface (البرمجيات):**
   * **C++ (Arduino IDE):** Non-blocking firmware for sensor polling and serial communication.
   * **Web Serial API:** Connects the browser directly to the Arduino in real-time.
   * **Three.js & JavaScript:** Renders the interactive 3D model of the heritage site.
   * **Web Speech API:** Provides automated Arabic voice narration for each historical zone.

---

## 🚀 How It Works (آلية العمل)
1. The visitor approaches a specific zone on the physical model.
2. The ultrasonic sensor detects proximity, and Arduino sends a serial command to the web application.
3. The 3D digital camera smoothly pivots to the selected landmark, the RGB LED changes color, and an audio guide describes the site.
4. If ambient temperature/humidity rises, the system shifts the digital interface to **"Night Mode"** to optimize user experience and resource tracking.

---

## 📂 Repository Structure (مكونات المستودع)
* `/arduino_firmware` -> C++ source code for the Arduino board.
* `/web_interface` -> HTML, CSS, and Three.js 3D rendering scripts.
* `/assets` -> 3D models (`.glb`) and images of the project setup.
