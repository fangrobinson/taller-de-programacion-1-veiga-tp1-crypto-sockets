#include "common_controlador_cifradores.h"
#include "common_cesar.h"
#include "common_cesar.c"
#include "common_vigenere.h"
#include "common_vigenere.c"
#include "common_arc4.h"
#include "common_arc4.c"

struct ControladorCifradoresStruct{
	void *c;
	char *metodo;
};

#ifndef __CONTROLADOR_CIFRADOR_T__
#define __CONTROLADOR_CIFRADOR_T__
typedef struct ControladorCifradoresStruct *cifradores_t;
#endif

void controlador_cifradores_init_por_metodo(cifradores_t controlador_cifradores,
											char *metodo, char *key){
	if (strcmp(metodo, "--method=cesar") == 0){
		controlador_cifradores->c = malloc(sizeof(struct CesarStruct));
		cesar_init((cesar_t) controlador_cifradores->c, key);
	}
	if (strcmp(metodo, "--method=vigenere") == 0){
		controlador_cifradores->c = malloc(sizeof(struct VigenereStruct));
		vigenere_init((vigenere_t) controlador_cifradores->c, key);
	}
	if (strcmp(metodo, "--method=rc4") == 0){
		controlador_cifradores->c = malloc(sizeof(struct Arc4Struct));
		arc4_init((arc4_t) controlador_cifradores->c, key);
	}
}

void controlador_cifradores_uninit_por_metodo(
										cifradores_t controlador_cifradores){
	if (strcmp(controlador_cifradores->metodo, "--method=cesar") == 0){
		cesar_uninit((cesar_t) controlador_cifradores->c);
	}
	if (strcmp(controlador_cifradores->metodo, "--method=vigenere") == 0){
		vigenere_uninit((vigenere_t) controlador_cifradores->c);
	}
	if (strcmp(controlador_cifradores->metodo, "--method=rc4") == 0){
		arc4_uninit((arc4_t) controlador_cifradores->c);
	}
	free(controlador_cifradores->c);
}


void controlador_cifradores_init(cifradores_t controlador_cifradores, 
	                            char *metodo, char *key){
	controlador_cifradores->metodo = malloc(strlen(metodo) + 1);
	strcpy(controlador_cifradores->metodo, metodo);
	controlador_cifradores_init_por_metodo(controlador_cifradores, 
		                                   metodo, key + 6);
	
}

void controlador_cifradores_uninit(cifradores_t controlador_cifradores){
	controlador_cifradores_uninit_por_metodo(controlador_cifradores);
	free(controlador_cifradores->metodo);	
}

void controlador_cifradores_cifrar(cifradores_t cifradores, char *msg, unsigned int str_len){
	if (strcmp(cifradores->metodo, "--method=cesar") == 0){
		cesar_cifrar((cesar_t) cifradores->c, msg, str_len);
	}
	if (strcmp(cifradores->metodo, "--method=vigenere") == 0){
		vigenere_cifrar((vigenere_t) cifradores->c, msg, str_len);
	}
	if (strcmp(cifradores->metodo, "--method=rc4") == 0){
		arc4_cifrar((arc4_t) cifradores->c, msg, str_len);
	}
}

void controlador_cifradores_descifrar(cifradores_t cifradores, char *msg, unsigned int str_len){
	if (strcmp(cifradores->metodo, "--method=cesar") == 0){
		cesar_descifrar((cesar_t) cifradores->c, msg, str_len);
	}
	if (strcmp(cifradores->metodo, "--method=vigenere") == 0){
		vigenere_descifrar((vigenere_t) cifradores->c, msg, str_len);
	}
	if (strcmp(cifradores->metodo, "--method=rc4") == 0){
		arc4_descifrar((arc4_t) cifradores->c, msg, str_len);
	}
}
