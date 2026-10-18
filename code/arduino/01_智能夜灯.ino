/*
 * 案例 1：智能夜灯
 * 功能：环境越暗，LED 越亮；环境亮时 LED 熄灭
 * 接线：光敏电阻一脚接 5V，另一脚接 A0，同时通过 10k 电阻接 GND（分压）
 *       LED 长脚（正极）经 220Ω 电阻接 D9，短脚接 GND
 * 板子：Arduino Uno
 */
const int LDR_PIN = A0;   // 光敏电阻
const int LED_PIN = 9;    // LED（PWM 引脚）

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);          // 0（暗）~ 1023（亮）
  int brightness = map(light, 0, 1023, 255, 0);  // 越暗越亮
  brightness = constrain(brightness, 0, 255);
  analogWrite(LED_PIN, brightness);

  Serial.print("光照值: ");
  Serial.print(light);
  Serial.print("  -> 亮度: ");
  Serial.println(brightness);
  delay(200);
}
