# 创新创业课程 · 教学资源库

本仓库收录创新创业课程的教学讲义（PPT）与配套代码，按主题组织，持续更新。

## 目录结构

```
innovation-course/
├── ppt/                    # 课程讲义（PowerPoint）
│   ├── Arduino开源硬件入门_创新创业课程.pptx
│   ├── GitHub奶爸级教学_创新创业课程.pptx
│   └── VibeCoding×Arduino_创新创业课程.pptx
└── code/
    └── arduino/            # Arduino 示例代码（.ino）
        ├── 01_智能夜灯.ino        # 光敏电阻 + LED：环境越暗灯越亮
        ├── 02_超声波报警器.ino     # HC-SR04 + 蜂鸣器：越近叫得越急
        └── 03_超声波雷达.ino       # 舵机 + HC-SR04：0~180° 扫描
```

## 使用说明

- `.pptx` 文件：直接用 PowerPoint / WPS / Keynote 打开即可上课使用。
- `.ino` 文件：在 Arduino IDE 中打开，选择对应开发板与端口，点"验证"后再"上传"。
  - 案例 1 接线：光敏电阻接 A0（10k 下拉分压），LED 经 220Ω 电阻接 D9
  - 案例 2 接线：HC-SR04 Trig→D7、Echo→D8，蜂鸣器接 D6
  - 案例 3 接线：舵机信号线接 D9，HC-SR04 Trig→D7、Echo→D8

## 课程讲义一览

| 讲义 | 内容 |
|---|---|
| Arduino 开源硬件入门 | Uno R3 认识、Blink 点灯、6 个创客项目案例、从原型到产品 |
| GitHub 奶爸级教学 | 注册/2FA、建仓库、搜索、Issues、Fork/PR、部署上线 |
| Vibe Coding × Arduino | 和 AI 结对编程：四步法、提示词技巧、3 个实操案例 |
