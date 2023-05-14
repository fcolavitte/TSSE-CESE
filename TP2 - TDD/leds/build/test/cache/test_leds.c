#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static uint16_t puerto_virtual;





void setUp(void) {

 ledsInit(&puerto_virtual);

}





void test_todos_los_leds_inician_apagados(void) {

 uint16_t puerto_virtual = 0xFFFF;

 ledsInit(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_un_led(void) {

 ledsTurnOnSingle(2);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_y_apagar_un_led(void) {

 ledsTurnOnSingle(2);

 ledsTurnOffSingle(2);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_y_apagar_varios_leds(void) {

 ledsTurnOnSingle(3);

 ledsTurnOnSingle(5);

 ledsTurnOffSingle(3);

 ledsTurnOffSingle(7);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_todos_los_leds(void) {

 ledsTurnOnAll();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_y_apagar_todos_los_leds(void) {

 ledsTurnOnAll();

 ledsTurnOffAll();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX16);

}



void test_recuperar_estado_de_un_led(void) {

 

_Bool 

     estado = 0;

 estado = ledIsOn(1);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}



void test_prender_y_recuperar_estado_de_un_led(void) {

 

_Bool 

     estado = 0;

 ledsTurnOnSingle(5);

 estado = ledIsOn(5);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((estado)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}



void test_apagar_y_recuperar_estado_de_un_led(void) {

 

_Bool 

     estado = 0;

 ledsTurnOffSingle(5);

 estado = ledIsOn(5);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((estado)), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

}



void test_prender_y_recuperar_estado_de_varios_led(void) {

 

_Bool 

     estado = 0;



 ledsTurnOnSingle(5);

 estado = ledIsOn(5);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((estado)), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);



 ledsTurnOnSingle(7);

 estado = ledIsOn(7);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((estado)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);



 ledsTurnOffSingle(7);

 estado = ledIsOn(7);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((estado)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

}
