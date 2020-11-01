#ifndef __ARC4_H__
#define __ARC4_H__

typedef struct Arc4Struct{
	unsigned char s_box[256];
	unsigned int i, j;
	const char *key;
	unsigned int key_lenght;
} arc4_t;

void arc4_init(arc4_t *arc4, const char *key);
void arc4_uninit(arc4_t *arc4);

// cifra los contenidos del buffer s de largo s_len de acuerdo a arc4
// el cifrado se realiza inplace
void arc4_cifrar(arc4_t *arc4, char *s, unsigned int s_len);

// descifra los contenidos del buffer s de largo s_len de acuerdo a arc4
// el descifrado se realiza inplace
void arc4_descifrar(arc4_t *arc4, char *s, unsigned int s_len);

#endif
