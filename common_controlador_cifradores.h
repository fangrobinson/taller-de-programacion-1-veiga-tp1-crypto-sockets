struct ControladorCifradoresStruct;
typedef struct ControladorCifradoresStruct *cifradores_t;

void controlador_cifradores_init(cifradores_t cifradores, char *metodo, char *key);
void controlador_cifradores_uninit(cifradores_t cifradores);
