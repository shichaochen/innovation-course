/*
 * 案例 2：超声波测距报警器
 * 功能：HC-SR04 测距；30cm 内有物体时蜂鸣器报警，距离越近叫得越急促
 * 接线：HC-SR04 VCC->5V, GND->GND, Trig->D7, Echo->D8
 *       有源/无源蜂鸣器一脚接 D6，一脚接 GND（无源用 tone() 驱动）
 * 板子：Arduino Uno
 */
const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int BUZZER_PIN = 6;
const int ALARM_DIST = 30;   // 报警距离阈值（cm）

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);  // 超时 30ms
  return duration / 58;  // 换算为厘米
}

void loop() {
  long dist = readDistanceCM();
  Serial.print("距离: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 0 && dist < ALARM_DIST) {
    int freq = map(dist, 0, ALARM_DIST, 2000, 500);  // 越近音调越高
    tone(BUZZER_PIN, freq, 120);
    delay(map(dist, 0, ALARM_DIST, 150, 600));       // 越近间隔越短
  } else {
    noTone(BUZZER_PIN);
    delay(200);
  }
}
