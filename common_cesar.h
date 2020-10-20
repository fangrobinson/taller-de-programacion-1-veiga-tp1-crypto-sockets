#ifndef __CESAR_H__
#define __CESAR_H__

struct CesarStruct;

#ifndef __CESAR_T__
#define __CESAR_T__
typedef struct CesarStruct *cesar_t;
#endif

void cesar_init(cesar_t cesar, char *key);
void cesar_uninit(cesar_t cesar);
void cesar_cifrar(cesar_t cesar, char *s, unsigned int s_len);
void cesar_descifrar(cesar_t cesar, char *s, unsigned int s_len);

#endif
