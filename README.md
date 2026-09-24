# noor-smart-system
Arduino-code مجلد لعرض كود الاردينو

arduino-components-installment-guide مجلد به دليل توصيلات الاردينو 

diriyah-3dModel مجلد به مجسم الدرعية  

full-project-shot  مجلد لعرض لقطات فيديو للمشروع قصيرة

install-diriyah-cartoon-with-arduino-components مجلد توثيق تركيب مجسم الكرتون مع المشروع 


making-of-Dirriyah-cartoon  مجلد لعرض عمل مجسم قصر الدرعية يدويا بالفيديو

testing- arduino with web api مجلد لعرض توصيل واختبار واجهة المشروع مع الاردينو

web-interface-project-full ملفات واجهة المشروع 

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

#### ⚙️ دليل التوصيلات الهندسية (Hardware Wiring Guide)

قم بتجهيز خطوط الطاقة العامة على لوحة التجارب (Breadboard) أولاً:
* **خط 5V:** من الأردوينو إلى الخط الموجب (+) في البريد بورد.
* **خط GND:** من الأردوينو إلى الخط السالب (-) في البريد بورد.

### جدول التوصيلات التفصيلي:
| اسم المكون | طرف المكون (Pin) | التوصيل بالأردوينو / البريد بورد | الوظيفة |
| :--- | :--- | :--- | :--- |
| **1. حساس DHT11** | VCC / GND / DATA | خط 5V / خط GND / Pin 8 | قراءة حرارة ورطوبة البيئة |
| **2. حساس المسافة (S1 - المدخل)** | Trig / Echo | Pin 2 / Pin 3 | استشعار منطقة المدخل |
| **3. حساس المسافة (S2 - البرج)** | Trig / Echo | Pin 4 / Pin 5 | استشعار منطقة البرج الدفاعي |
| **4. حساس المسافة (S3 - الساحة)** | Trig / Echo | Pin 6 / Pin 7 | استشعار منطقة المجالس والساحة |
| **5. وحدة الإضاءة RGB** | R / G / B / GND | Pin 11 / Pin 10 / Pin 9 / خط GND | إضاءة ديناميكية مع كل منطقة |
| **6. محرك السيرفو (SG90)** | Signal (برتقالي/أصفر) | Pin 12 | تحريك علم المملكة على البرج |

---

## 🚀 طريقة التشغيل (How to Run)

### أولاً: رفع كود الأردوينو (Arduino Code)
1. افتح برنامج **Arduino IDE**.
2. تأكد من تثبيت المكتبات المطلوبة (مثل `DHT sensor library` و `Servo`).
3. افتح ملف الكود البرمجي الخاص بالمشروع (`arduino_code.ino`).
4. وصل لوحة الـ Arduino Uno بالحاسوب واضغط على **Upload** لرفع الكود.

### ثانياً: تشغيل واجهة المتصفح (Web 3D Viewer)
بما أن المشروع يستخدم واجهة تفاعلية تعتمد على الـ WebGL ومتصففات الويب الحديثة، يُفضل استخدام بيئة تطوير محلية مثل **Visual Studio Code**:

1. افتح مجلد المشروع في برنامج **Visual Studio Code**.
2. تأكد من تثبيت الإضافة الشهيرة **Live Server** من متجر الإضافات.
3. افتح ملف الـ HTML الخاص بالمشروع (`index.html`).
4. اضغط على زر **Go Live** في الشريط السفلي لـ VS Code ليفتح المجسم التفاعلي تلقائياً على متصفح الويب الافتراضي لديك.
5. انقر على زر **"اتصال بالأردوينو"** داخل الصفحة لتفعيل الربط المباشر واستعراض تفاعل الحساسات مع المجسم!

---

## 📂 Repository Structure (مكونات المستودع)
* `/arduino_firmware` -> C++ source code for the Arduino board.
* `/web_interface` -> HTML, CSS, and Three.js 3D rendering scripts.
* `/assets` -> 3D models (`.glb`) and images of the project setup.
