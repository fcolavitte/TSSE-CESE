#include "leds.h"
#include <stdint.h>
#include <stdbool.h>

#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF

static uint16_t * puerto_virtual;

void ledsInit(uint16_t * direccion) {
    puerto_virtual = direccion;
    *direccion = ALL_LEDS_OFF;
}

void ledsTurnOnSingle(uint8_t led) {
    *puerto_virtual |= (FIRST_BIT<<(led-INDEX_OFFSET));
}

void ledsTurnOffSingle(uint8_t led) {
    *puerto_virtual &= ~(FIRST_BIT<<(led-INDEX_OFFSET));
}

void ledsTurnOnAll() {
    *puerto_virtual = ALL_LEDS_ON;
}

void ledsTurnOffAll() {
    *puerto_virtual = ALL_LEDS_OFF;
}

bool ledIsOn(uint8_t led) {
    uint16_t bit_case = 0;
    bit_case = (*puerto_virtual) &(FIRST_BIT<<(led-INDEX_OFFSET));
    if(bit_case > 0) {
        return 1;
    }
    return 0;
}