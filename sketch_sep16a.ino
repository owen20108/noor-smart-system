#include <DHT.h>
#include <Servo.h> // مكتبة محرك السيرفو

// --- إعدادات حساس الحرارة والرطوبة (DHT11) ---
#define DHTPIN 8       
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

// --- إعدادات حساسات المسافة الثلاثة (Ultrasonic) ---
const int trigPin1 = 2; const int echoPin1 = 3; // S1 - المدخل
const int trigPin2 = 4; const int echoPin2 = 5; // S2 - البرج
const int trigPin3 = 6; const int echoPin3 = 7; // S3 - الساحة

// --- إعدادات وحدة الـ RGB LED (KY-016) ---
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

// --- إعدادات محرك السيرفو (علم المملكة على برج المراقبة) ---
Servo flagServo;
const int servoPin = 12; // تم تخصيص البن 12 للسيرفو للحفاظ على توصيلات الليد كما هي

unsigned long lastDHTTime = 0;
unsigned long lastActionTime = 0;
bool zoneTriggered = false;

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 20000);
  if (duration == 0) return -1;
  long distance = duration * 0.034 / 2;
  return distance;
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(trigPin1, OUTPUT); pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT); pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); pinMode(echoPin3, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // ربط السيرفو بالبن 12 وتعيين وضعية البداية (0)
  flagServo.attach(servoPin);
  flagServo.write(0);

  // إضاءة افتتاحية باللون الأبيض الباهت
  setColor(50, 50, 50);
  delay(1000);
}

void loop() {
  long d1 = readDistance(trigPin1, echoPin1);
  long d2 = readDistance(trigPin2, echoPin2);
  long d3 = readDistance(trigPin3, echoPin3);

  int threshold = 20; // المسافة بالسنتي

  if (millis() - lastActionTime > 1500) {
    if (d1 > 0 && d1 < threshold) {
      Serial.println("ZONE1");
      setColor(255, 0, 0); // أحمر للمدخل
      flagServo.write(0);  // السيرفو في وضع السكون
      lastActionTime = millis();
      zoneTriggered = true;
    } 
    else if (d2 > 0 && d2 < threshold) {
      Serial.println("ZONE2");
      setColor(0, 255, 0); // أخضر للبرج
      flagServo.write(90); // تحريك السيرفو لرفع/تلويح العلم (زاوية 90)
      lastActionTime = millis();
      zoneTriggered = true;
    } 
    else if (d3 > 0 && d3 < threshold) {
      Serial.println("ZONE3");
      setColor(0, 0, 255); // أزرق للساحة
      flagServo.write(0);  // السيرفو في وضع السكون
      lastActionTime = millis();
      zoneTriggered = true;
    }
    else if (zoneTriggered && millis() - lastActionTime > 3000) {
      // إعادة ضبط الليد والسيرفو للوضع الطبيعي بعد انتهاء العرض
      setColor(50, 50, 50);
      flagServo.write(0);
      zoneTriggered = false;
    }
  }

  // قراءة الحرارة والرطوبة كل 5 ثوانٍ بدون إيقاف النظام
  if (millis() - lastDHTTime > 5000) {
    lastDHTTime = millis();
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h) && !isnan(t)) {
      Serial.print("ENV:");
      Serial.print(t);
      Serial.print(",");
      Serial.println(h);
    }
  }

  delay(50);
}