struct Arc4Struct;
typedef struct Arc4Struct *arc4_t;

void arc4_init(arc4_t arc4, char *key);
void arc4_del(arc4_t arc4);
void arc4_cifrar(arc4_t arc4, char *s);
void arc4_descifrar(arc4_t arc4, char *s);
