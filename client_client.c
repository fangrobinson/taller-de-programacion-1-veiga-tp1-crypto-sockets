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

	//struct ControladorCifradoresStruct controlador_cifradores_struct;
	//cifradores_t cifradores = &cifradores_struct;

	// inicializar mi cifrador

	// cifrar mensajes de a chunks

	// enviar ?

	return 0;
}