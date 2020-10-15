#include <stdlib.h>
#include <string.h>
#include "common_vigenere.h"

struct VigenereStruct{
	char *key;
	size_t key_len;
};

vigenere_t crear_vigenere(char *key){
	vigenere_t v = malloc(sizeof(vigenere_t));
	if (v == NULL) return v;
	v->key_len = strlen(key);
	v->key = malloc(strlen(key) + 1);
	strcpy(v->key, key);
	return v;
}

void del_vigenere(vigenere_t v){
	free(v->key);
	free(v);
}

void vigenere_traducir(vigenere_t v, char *s, int mult){
	unsigned char let;
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		let = s[i];
		let = (let + (2 * mult))%256;
		s[i] = let;
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
