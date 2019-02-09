
Arduino IDE and Arduino builder support custom board definitions from [hardware subfolder](https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification) of your sketches folder. This definitions can use core classes and tools from installed board packages.

This GitHub repository contains my settings for boards I use for my project and to develop Arduino libraries. You can use it as starting point for your boards specialties.

![folders](my_boards.png)

All boards in this repo are only additions to installed 'official' board packages. My files contain only definition of the board in boards.txt, the folder in variants and platform.txt file contains only additional entries. I use Eclipse Arduino plugin named Sloeber for Arduino development. With Sloeber the entries from platform.txt in custom definition are merged with official platform.txt and my entries have priority. With Arduino IDE only some entries are respected.

## Boards

### AVR architecture

Boards defined here use my version of Optiboot bootloader with `copy_flash_pages` function (for ArduinoOTA library). platform.txt contains entries for sketch upload over network to ArduinoOTA library. All boards refer official Arduino AVR core and tools.

The official Arduino Mega doesn't use Optiboot bootloader. It has a 4 kB bootloader. The board definition here is changed to respect 1 kB Optiboot bootloader. The AVR package can use arduino:mega as variant reference to official package, so the variants folder doesn't need to be copied here. 

I have [a small series ATmega1284p board](https://github.com/budvar10/Arduino-ATmega1284P) by budvar10. It has perfect Uno pins compatibility. The pin mapping in variants is copied from budvar10's repo.

### SAMD architecture

platform.txt contains an entry for remote upload, that is missing in the official package.

I use a M0 board without bootloader. The official core doesn't define a SAMD board without bootloader. The variants/arduino_mzero folder is copied from the Arduino SAMD package.
