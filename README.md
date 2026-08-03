# ESPHome code for the Waveshare esp32-s3 7-inch

ESPHome code to use for your Waveshare-ESPHome-LVGL-tinkering.

## My project
<!--img align="right" src="overview.png" alt="overview" width="300"/-->
<img src="images\example_v2.png" alt="overview" width="80%"/>

Only one page, nothing fancy, but examples with this board and ESPHome together with LVGL are scarse and far apart, so I thought I would share my project. 

## ESP32-S3-Touch-LCD-7
https://www.waveshare.com/esp32-s3-touch-lcd-7.htm

ESP32-S3 7inch Capacitive Touch Display Development Board, ESP32 With Display, 800×480, 5-point Touch, 32-bit LX7 Dual-core Processor, Up to 240MHz Frequency, Supports WiFi & Bluetooth, With Onboard Antenna

## Code
Complete example **[waveshare-esp32-s3-7inch_v2.yaml](waveshare-esp32-s3-7inch.yaml)**
Probably not nearly as optimal as you could do, but it seems to do the job as indented. 

## Windows installation note
This project is meant to be built with ESPHome on Windows using a Python virtual environment.

Compatibility notes for this YAML:
- Python: use Python 3.11 or 3.12 on Windows.
- ESPHome: use ESPHome 2026.7.x or newer. Older releases such as 2026.6.x are not compatible with the newer `image:` platform syntax used in this file.
- Firmware target: ESP32-S3 with ESP-IDF framework, 16 MB flash, and octal PSRAM at 80 MHz.
- Display stack: LVGL, `web_server` v3, GT911 touch, and ST7701S display support must be available in the ESPHome release you install.
- Project files: keep the local `components/` and `images/` folders next to the YAML because this config loads custom components and local image assets from disk.

Recommended Windows setup:
1. Install Python 3.11 or 3.12.
2. Create and activate a virtual environment.
3. Install ESPHome with `pip install esphome` or pin a tested release with `pip install esphome==2026.7.*`.
4. Run ESPHome from this folder so the local custom components resolve correctly.

If you need maximum safety, prefer the latest stable ESPHome release that still supports ESP32-S3, LVGL, `web_server` v3, and the `image:` platform syntax used here.

## Credit
This is based on work from [DMonkey-hub](https://github.com/DMonkey-hub/esphome/tree/main)
