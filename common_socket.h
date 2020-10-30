#ifndef __SOCKET_H__
#define __SOCKET_H__
#include "common_socket.h"
#include <stddef.h>

struct SocketStruct{
	int socket;
};

typedef struct SocketStruct socket_t;

void socket_init(socket_t *socket);
int socket_uninit(socket_t *socket);

int socket_bind_and_listen(socket_t *socket, const char *port);
int socket_connect(socket_t *socket, const char *server, const char *port);
int socket_accept(socket_t *socket, socket_t *socket_to_accept);
void socket_shutdown(socket_t *socket);

int socket_send(socket_t *socket, const char *buffer, size_t length);
int socket_receive(socket_t *socket, char *buffer, size_t length);

#endif
