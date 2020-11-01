#ifndef __VIGENERE_H__
#define __VIGENERE_H__

typedef struct VigenereStruct{
	const char *key;
	size_t key_len;
	unsigned int current_pos;
} vigenere_t;

void vigenere_init(vigenere_t *v, const char *key);
void vigenere_uninit(vigenere_t *v);
// cifra los contenidos del buffer s de largo s_len de acuerdo a vigenere
// el cifrado se realiza inplace
void vigenere_cifrar(vigenere_t *v, char *s, unsigned int s_len);
// descifra los contenidos del buffer s de largo s_len de acuerdo a vigenere
// el descifrado se realiza inplace
void vigenere_descifrar(vigenere_t *v, char *s, unsigned int s_len);

#endif
