# ⌚ Paper Watch — W-01

> *"The only watch that works for you, not a server."*

[![Status](https://img.shields.io/badge/status-in_development-yellow)](.)
[![Version](https://img.shields.io/badge/version-0.1_MVP-blue)](.)
[![License](https://img.shields.io/badge/license-GPL_v3-green)](.)
[![Platform](https://img.shields.io/badge/platform-ESP32--S3-red)](.)

---

## What is this?

The Guardian Watch is an open-source, privacy-first e-ink smartwatch built as a direct rejection of surveillance capitalism in wearables. No data mining. No subscriptions. No cloud dependency. Just a rugged, always-readable tool that works for you.

**Core pillars:**
- **Invisible Utility** — Always-on time display, 14-day battery, built to last
- **Server-Blind Privacy** — You hold the encryption key. The server never does.
- **Hacker Aesthetic** — E-ink display, repairable hardware, fully open-source firmware

---

## Hardware

| Component | Part | Role |
|---|---|---|
| MCU | ESP32-S3-WROOM-1 (N16R8) | Brain — WiFi, BLE, encryption |
| Display | Waveshare 1.54" E-Ink (SPI) | 200×200px, always-on face |
| Motion | MPU-6050 (6-axis IMU) | Steps, fall detection, lift-to-wake |
| Thermal | MLX90614 (IR) | Contactless temperature / fever check |
| Battery | 500mAh LiPo (602530) | 14+ day life via deep sleep |
| Charging | TP4056 (USB-C) | With DW01 over-discharge protection |
| Haptics | Coin vibration motor | Silent alerts, fall notification |
| Light | 3mm white LED (side-firing) | Night vision / torch |

---

## Wiring

### Display (Waveshare 1.54" E-Ink)

| Display Pin | ESP32-S3 GPIO |
|---|---|
| DIN (MOSI) | GPIO 11 |
| CLK | GPIO 12 |
| CS | GPIO 10 |
| DC | GPIO 8 |
| RST | GPIO 9 |
| BUSY | GPIO 7 |
| VCC | 3.3V |
| GND | GND |

### Sensors (I2C — shared bus)

| Sensor Pin | ESP32-S3 GPIO |
|---|---|
| SDA (both sensors) | GPIO 41 |
| SCL (both sensors) | GPIO 42 |
| MPU-6050 INT | GPIO 4 |
| VCC | 3.3V |
| GND | GND |

### Other

| Component | ESP32-S3 GPIO |
|---|---|
| Button — Menu (Top) | GPIO 0 |
| Button — Back (Middle) | GPIO 1 |
| Button — Torch (Side) | GPIO 2 |
| Vibration Motor | GPIO 38 |
| LED (Night Vision) | GPIO 39 |
| Battery ADC | GPIO 34 |

> Full circuit diagram: `docs/wiring.png` *(coming soon)*

---

## Project Structure

```
GuardianWatch/
├── platformio.ini        # Build config and library deps
├── README.md
├── docs/
│   └── wiring.png        # Circuit diagram
└── src/
    ├── main.cpp          # Entry point — setup() and loop() only
    ├── config.h          # ALL pin numbers and constants live here
    ├── display/          # E-ink driver and drawing primitives
    ├── sensors/          # IMU (MPU-6050) and temperature (MLX90614)
    ├── ui/               # Watch faces and screen layouts
    ├── power/            # Battery reading and deep sleep logic
    └── safety/           # Fall detection protocol and alerts
```

---

## Building & Flashing

**Requirements:**
- VSCode + PlatformIO extension
- ESP32-S3 board connected via USB-C

```bash
# Clone the repo
git clone https://github.com/yourusername/guardian-watch.git
cd guardian-watch

# Open in VSCode, then in PlatformIO:
# 1. Click the checkmark to Build
# 2. Click the arrow to Upload
# 3. Click the plug icon to open Serial Monitor (115200 baud)
```

---

## Firmware Roadmap

- [x] Project scaffold and folder structure
- [x] PlatformIO build compiling clean
- [ ] E-ink display — hello world
- [ ] Watch face — dark mode, time + date
- [ ] MPU-6050 — step counting
- [ ] MPU-6050 — fall detection
- [ ] MLX90614 — temperature reading
- [ ] Deep sleep + timer wake
- [ ] Battery percentage via ADC
- [ ] Fall protocol — vibrate → WiFi alert
- [ ] Black Box encryption (SHA-256, NVS)
- [ ] BLE phone notifications

---

## The "Black Box" Privacy Protocol

On first boot, the ESP32 generates a cryptographic master key locally. It is displayed **once** on the e-ink screen for the user to write down, then stored in the ESP32's encrypted NVS partition. It is **never transmitted** to any server. All health data is encrypted on-device before any wireless transmission. The server receives only ciphertext — even a full server compromise exposes nothing.

---

## License

GPL v3 — any fork of this code must also be open-source. See `LICENSE`.

---

*Built by a student who refused to wear a spy.*
