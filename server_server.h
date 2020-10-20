#ifndef __SERVER_H__
#define __SERVER_H__
#include <stddef.h>
#include "common_controlador_cifradores.h"
#include "common_socket.h"

struct ServerStruct{
	unsigned short port;
	char *method;
	char *key;
	unsigned int size_of_buffer;
	cifradores_t cifradores;
	socket_t socket;
};

#ifndef __SERVER_T__
#define __SERVER_T__
typedef struct ServerStruct *server_t;
#endif

void server_init(server_t server, char *port, char *method, char *key);
void server_uninit(server_t server);
int server_receive(server_t server);

#endif