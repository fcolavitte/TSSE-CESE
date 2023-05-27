/*
 * @file   : API_Json.h
 * @date   : Mar 02, 2023
 * @author : Colavitte Facundo G. <facundocolavitte@gmail.com>
 * @version	v1.0.0
 */

#ifndef MAIN_DRIVERS_LIB_API_JSON_H_
#define MAIN_DRIVERS_LIB_API_JSON_H_

/********************** inclusions *******************************************/

#include <stdint.h>

/********************** macros and definitions *******************************/

#define KEY_STRING_MAX_LENGHT 	(uint32_t)8 		/*sizeof de "Mensaje" incluyendo el '\0'			*/
#define KEY_UINT_MAX_LENGHT 	(uint32_t)18 		/*sizeof de "Pasar_a_modo_WiFi" incluyendo el '\0'	*/
#define INT_IN_STRING_SIZE		(uint8_t)20			/*Tamaño máximo del string para pasar a entero		*/
#define CANT_ELEMENTOS_DE_JSON_STRUCT_T		(uint32_t)5
#define VALUE_STRING_MAX_LENGHT (uint8_t)30

/********************** typedef **********************************************/

typedef struct{
	uint8_t *key;//key[KEY_STRING_MAX_LENGHT];
	uint8_t value[VALUE_STRING_MAX_LENGHT];
} Json_String_element_t;

typedef struct{
	uint8_t *key;//key[KEY_UINT_MAX_LENGHT];
	uint32_t value;
} Json_uint_element_t;

typedef struct{
	struct {
		Json_String_element_t Mensaje;
		Json_String_element_t Time_inicio_programado;
		Json_uint_element_t   Periodo_seconds;
		Json_uint_element_t   Ventana_minutes;
		Json_uint_element_t   Pass_to_WiFi;
	};
} Json_struct_t;

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/**
 * @brief  Devuelve el valor del key solicitado del Json. En caso de no encontrarse devuelve 0. Si se encontró el valor devuelve 1.
 * @param  Puntero al String del Json
 * @param  Puntero al String del key a buscar
 * @param  Puntero a la posición de memoria en donde se guardará el valor encontrado
 * @param  Largo máximo del String del valor a devolver, por defecto 30.
 * @return Devuelve 1 si encontró el key y pudo obtener valor, 0 si no encontró el key o no se pudo obtener el valor
 *
 * @Note  Ejemplo de Json: {"Enviar":"Mensaje de prueba","Horario":"10-00","Periodo":30,"Ventana":10}
 */
uint8_t get_Json_value(uint8_t *Json, uint8_t *key, uint8_t *value_return, uint8_t return_max_lenght);

#endif /* MAIN_DRIVERS_LIB_API_JSON_H_ */

/********************** end of file ******************************************/