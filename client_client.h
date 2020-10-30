#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "common_controlador_cifradores.h"
#include "common_socket.h"

typedef struct ClientStruct{
	const char *server;
	const char *port;
	const char *method;
	const char *key;
	size_t buffer_size;
	cifradores_t cifradores;
	socket_t socket;
} client_t;


void client_init(client_t *client, size_t buffer_size,const char *server, const char *port,
                 const char *method, const char *key);
void client_uninit(client_t *client);
int client_run(client_t *client);
//int client_connect(client_t *client);
//void client_send_msg(client_t *client, char *msg);

#endif
