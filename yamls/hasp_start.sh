#!/bin/sh

# Set GPIO pins for relays
gpio mode 40 output
gpio mode 1 output
gpio mode 2 output

# Initialize all relays to OFF
gpio write 40 0
gpio write 1 0
gpio write 2 0

# Set backlight
gpio mode 38 pwm
gpio pwm 38 1023  # Full brightness
