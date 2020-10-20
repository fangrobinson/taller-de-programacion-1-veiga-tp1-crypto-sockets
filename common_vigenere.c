#include <stdlib.h>
#include <string.h>
#include "common_vigenere.h"

void vigenere_init(vigenere_t v, char *key){
	v->key_len = strlen(key);
	v->key = malloc(strlen(key) + 1);
	strcpy(v->key, key);
}

void vigenere_uninit(vigenere_t v){
	free(v->key);
}

void vigenere_traducir_cambio_letra(vigenere_t v, char *s, int i, int mult){
	unsigned char string_let = s[i];
	unsigned char key_let = v->key[i % v->key_len];
	string_let = (string_let + (key_let * mult))%256;
	s[i] = string_let;
}

void vigenere_traducir(vigenere_t v, char *s, unsigned int s_len, int mult){
	int i;
	for (i = 0; i < s_len; ++i) {
		vigenere_traducir_cambio_letra(v, s, i, mult);
	}
	return;
}

void vigenere_cifrar(vigenere_t v, char *s, unsigned int s_len){
	vigenere_traducir(v, s, s_len, 1);
	return;
}

void vigenere_descifrar(vigenere_t v, char *s, unsigned int s_len){
	vigenere_traducir(v, s, s_len, -1);
	return;
}
