#ifndef __ARC4_H__
#define __ARC4_H__

struct Arc4Struct;
typedef struct Arc4Struct *arc4_t;

void arc4_init(arc4_t arc4, char *key);
void arc4_uninit(arc4_t arc4);
void arc4_cifrar(arc4_t arc4, char *s, unsigned int s_len);
void arc4_descifrar(arc4_t arc4, char *s, unsigned int s_len);

#endif
