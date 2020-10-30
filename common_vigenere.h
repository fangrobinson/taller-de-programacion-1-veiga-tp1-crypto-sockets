#ifndef __VIGENERE_H__
#define __VIGENERE_H__

typedef struct VigenereStruct{
	char *key;
	size_t key_len;
} vigenere_t;

void vigenere_init(vigenere_t *v, char *key);
void vigenere_uninit(vigenere_t *v);
void vigenere_cifrar(vigenere_t *v, char *s, unsigned int s_len);
void vigenere_descifrar(vigenere_t *v, char *s, unsigned int s_len);

#endif
