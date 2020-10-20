#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "common_controlador_cifradores.h"
#include "common_socket.h"

struct ClientStruct{
	char *server;
	unsigned short port;
	char *method;
	char *key;
	unsigned int size_of_buffer;
	cifradores_t cifradores;
	socket_t socket;
};

#ifndef __CLIENT_T__
#define __CLIENT_T__
typedef struct ClientStruct *client_t;
#endif


void client_init(client_t client, char *server, char *port, char *method, char *key);
void client_uninit(client_t client);
int client_connect(client_t client);
void client_send_msg(client_t client, char *msg);

#endif