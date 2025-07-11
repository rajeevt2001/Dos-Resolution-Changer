# DOS Resolution Changer

A simple DOS utility to switch between common **text** and **graphics** video modes. Written in Turbo C, with the help of Blackbox AI and Chat GPT, using BIOS interrupts (`INT 10h`).

## Table of Contents

- [About](#about)
- [Features](#features)
- [Tested-On](#Tested-On)
- [Screenshots](#screenshots)
- [Controls](#getting-started)
- [Supported Modes](#supported-Modes)
- [How to Compile](#how-to-Compile)
- [Notes](#notes)
- [License](#license)
---

## Features

- Text mode and graphics mode selection
- Categorized modes
- Clean text-based UI with menu switching
- Key controls: `T`, `G`, `Q`
- Written in C for real DOS / DOSBox systems

---

## Tested On
Dos ver 7.1 in DOSBox-X version 2023.05.01 (Will test on real machine later).
Complied on Borland Turbo C (Dos)

## Screenshots
![Preview Image](Screenshots/Screenshot%201.png)

Graphics Mode Page

![Preview Image](Screenshots/Screenshot%202.png)

Text Mode Page

![Preview Image](Screenshots/Screenshot%203.png)

Mode 0x00 (First Text Mode 40x25) Applied

![Preview Image](Screenshots/Screenshot%204.png)

Mode 0x04 (First Graphics Mode 40x25) Applied


## 🎮 Controls

| Key | Action                          |
|-----|---------------------------------|
| 1–9 | Select corresponding mode       |
| T   | Show Text Modes menu            |
| G   | Show Graphics Modes menu        |
| Q   | Quit the program                |

---

## Supported Modes

### Graphics Modes
- Mode 0x04: 320x200, 4 colors (CGA)
- Mode 0x06: 640x200, 2 colors (CGA)
- Mode 0x10: 640x350, 16 colors (EGA)
- Mode 0x13: 320x200, 256 colors (VGA)
- Mode 0x12: 640x480, 16 colors (VGA)
- Mode 0x07: 720x400, mono text (VGA)
- Mode 0x102: 800x600, 16 colors (SVGA)
- Mode 0x105: 1024x768, 16 colors (SVGA)
- Mode 0x107: 1280x1024, 16 colors (SVGA)

### Text Modes
- Mode 0x00: 40x25, 16 colors
- Mode 0x01: 40x25, alt 16 colors
- Mode 0x02: 80x25, 16 colors
- Mode 0x03: 80x25, 16 colors (default)
- Mode 0x07: 80x25, monochrome
- Mode 0x0F: 80x25, mono VGA (720x400)

---

## How to Compile

### Using Turbo C (DOS or DOSBox):
1. Open Turbo C IDE
2. Load the `.cpp` source file
3. Go to `Compile → Compile` (Alt + F9)
4. Then `Compile → Link → Run` (Ctrl + F9)

## Notes
The Modes:
 0x102: 800x600 16 colors (SVGA),
 0x105: 1024x768 16 colors (SVGA),
 0x107: 1280x1024 16 colors (SVGA),
It does not apply when I test it in DOSBox; you have to test it on your actual hardware.

Perhaps some bugs are also present, so it's not perfect yet.

## License
This project is open source and available under the MIT License.
