#ifndef __CONTROLADOR_CIFRADOR_H__
#define __CONTROLADOR_CIFRADOR_H__

struct ControladorCifradoresStruct;

#ifndef __CONTROLADOR_CIFRADOR_T__
#define __CONTROLADOR_CIFRADOR_T__

struct ControladorCifradoresStruct{
	void *c;
	char *metodo;
};

typedef struct ControladorCifradoresStruct *cifradores_t;
#endif

void controlador_cifradores_init(cifradores_t cifradores, char *metodo, 
	                             char *key);
void controlador_cifradores_uninit(cifradores_t cifradores);
void controlador_cifradores_cifrar(cifradores_t cifradores, char *msg, 
	                               unsigned int str_len);
void controlador_cifradores_descifrar(cifradores_t cifradores, char *msg, 
	                               unsigned int str_len);
#endif