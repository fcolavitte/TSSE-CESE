#include "src/API_Json.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
void test_un_parametro_de_entrada_es_cero(void) {

    uint8_t* Json;

    uint8_t* key;

    uint8_t* value;

    uint8_t return_max_lenght = 10;



    uint8_t retvalue = 1;

    retvalue = get_Json_value(0, key, value, return_max_lenght);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((retvalue)), (

((void *)0)

), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX8);

}



void test_cualquier_parametro_de_entrada_es_cero(void) {

    uint8_t* Json;

    uint8_t* key;

    uint8_t* value;

    uint8_t return_max_lenght = 10;



    uint8_t retvalue = 1;

    retvalue = get_Json_value(0, key, value, return_max_lenght);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((retvalue)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX8);



    retvalue = 1;

    retvalue = get_Json_value(Json, 0, value, return_max_lenght);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((retvalue)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX8);



    retvalue = 1;

    retvalue = get_Json_value(Json, key, 0, return_max_lenght);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((retvalue)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX8);



    retvalue = 1;

    retvalue = get_Json_value(Json, key, value, 0);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((retvalue)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX8);

}
