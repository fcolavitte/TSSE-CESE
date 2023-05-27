#include "unity.h"
#include "leds.h"
#include <stdint.h>

static uint16_t puerto_virtual;

//setUp se ejecuta antes de cada prueba
void setUp(void) {
	ledsInit(&puerto_virtual);
}


void test_todos_los_leds_inician_apagados(void) {
	uint16_t puerto_virtual = 0xFFFF;
	ledsInit(&puerto_virtual);
	TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_prender_un_led(void) {
	ledsTurnOnSingle(2);
	TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual);
}

void test_prender_y_apagar_un_led(void) {
	ledsTurnOnSingle(2);
	ledsTurnOffSingle(2);
	TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_prender_y_apagar_varios_leds(void) {
	ledsTurnOnSingle(3);
	ledsTurnOnSingle(5);
	ledsTurnOffSingle(3);
	ledsTurnOffSingle(7);
	TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);
}

void test_prender_todos_los_leds(void) {
	ledsTurnOnAll();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

void test_prender_y_apagar_todos_los_leds(void) {
	ledsTurnOnAll();
	ledsTurnOffAll();
	TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_recuperar_estado_de_un_led(void) {
	bool estado = 0;
	estado = ledIsOn(1);
	TEST_ASSERT_EQUAL(0, puerto_virtual);
}

void test_prender_y_recuperar_estado_de_un_led(void) {
	bool estado = 0;
	ledsTurnOnSingle(5);
	estado = ledIsOn(5);
	TEST_ASSERT_EQUAL(1, estado);
}

void test_apagar_y_recuperar_estado_de_un_led(void) {
	bool estado = 0;
	ledsTurnOffSingle(5);
	estado = ledIsOn(5);
	TEST_ASSERT_EQUAL(0, estado);
}

void test_prender_y_recuperar_estado_de_varios_led(void) {
	bool estado = 0;
	ledsTurnOnSingle(5);
	estado = ledIsOn(5);
	TEST_ASSERT_EQUAL(1, estado);

	ledsTurnOnSingle(7);
	estado = ledIsOn(7);
	TEST_ASSERT_EQUAL(1, estado);
}