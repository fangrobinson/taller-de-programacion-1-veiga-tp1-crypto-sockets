struct VigenereStruct;
typedef struct VigenereStruct *vigenere_t;

void vigenere_init(vigenere_t, char *key);
void vigenere_del(vigenere_t v);

void vigenere_cifrar(vigenere_t v, char *s);
void vigenere_descifrar(vigenere_t v, char *s);
