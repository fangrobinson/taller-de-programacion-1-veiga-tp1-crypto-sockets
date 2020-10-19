#include <stdlib.h>
#include <string.h>
#include "common_arc4.h"

struct Arc4Struct{
	unsigned char s_box[256];
	unsigned int i, j;
	char *key;
	unsigned int key_lenght;
};

void s_box_swap(unsigned char *s, unsigned int i, unsigned int j) {
    unsigned char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    /*
	unsigned char temp = arc4->s_box[i]
	arc4->s_box[i] = arc4->s_box[j]
	arc4->s_box[j] temp
    */
}

void arc4_init(arc4_t arc4, char *key){
	/*
	arc4_t arc4 = malloc(sizeof(struct Arc4Struct));
	if (arc4 == NULL) return NULL;
	*/
	arc4->key = key;
	arc4->key_lenght = strlen(key);
	int i, j;

	for (i = 0; i < 256; i++)
		arc4->s_box[i] = i;

	for (i = j = 0; i < 256; i++) {
		j = (j + key[i % arc4->key_lenght] + arc4->s_box[i]) & 255;
		s_box_swap(arc4->s_box, i, j);
	}

	arc4->i = arc4->j = 0;
}

void arc4_del(arc4_t arc4){
	free(arc4);
}

unsigned char arc4_output(arc4_t arc4) {
    arc4->i = (arc4->i + 1) & 255;
    arc4->j = (arc4->j + arc4->s_box[arc4->i] ) & 255;

    s_box_swap(arc4->s_box, arc4->i, arc4->j);

    return arc4->s_box[(arc4->s_box[arc4->i] + arc4->s_box[arc4->j]) & 255];
}

void arc4_traducir(arc4_t arc4, char *s) {
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		s[i] = s[i] ^ arc4_output(arc4);
	}
}

void arc4_cifrar(arc4_t arc4, char *s){
	arc4_traducir(arc4, s);
}

void arc4_descifrar(arc4_t arc4, char *s){
	arc4_init(arc4, arc4->key);
	arc4_traducir(arc4, s);
}
