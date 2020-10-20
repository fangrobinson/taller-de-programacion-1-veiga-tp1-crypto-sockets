#include "common_controlador_cifradores.h"
#include "common_controlador_cifradores.c"
#include <stdio.h>

//./client 127.0.0.1 8080 --method=rc4 --key=queso < __client_stdin__


int main(int argc, char const *argv[])
{
	printf("server: %s\n", argv[1]);
	printf("port: %s\n", argv[2]);
	printf("method: %s\n", argv[3]);
	printf("key: %s\n", argv[4]);
	printf("stdin: %s\n", argv[5]);

	char *metodo = malloc(strlen(argv[3])+1);
	strcpy(metodo, argv[3]);

	char *key = malloc(strlen(argv[4]) + 1);
	strcpy(key, argv[4]);

	char *msg = malloc(strlen(argv[5]) + 1);
	strcpy(msg, argv[5]);

	struct ControladorCifradoresStruct controlador_cifradores_struct;
	cifradores_t cifradores = &controlador_cifradores_struct;

	controlador_cifradores_init(cifradores, metodo, key);
	
	controlador_cifradores_cifrar(cifradores, msg, 1);
	printf("%s\n", msg);
	controlador_cifradores_descifrar(cifradores, msg, 1);
	printf("%s\n", msg);

	controlador_cifradores_uninit(cifradores);

	free(metodo);
	free(key);
	free(msg);

	return 0;
}