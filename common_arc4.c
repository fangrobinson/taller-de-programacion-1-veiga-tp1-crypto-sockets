#include <stdlib.h>
#include <string.h>
#include "common_arc4.h"

void s_box_swap(unsigned char *s, unsigned int i, unsigned int j) {
    unsigned char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void arc4_set_s_box(arc4_t *arc4){
	int i, j;

	for (i = 0; i < 256; i++)
		arc4->s_box[i] = i;

	for (i = j = 0; i < 256; i++) {
		j = (j + arc4->key[i % arc4->key_lenght] + arc4->s_box[i]) & 255;
		s_box_swap(arc4->s_box, i, j);
	}

	arc4->i = arc4->j = 0;
}

void arc4_init(arc4_t *arc4, char *key){
	arc4->key = malloc(strlen(key) + 1);
	strcpy(arc4->key, key);
	
	arc4->key_lenght = strlen(key);
	
	arc4_set_s_box(arc4);
}

void arc4_uninit(arc4_t *arc4){
	free(arc4->key);
}

unsigned char arc4_output(arc4_t *arc4) {
    arc4->i = (arc4->i + 1) & 255;
    arc4->j = (arc4->j + arc4->s_box[arc4->i] ) & 255;

    s_box_swap(arc4->s_box, arc4->i, arc4->j);

    return arc4->s_box[(arc4->s_box[arc4->i] + arc4->s_box[arc4->j]) & 255];
}

void arc4_traducir(arc4_t *arc4, char *s, unsigned int s_len) {
	int i;
	for (i = 0; i < s_len; ++i) {
		s[i] = (char)(s[i] ^ arc4_output(arc4));
	}
}

void arc4_cifrar(arc4_t *arc4, char *s, unsigned int s_len){
	arc4_traducir(arc4, s, s_len);
}

void arc4_descifrar(arc4_t *arc4, char *s, unsigned int s_len){
	arc4_set_s_box(arc4);
	arc4_traducir(arc4, s, s_len);
}
