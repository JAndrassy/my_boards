
Arduino IDE and Arduino builder support custom board definitions from [hardware subfolder](https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification) of your sketches folder. This definitions can use core classes and tools from installed board packages.

This GitHub repository contains my settings for boards I use for my project and to develop Arduino libraries. You can use it as starting point for your boards specialties.

![folders](my_boards.png)

All boards in this repo are only additions to installed 'official' board packages. My files contain only definition of the board in boards.txt, the folder in variants and platform.txt file contains only additional entries. I use Eclipse Arduino plugin named Sloeber for Arduino development. With Sloeber the entries from platform.txt in custom definition are merged with official platform.txt and my entries have priority. With Arduino IDE only some entries are respected.

## Boards

### AVR architecture

Boards defined here use build of [Optiboot bootloader with `copy_flash_pages` function](https://github.com/Optiboot/optiboot/pull/269) (for ArduinoOTA library). platform.txt contains entries for sketch upload over network to ArduinoOTA library. All boards refer official Arduino AVR core and tools.

The official Arduino Mega doesn't use Optiboot bootloader. It has a 4 kB bootloader. The board definition here is changed to respect 1 kB Optiboot bootloader. The AVR package can use arduino:mega as variant reference to official package, so the variants folder doesn't need to be copied here. 

I have [a small series ATmega1284p board](https://github.com/budvar10/Arduino-ATmega1284P) by budvar10. It has perfect Uno pins compatibility. The pin mapping in variants is copied from budvar10's repo.

### SAMD architecture

platform.txt contains an entry for remote upload, that is missing in the official package.

I use a M0 board without bootloader. The official core doesn't define a SAMD board without bootloader. The variants/arduino_mzero folder is copied from the Arduino SAMD package.

### esp8266

For this to work you must replace in installed official platform.txt `{runtime.platform.path}` to `{build.core.path}/../../`. (Only until next version of the esp8266 package.) 

platform.txt here contains entries required by the SPIFFS upload plugin. It searches for esptool command name only in selected board's folder.

The esp8266 has too many Tools menu options and Sloeber doesn't remember them if hardware package is changed and takes some seconds to process the large boards.txt file of the esp8266 package every time I open project settings. So a smaller boards.txt with fixed settings I had always selected is convenient. 

I have a Wemos D1 R2 wit 4MB flash and Wemos D1 mini clone with 1 MB flash. The official package contains only options for 4 MB flash so I copied the 1 MB flash options from the Generic section.

I have a Grove UART WiFi module a simple module with Rx, TX pins only. Now it has a name in my boards menu. 
