#ifndef __SERVER_H__
#define __SERVER_H__
#include <stddef.h>
#include "common_controlador_cifradores.h"
#include "common_socket.h"

typedef struct ServerStruct{
	const char *port;
	const char *method;
	const char *key;
	const size_t buffer_size;
	cifradores_t cifradores;
	socket_t socket;
} server_t;

void server_init(server_t *server, size_t buffer_size, const char *port, const char *method, const char *key);
void server_uninit(server_t *server);
int server_run(server_t *server);

#endif
