#ifndef __CESAR_H__
#define __CESAR_H__

struct CesarStruct;
typedef struct CesarStruct *cesar_t;

void cesar_init(cesar_t cesar, char *key);
void cesar_uninit(cesar_t cesar);
void cesar_cifrar(cesar_t cesar, char *s, unsigned int s_len);
void cesar_descifrar(cesar_t cesar, char *s, unsigned int s_len);

#endif
