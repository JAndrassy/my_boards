/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

const uint32_t g_ADigitalPinMap[PINS_COUNT] = {
  7, // RX
  8, // TX
  9, // D2, W5500 interrupt
  10,
  11,
  12,
  13,
  17,
  18,
  23,
  24,
  25, // D11, SPI MOSI
  28, // D12, SPI MISO
  29, // D13, SPI SCK
  1,  // A0
  2,
  3,
  4,
  5,  // A4, I2C SDA
  6,  // A5, I2C SCL
  30  // A6, LED_PIN
};
