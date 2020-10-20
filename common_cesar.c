#include <stdio.h>
#include <stdlib.h>

struct CesarStruct{
	int key;
};

void cesar_init(cesar_t cesar, char *key){
	cesar->key = atoi(key);
}

void cesar_uninit(cesar_t cesar){}

void cesar_traducir(cesar_t cesar, char *s, unsigned int s_len, int mult){
	unsigned char let;
	int i;
	for(i = 0; i < s_len; ++i){
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
