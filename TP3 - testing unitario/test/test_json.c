/**
 * El presente programa utiliza ceedling y es un test de una función desarrollada para el
 * proyecto final de carrera de CESE18. El test se desarrolla en el ámbito de la materia TSSE.
 * 
 * Código a testear:
 *              El código a testear es un componente del archivo original API_Json.c.
 *              La función a testear es uint8_t get_Json_value(<...>);.
 *              La función busca el "value" de un "key" de un JSON en formato String.
 *              Ejemplo tipico a recibir:
 *                      {"Enviar":"Mensaje de prueba","Horario":"10-00","Periodo":30,"Ventana":10}
 * 
 *  Requisitos:
 *          - La función debe solicitar un largo máximo a analizar, para evitar
 *            errores de omisión de '\0' en el array de chars.
 *          - La función debe buscar el "key" y devolver el "value" en una dirección dada.
 *          - La función debe poder encontrar values del tipo int y String (con y sin 0x22(ASCII:"))
 *          - La función debe devolver 0 si algún parametro de entrada es 0.
 *          - Si no se pudo obtener el "value" la función debe devuelver 0.
 *          - Si se pudo obtener el "value" la función debe devolver 1.
 *          - La función debe recibir de parámetro el "key", una dirección donde guardar el "value",
 *            el String del JSON y el largo máximo a analizar.
 *          - La función solo busca un key-value a la vez.
 * 
 *  Tests:
 *          - Revisar que la función devuelva 0 si uno de los parámetros de entrada es 0.
 *          - Revisar que la función devuelva 0 si cualquiera de los parámetros de entrada es 0.
 *          - Revisar que devuelva 0 al buscar un key que no figura en el JSON
 *          - Buscar un "Value" del tipo entero en un JSON de un único key-value
 *          - Buscar un "Value" del tipo String en un JSON de un único key-value
 *          - Buscar un "Value" del tipo entero en un JSON de dos key-value con el valor buscado al comienzo
 *          - Buscar un "Value" del tipo String en un JSON de dos key-value con el valor buscado al comienzo
 *          - Buscar un "Value" del tipo entero en un JSON de dos key-value con el valor buscado al final
 *          - Buscar un "Value" del tipo String en un JSON de dos key-value con el valor buscado al final
 *          - Verificar que devuelva 0 si el largo máximo a analizar no alcanza para encontrarlo pero sí está en el JSON
 * 
 * @file   : test_json.c
 * @date   : Feb 20, 2023
 * @author : Colavitte Facundo G. <facundocolavitte@gmail.com>
 * @version	v1.0.0
*/

#include "unity.h"
#include "API_Json.h"
#include <stdint.h>

#define compilar_test_de_prueba 0


#if compilar_test_de_prueba == 1
void test_siempre_falla(void) {
    TEST_FAIL_MESSAGE("Iniciando...");
}
#endif


void test_un_parametro_de_entrada_es_cero(void) {
    uint8_t* Json;
    uint8_t* key;
    uint8_t* value;
    uint8_t return_max_lenght = 10;

    uint8_t retvalue = 1;
    retvalue = get_Json_value(0, key, value, return_max_lenght);
	TEST_ASSERT_EQUAL_HEX8(0, retvalue);
}

void test_cualquier_parametro_de_entrada_es_cero(void) {
    uint8_t* Json;
    uint8_t* key;
    uint8_t* value;
    uint8_t return_max_lenght = 10;

    uint8_t retvalue = 1;
    retvalue = get_Json_value(0, key, value, return_max_lenght);
	TEST_ASSERT_EQUAL_HEX8(0, retvalue);

    retvalue = 1;
    retvalue = get_Json_value(Json, 0, value, return_max_lenght);
	TEST_ASSERT_EQUAL_HEX8(0, retvalue);

    retvalue = 1;
    retvalue = get_Json_value(Json, key, 0, return_max_lenght);
	TEST_ASSERT_EQUAL_HEX8(0, retvalue);

    retvalue = 1;
    retvalue = get_Json_value(Json, key, value, 0);
	TEST_ASSERT_EQUAL_HEX8(0, retvalue);
}
