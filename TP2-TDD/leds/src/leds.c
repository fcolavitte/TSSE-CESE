#include "leds.h"
#include <stdint.h>
#include <stdbool.h>

#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF

uint16_t bitLedPosition(uint8_t led);

static uint16_t * puerto_virtual;

void ledsInit(uint16_t * direccion) {
    puerto_virtual = direccion;
    ledsTurnOffAll();
}

void ledsTurnOnSingle(uint8_t led) {
    *puerto_virtual |= bitLedPosition(led);
}

void ledsTurnOffSingle(uint8_t led) {
    *puerto_virtual &= ~bitLedPosition(led);
}

void ledsTurnOnAll() {
    *puerto_virtual = ALL_LEDS_ON;
}

void ledsTurnOffAll() {
    *puerto_virtual = ALL_LEDS_OFF;
}

bool ledIsOn(uint8_t led) {
    return (*puerto_virtual) & bitLedPosition(led);
}

uint16_t bitLedPosition(uint8_t led) {
    uint16_t retvalue = 0;
    retvalue = FIRST_BIT<<(led-INDEX_OFFSET);
    return retvalue;
}