# radarGun

A low-cost, handheld Doppler radar gun for measuring baseball pitch speed, built around an ESP32 and a 24 GHz microwave sensor.

## Overview

Commercial radar guns typically cost well over $100. This project aims to build a working alternative from inexpensive, off-the-shelf components while documenting the full engineering process, from first wiring tests to field calibration.

The device works on the Doppler principle: a moving ball shifts the frequency of the reflected microwave signal in proportion to its speed. The ESP32 measures that frequency shift and converts it to miles per hour.

## Goals

| Goal | Target |
|---|---|
| Total build cost | Under $100 CAD |
| Accuracy | ±2 mph against a reference radar gun |
| Usability | Press-and-hold to measure; peak speed stays on the display |
| Documentation | Record each build stage, including problems and fixes |

## How it works

```text
Moving baseball
    ↓  reflected 24 GHz signal
CDM324 Doppler radar module
    ↓  small analog Doppler signal
LM358 amplifier / filter
    ↓  amplified, biased waveform
LM393 comparator
    ↓  digital pulses
ESP32
    ↓  frequency → speed, peak-speed logic
4-digit 7-segment display
```

At the CDM324's nominal 24.125 GHz carrier, speed relates to Doppler frequency as:

```text
mph ≈ Doppler frequency (Hz) / 65.5
```

For example, a 90 mph pitch produces a Doppler shift of roughly 5.9 kHz.

## Hardware

| Component | Role |
|---|---|
| ESP32-WROOM-32 dev board | Frequency measurement, speed calculation, display and button control |
| CDM324 24 GHz Doppler module | Transmits microwave signal and outputs the Doppler (IF) signal |
| LM358N op-amp | Amplifies and filters the weak radar signal |
| LM393 comparator | Converts the analog waveform into clean digital pulses |
| 5461AS-1 4-digit 7-segment display | Final speed readout |
| LCD1602 display | Debugging display during development |
| Tactile pushbutton | Starts and stops a measurement session |
| 1K Ω resistors, capacitors, breadboard, jumpers | Prototyping and signal conditioning |

## Roadmap

1. **Hardware prototype:** complete the breadboard build and verify each subsystem independently.
2. **Speed measurement:** measure the Doppler frequency and convert it to a reliable speed reading.
3. **Companion app:** stream readings from the ESP32 to a local application for logging and analysis.
4. **Final build:** move to a soldered board, battery power and a handheld enclosure.


## Limitations

This is an educational prototype. A low-cost Doppler module has limited range and can pick up other moving objects, so accuracy depends heavily on aiming, signal conditioning and calibration. Readings are not guaranteed to match a commercial radar gun.
