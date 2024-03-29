#include <stdio.h>
#include <stdlib.h>
#include "common_cesar.h"

void cesar_init(cesar_t *cesar, const char *key){
	cesar->key = atoi(key);
}

void cesar_uninit(cesar_t *cesar){}

void cesar_traducir(cesar_t *cesar, char *s, unsigned int s_len, int mult){
	int i;
	for (i = 0; i < s_len; ++i) {
		s[i] = (s[i] + (cesar->key * mult)) % 256;
	}
	return;
}

void cesar_cifrar(cesar_t *cesar, char *s, unsigned int s_len){
	cesar_traducir(cesar, s, s_len, 1);
}

void cesar_descifrar(cesar_t *cesar, char *s, unsigned int s_len){
	cesar_traducir(cesar, s, s_len, -1);
}
