#include <stdio.h>
#include <stdlib.h>

struct CesarStruct{
	int key;
};

void cesar_init(cesar_t cesar, char *key){
	cesar->key = atoi(key);
}

void cesar_traducir(cesar_t cesar, char *s, int mult){
	unsigned char let;
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		let = s[i];
		let = (let + (cesar->key * mult))%256;
		s[i] = let;
	}
	return;
}

void cesar_cifrar(cesar_t cesar, char *s){
	cesar_traducir(cesar, s, 1);
}

void cesar_descifrar(cesar_t cesar, char *s){
	cesar_traducir(cesar, s, -1);
}
