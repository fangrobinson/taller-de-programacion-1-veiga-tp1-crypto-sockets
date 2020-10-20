#include "common_controlador_cifradores.h"
#include "common_controlador_cifradores.c"
#include <stdio.h>

//./client 127.0.0.1 8080 --method=rc4 --key=queso < __client_stdin__

void client_cifrar_mensaje(char *metodo, char *mensaje, char *key){

}

int main(int argc, char const *argv[])
{
	
	printf("server: %s\n", argv[1]);
	printf("port: %s\n", argv[2]);
	printf("method: %s\n", argv[3]);
	printf("key: %s\n", argv[4]);
	printf("stdin: %s\n", argv[5]);

	printf("%s\n\n\n", argv[3]);
	printf("%ld\n", (strlen(argv[3]) + 1));

	char *metodo = malloc(strlen(argv[3])+1);
	if (!metodo){
		return -1;
	}
	strcpy(metodo, argv[3]);

	char *key = malloc(strlen(argv[4]) + 1);
	strcpy(key, argv[4]);

	struct ControladorCifradoresStruct controlador_cifradores_struct;
	cifradores_t cifradores = &controlador_cifradores_struct;

	controlador_cifradores_init(cifradores, metodo, key);
	
	char *msg_a_cifrar = malloc(strlen(argv[5]) + 1);
	char *msg_cifrado = malloc(strlen(argv[5]) + 1);

	controlador_cifradores_cifrar(cifradores, msg_cifrado, msg_a_cifrar);

	free(metodo);
	free(key);

	// inicializar mi cifrador

	// cifrar mensajes de a chunks

	// enviar ?

	return 0;
}