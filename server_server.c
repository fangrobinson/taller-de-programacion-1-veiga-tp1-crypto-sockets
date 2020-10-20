#include "common_controlador_cifradores.h"
//#include "common_controlador_cifradores.c"
#include "server_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_socket.h"
#define SIZE_OF_CHUNK 64

#ifndef __SERVER_T__
#define __SERVER_T__
typedef struct ServerStruct *server_t;
#endif

void server_init(server_t server, char *port, char *method, char *key){
	server->port = atoi(port);
	server->method = malloc(strlen(method) + 1);
	strcpy(server->method, method);
	server->key = malloc(strlen(key) + 1);
	strcpy(server->key, key);

	// HARDCODED SIZE OF CHUNK:
	server->size_of_buffer = 64;

	server->cifradores = malloc(sizeof(struct ControladorCifradoresStruct));

	controlador_cifradores_init(server->cifradores, server->method, 
								server->key);

	socket_init(&server->socket);

}
void server_uninit(server_t server){
	controlador_cifradores_uninit(server->cifradores);
	socket_shutdown(&server->socket);
	socket_uninit(&server->socket);
	free(server->cifradores);
	//free(server->port);
	free(server->method);
	free(server->key);
}

int server_receive(server_t server){
	int connected = socket_bind_and_listen(&server->socket, server->port);
	if (connected != 0) {
		return 1;
	}

	socket_t socket_to_accept;

	connected = socket_accept(&server->socket, &socket_to_accept);
	if (connected != 0) {
		return 1;
	}

	char *buffer = malloc(sizeof(SIZE_OF_CHUNK));

	while (1) {
		int cant = socket_receive(&server->socket, buffer, SIZE_OF_CHUNK);
		fwrite(buffer, 1, cant, stdout);
		break;
	}

	free(buffer);
	return 0;
}
