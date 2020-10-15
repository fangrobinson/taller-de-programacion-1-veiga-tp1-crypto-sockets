struct VigenereStruct;
typedef struct VigenereStruct *vigenere_t;

vigenere_t crear_vigenere(char *key);
void del_vigenere(vigenere_t v);

void vigenere_cifrar(vigenere_t v, char *s);
void vigenere_descifrar(vigenere_t v, char *s);
