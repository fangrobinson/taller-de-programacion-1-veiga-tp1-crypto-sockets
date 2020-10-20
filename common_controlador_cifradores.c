#include "common_controlador_cifradores.h"
#include "common_cesar.h"
#include "common_cesar.c"
#include "common_vigenere.h"
#include "common_vigenere.c"
#include "common_arc4.h"
#include "common_arc4.c"

struct Cifrador {
	const char *name;
	void (* func)(void *c, char *s, unsigned int s_len);
};

void wrapper_cesar_cifrar(void *c, char *s, unsigned int s_len){
	cesar_cifrar((cesar_t) c, s, s_len);
}

void wrapper_vigenere_cifrar(void *c, char *s, unsigned int s_len){
	vigenere_cifrar((vigenere_t) c, s, s_len);
}

void wrapper_arc4_cifrar(void *c, char *s, unsigned int s_len){
	arc4_cifrar((arc4_t) c, s, s_len);
}


struct CifradoresStruct{
	struct Cifrador *cifradores;
	size_t cantidad_cifradores;
	char *metodo;
	void *c;
};

void controlador_cifradores_init_por_metodo(cifradores_t controlador_cifradores, char *metodo, char *key){
	/*
	for (int i  = 0; i < 3; i++){
		if (strcmp(metodo, cifradores[i].name) == 0){
			cifradores[i].func(mensaje, key, strlen(key));
		}
	}*/
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

void controlador_cifradores_uninit_por_metodo(cifradores_t controlador_cifradores, char *metodo){
	/*
	for (int i  = 0; i < 3; i++){
		if (strcmp(metodo, cifradores[i].name) == 0){
			cifradores[i].func(mensaje, key, strlen(key));
		}
	}*/
	controlador_cifradores->metodo = malloc(sizeof(strlen(metodo)));
	controlador_cifradores->metodo = strcopy(metodo);
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


void controlador_cifradores_init(cifradores_t controlador_cifradores, char *metodo, char *key){
	/*
	struct Cifrador *cifradores  = {
		{"--method=cesar", wrapper_cesar_cifrar},
		{"--method=vigenere", wrapper_vigenere_cifrar},
		{"--method=rc4", wrapper_arc4_cifrar},	
	};
	controlador_cifradores->cifradores = cifradores;
	*/
	controlador_cifradores->c = controlador_cifradores_init_por_metodo(metodo);
}

/*
void cifradores_cifrar_mensaje(char *metodo, char *mensaje, char *key){
	for (int i  = 0; i < 3; i++){
		if (strcmp(metodo, cifradores[i].name) == 0){
			cifradores[i].func(mensaje, key, strlen(key));
		}
	}
}
*/
