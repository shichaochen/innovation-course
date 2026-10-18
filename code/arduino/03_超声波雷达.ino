/*
 * 案例 3：超声波雷达扫描仪（进阶）
 * 功能：舵机带动 HC-SR04 在 0~180° 间来回扫描，串口输出“角度,距离”
 *       可配合串口绘图器（Arduino IDE：工具 -> 串口绘图器）看波形
 * 接线：舵机信号线->D9, VCC->5V, GND->GND（舵机较多时建议独立供电）
 *       HC-SR04 Trig->D7, Echo->D8, VCC->5V, GND->GND
 * 板子：Arduino Uno
 */
#include <Servo.h>

const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int SERVO_PIN = 9;

Servo radar;

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  return duration / 58;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  radar.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("angle,distance");  // 表头，方便导入表格
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 5) {   // 正向扫描
    radar.write(angle);
    delay(60);  // 等舵机转到位
    Serial.print(angle);
    Serial.print(",");
    Serial.println(readDistanceCM());
  }
  for (int angle = 180; angle >= 0; angle -= 5) {   // 反向扫描
    radar.write(angle);
    delay(60);
    Serial.print(angle);
    Serial.print(",");
    Serial.println(readDistanceCM());
  }
}
