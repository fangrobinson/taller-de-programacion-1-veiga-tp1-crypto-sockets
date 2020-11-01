#ifndef __CONTROLADOR_CIFRADOR_H__
#define __CONTROLADOR_CIFRADOR_H__

typedef struct ControladorCifradoresStruct{
	void *c;
	const char *metodo;
} cifradores_t;

// aloca e inicializa el cifrador correcto de acuerdo al metodo a utilizar
void controlador_cifradores_init(cifradores_t *cifradores, const char *metodo,
	                             const char *key);

// deinicializa y libera el cifrador correcto de acuerdo al metodo utilizado
void controlador_cifradores_uninit(cifradores_t *cifradores);

// delega en el cifrador el cifrado de un mensaje de largo str_len
// altera el contenido del buffer msg
void controlador_cifradores_cifrar(cifradores_t *cifradores, char *msg,
	                               unsigned int str_len);

// delega en el cifrador el descifrado de un mensaje de largo str_len
// altera el contenido del buffer msg
void controlador_cifradores_descifrar(cifradores_t *cifradores, char *msg,
	                               unsigned int str_len);
#endif
