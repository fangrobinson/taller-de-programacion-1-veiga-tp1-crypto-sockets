#include <stdio.h>
#include <stdlib.h>
#include "common_cesar.h"

/*
struct CesarStruct{
	int key;
};
*/
#ifndef __CESAR_T__
#define __CESAR_T__
typedef struct CesarStruct *cesar_t;
#endif

void cesar_init(cesar_t cesar, char *key){
	cesar->key = atoi(key);
}

void cesar_uninit(cesar_t cesar){}

void cesar_traducir(cesar_t cesar, char *s, unsigned int s_len, int mult){
	unsigned char let;
	int i;
	for (i = 0; i < s_len; ++i) {
		let = s[i];
		let = (let + (cesar->key * mult))%256;
		s[i] = let;
	}
	return;
}

void cesar_cifrar(cesar_t cesar, char *s, unsigned int s_len){
	cesar_traducir(cesar, s, s_len, 1);
}

void cesar_descifrar(cesar_t cesar, char *s, unsigned int s_len){
	cesar_traducir(cesar, s, s_len, -1);
}
