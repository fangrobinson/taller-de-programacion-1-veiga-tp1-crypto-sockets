struct CesarStruct;
typedef struct CesarStruct *cesar_t;

void cesar_init(cesar_t cesar, char *key);
void cesar_cifrar(cesar_t cesar, char *s);
void cesar_descifrar(cesar_t cesar, char *s);
