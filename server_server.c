#include "common_controlador_cifradores.h"
//#include "common_controlador_cifradores.c"
#include "server_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_socket.h"
#define SIZE_OF_CHUNK 64

void server_init(server_t *server, size_t buffer_size, const char *port, const char *method, const char *key) {
    server->buffer_size = buffer_size;
    server->port = port;
    server->method = method;
    server->key = key;
    //iniciar controlador de cifradores;
    //iniciar socket;
}

void server_uninit(server_t *server){
	//controlador_cifradores_uninit(server->cifradores);
	//socket_shutdown(&server->socket);
	//socket_uninit(&server->socket);
	//free(server->cifradores);
}

int server_run(server_t *server){
    return 0;
    /*
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
	if (!buffer) {
		printf("Buffer problems\n");
	}

	while (1) {
		int cant = socket_receive(&socket_to_accept, buffer, SIZE_OF_CHUNK);
		printf("BUFFER\n");
		fwrite(buffer, 1, cant, stdout);
		break; //DELETE
	}

	free(buffer);
	return 0;
    */
}
