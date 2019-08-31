/****************************************************************************************
 *               *** Arduino pin definition functions for ATmega1284p ***               *
 *                               Copyright (c) 2015  badio                              *
 *                                  All Rights Reserved                                 *
 ****************************************************************************************
 ---- b a d i o  C++ ----

    File name: pins_arduino.h

 +--------------------------------------------------------------------------------------+
 | This library is free software; you can redistribute it and/or modify it the terms of |
 | the GNU Lesser General Public License as published by the Free Software Foundation;  |
 | either version 2.1 of the License, or (at your option) any later version.            |
 |                                                                                      |
 | This library is distributed in the hope that it will be useful, but WITHOUT ANY      |
 | WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR        |
 | A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.    |
 |                                                                                      |
 | You should have received a copy of the GNU Lesser General Public License along with  |
 | this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St,   |
 | Fifth Floor, Boston, MA  02110-1301  USA                                             |
 +--------------------------------------------------------------------------------------+

 */

#ifndef Pins_Arduino_h          // test for header application during compilation
    #define Pins_Arduino_h      // header identification 

// --------------------------------------------------------------------------------------

#include <avr/pgmspace.h>       // AVR Program Space Utilities

#define PROBADIO


// On the Arduino board, digital pins are also used for the analog output (software PWM).
// Analog input pins are a separate set.

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define EXTERNAL_NUM_INTERRUPTS     3
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)

#if defined(__AVR_ATmega1284P__)
    #define digitalPinHasPWM(p)     (((p) >=  4 && (p) <=  7) || \
                                     ((p) >=  9 && (p) <= 11) || \
                                     ((p) >= 12 && (p) <= 13))
#endif

static const uint8_t SS           = 10;
static const uint8_t MOSI         = 11;
static const uint8_t MISO         = 12;
static const uint8_t SCK          = 13;

static const uint8_t SDA          = 15;
static const uint8_t SCL          = 14;
static const uint8_t LED_BUILTIN  = 13;

static const uint8_t A0           = 24;
static const uint8_t A1           = 25;
static const uint8_t A2           = 26;
static const uint8_t A3           = 27;
static const uint8_t A4           = 28;
static const uint8_t A5           = 29;
static const uint8_t A6           = 30;
static const uint8_t A7           = 31;


// External Interrupts ~ Pin Change Interrupt Control Register

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR)        \
                                                                      : ((uint8_t *)0))


#define digitalPinToPCICRbit(p) (((p) <= 7)                                             \
                                        ? 3                                             \
                                        : (((p) <= 13)                                  \
                                                ? 1                                     \
                                                : (((p) <= 21)                          \
                                                        ? 2                             \
                                                        : (((p) <= 23) ? 1 : 0))))

#define digitalPinToPCMSK(p)    (((p) <= 7)                                             \
                                        ? (&PCMSK3)                                     \
                                        : (((p) <= 13)                                  \
                                                ? (&PCMSK1)                             \
                                                : (((p) <= 21)                          \
                                                        ? (&PCMSK2)                     \
                                                        : (((p) <= 23)                  \
                                                                ? (&PCMSK1)             \
                                                                : (((p) <= 31)          \
                                                                        ? (&PCMSK0)     \
                                                                        : ((uint8_t *)0))))))


#define digitalPinToPCMSKbit(p) (((p) <= 7)                                             \
                                        ? (p)                                           \
                                        : (((p) <= 13)                                  \
                                                ? ((p) - 6)                             \
                                                : (((p) <= 21)                          \
                                                        ? ((p) - 14)                    \
                                                        : (((p) <= 23)                  \
                                                                ? ((p) - 22)            \
                                                                : ((p) - 24)))))

#define digitalPinToInterrupt(p) ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 8 ? 2 : NOT_AN_INTERRUPT)))

#ifdef ARDUINO_MAIN

/* These arrays map port names (e.g. port B) to the appropriate addresses for various
   functions (e.g. reading and writing).
 */
    const uint16_t PROGMEM port_to_mode_PGM[] =
    {
        NOT_A_PORT,
        (uint16_t) &DDRA,
        (uint16_t) &DDRB,
        (uint16_t) &DDRC,
        (uint16_t) &DDRD
    };

    const uint16_t PROGMEM port_to_output_PGM[] =
    {
        NOT_A_PORT,
        (uint16_t) &PORTA,
        (uint16_t) &PORTB,
        (uint16_t) &PORTC,
        (uint16_t) &PORTD
    };

    const uint16_t PROGMEM port_to_input_PGM[] =
    {
        NOT_A_PORT,
        (uint16_t) &PINA,
        (uint16_t) &PINB,
        (uint16_t) &PINC,
        (uint16_t) &PIND
    };

    const uint8_t PROGMEM digital_pin_to_port_PGM[] =
    {
        PD, /* 0 */
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PB, /* 8 */
        PB,
        PB,
        PB,
        PB,
        PB,
        PC, /* 14 */
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PB, /* 22 */
        PB,
        PA, /* 24 */
        PA,
        PA,
        PA,
        PA,
        PA,
        PA,
        PA
    };

    const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
    {
        _BV(0), /* 0 - port D */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(2), /* 8 - port B */
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 14 - port C */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 22 - port B */
        _BV(1),
        _BV(0), /* 24 - port A */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7)
    };

    const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
    {
        NOT_ON_TIMER, /* 0 - port D */
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        TIMER1B,
        TIMER1A,
        TIMER2B,
        TIMER2A,
        NOT_ON_TIMER, /* 8 - port B */
        TIMER0A,
        TIMER0B,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        TIMER3A,
        TIMER3B,
        NOT_ON_TIMER, /* 14 - port C */
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER, /* 22 - port B */
        NOT_ON_TIMER,
        NOT_ON_TIMER, /* 24 - port A */
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER,
        NOT_ON_TIMER
    };

#endif                          // ARDUINO_MAIN

// --------------------------------------------------------------------------------------

#endif                          // Pins_Arduino_h

