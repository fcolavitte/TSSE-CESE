/*
 * @file   : API_Json.c
 * @date   : Feb 19, 2023
 * @author : Colavitte Facundo G. <facundocolavitte@gmail.com>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/

#include "API_Json.h"
#include <stdint.h>
#include <string.h>

/********************** macros and definitions *******************************/

/********************** internal data declaration ****************************/

Json_struct_t Json_from_DB;

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/

/********************** external data definition *****************************/

/********************** internal functions definition ************************/

uint8_t get_Json_value(uint8_t *Json, uint8_t *key, uint8_t *value_return, uint8_t return_max_lenght) {
    if(Json==0||key==0||value_return==0||return_max_lenght==0){
    	return 0;
    }
    uint8_t *indexIn;										/* Inicio del value		*/
    uint8_t *indexOut;										/* Fin del value			*/
    indexIn=(uint8_t*)strstr((char*)Json, (char*)key);		/* Posicionarse al comienzo del key		*/
    if(indexIn==0){						/* Si no encontró el key, strstr() devuelve 0		*/
		printf(">>ERROR>get_Json_value()>KEY NO ENCONTRADO:%s\n",(char*)key);
    	return 0;
    }
    if(strlen((char*)indexIn)<strlen((char*)key)+3){	/* Si no posee largo suficiente para obtener valor devolver 0	*/
    	return 0;
    }
    indexIn+=strlen((char*)key)+2;		/* Se posiciona justo despues del caracter ':' que separa key de value		*/
    if(*indexIn=='"'){					/* Si después de ':' hay un '"', el value es un String y el value está entre comillas dobles*/
    	indexIn++;
        indexOut=(uint8_t*)strstr((char*)indexIn,"\"");
    } else {
        indexOut=(uint8_t*)strstr((char*)indexIn,",");	/* Si value no es un String, al final del value hay una ',' separandolo del siguiente key */
    	if(indexOut==0){ 	 	 	 	/* o hay un '}' indicando que es el fin del Json	 	 	 	 	 	 	 	 	 		 */
    		indexOut=(uint8_t*)strstr((char*)indexIn,"}");
    	}
    }
	if(indexOut==0){	/* Si no se encontro el caracter de cierre del value se devuelve 0 */
		return 0;
	}
	uint32_t value_lenght = indexOut-indexIn;
	if(value_lenght > return_max_lenght){
		return 0;
	}
	strncpy((char*)value_return,(char*)indexIn,value_lenght);
	value_return[value_lenght] = '\0';
    return 1;
}