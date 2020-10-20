struct ControladorCifradoresStruct;

#ifndef __CONTROLADOR_CIFRADOR_T__
#define __CONTROLADOR_CIFRADOR_T__
typedef struct ControladorCifradoresStruct *cifradores_t;
#endif

void controlador_cifradores_init(cifradores_t cifradores, char *metodo, char *key);
void controlador_cifradores_uninit(cifradores_t cifradores);
