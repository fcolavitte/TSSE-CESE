#include <stdint.h>
#include <stdbool.h>

void ledsInit(uint16_t * direccion);

void ledsTurnOnSingle(uint8_t led);

void ledsTurnOffSingle(uint8_t led);

void ledsTurnOnAll();

void ledsTurnOffAll();

bool ledIsOn(uint8_t led);