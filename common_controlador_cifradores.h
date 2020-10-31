#ifndef __CONTROLADOR_CIFRADOR_H__
#define __CONTROLADOR_CIFRADOR_H__

typedef struct ControladorCifradoresStruct{
	void *c;
	const char *metodo;
} cifradores_t;

void controlador_cifradores_init(cifradores_t *cifradores, const char *metodo,
	                             const char *key);
void controlador_cifradores_uninit(cifradores_t *cifradores);
void controlador_cifradores_cifrar(cifradores_t *cifradores, char *msg,
	                               unsigned int str_len);
void controlador_cifradores_descifrar(cifradores_t *cifradores, char *msg,
	                               unsigned int str_len);
#endif
