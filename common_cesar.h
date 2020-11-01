#ifndef __CESAR_H__
#define __CESAR_H__

typedef struct CesarStruct{
	int key;
} cesar_t;

void cesar_init(cesar_t *cesar, const char *key);
void cesar_uninit(cesar_t *cesar);
// cifra los contenidos del buffer s de largo s_len de acuerdo a cesar
// el cifrado se realiza inplace
void cesar_cifrar(cesar_t *cesar, char *s, unsigned int s_len);
// descifra los contenidos del buffer s de largo s_len de acuerdo a cesar
// el descifrado se realiza inplace
void cesar_descifrar(cesar_t *cesar, char *s, unsigned int s_len);

#endif
