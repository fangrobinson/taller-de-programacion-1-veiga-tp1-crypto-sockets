#include <stdlib.h>
#include <string.h>
#include "common_vigenere.h"

struct VigenereStruct{
	char *key;
	size_t key_len;
};

void vigenere_init(vigenere_t v, char *key){
	v->key_len = strlen(key);
	v->key = key;
	/*
	v->key = malloc(strlen(key) + 1);
	if (!v->key) {
		free(v);
		return NULL;
	}
	strcpy(v->key, key);
	return v;
	*/
}

void del_vigenere(vigenere_t v){
	/*
	free(v->key);
	free(v);
	*/
}

void vigenere_traducir_cambio_letra(vigenere_t v, char *s, int i,int mult){
	unsigned char string_let = s[i];
	unsigned char key_let = v->key[i%v->key_len];
	string_let = (string_let + (key_let * mult))%256;
	s[i] = string_let;
}

void vigenere_traducir(vigenere_t v, char *s, int mult){
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		vigenere_traducir_cambio_letra(v, s, i, mult);
	}
	return;
}

void vigenere_cifrar(vigenere_t v, char *s){
	vigenere_traducir(v, s, 1);
	return;
}

void vigenere_descifrar(vigenere_t v, char *s){
	vigenere_traducir(v, s, -1);
	return;
}
