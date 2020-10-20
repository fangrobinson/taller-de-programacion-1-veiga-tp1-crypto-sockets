#include "common_controlador_cifradores.h"
//#include "common_controlador_cifradores.c"
#include "server_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_socket.h"


#ifndef __SERVER_T__
#define __SERVER_T__
typedef struct ServerStruct *server_t;
#endif

void server_init(server_t server, char *port, char *method, char *key){
	server->port = malloc(strlen(port) + 1);
	strcpy(server->port, port);
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
	free(server->cifradores);
	free(server->port);
	free(server->method);
	free(server->key);
}

//void server_connect(server_t server);

void server_send_msg(server_t server, char *msg);
