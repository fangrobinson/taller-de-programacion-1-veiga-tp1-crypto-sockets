#include <stdio.h>

void traducir(char *s, int key, int mult){
	unsigned char let;
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		let = s[i];
		let = (let + (key * mult))%256;
		s[i] = let;
	}
	return;
}

void cesar_cifrar(char *s, int key){
	traducir(s, key, 1);
}

void cesar_descifrar(char *s, int key){
	traducir(s, key, -1);
}

