#ifndef __SOCKET_H__
#define __SOCKET_H__

struct SocketStruct{
	int socket;
};

typedef struct SocketStruct socket_t;

void socket_init(socket_t *socket);
int socket_uninit(socket_t *socket);

#endif
