#include "common_controlador_cifradores.h"
#include "server_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_socket.h"

#define OK 0
#define ERROR 1

void server_init(server_t *server, size_t buffer_size, const char *port, const char *method, const char *key) {
    server->buffer_size = buffer_size;
    server->port = port;
    server->method = method;
    server->key = key;

    socket_init(&server->socket);

    controlador_cifradores_init(&server->cifradores, server->method,
                                server->key);
}

void server_uninit(server_t *server){
    socket_shutdown(&server->socket);
    socket_uninit(&server->socket);
    controlador_cifradores_uninit(&server->cifradores);
}

int server_run(server_t *server){
    int connected = socket_bind_and_listen(&server->socket, server->port);
    if (connected != OK) {
        return ERROR;
    }

    socket_t socket_to_accept;

    connected = socket_accept(&server->socket, &socket_to_accept);
    if (connected != OK) {
        return ERROR;
    }
    char buffer[server->buffer_size];
    int bytes_recibidos;
    do {
        bytes_recibidos = socket_receive(&socket_to_accept, buffer, server->buffer_size);
        //printf("buffer received:\n%s\n", buffer);
        controlador_cifradores_descifrar(&server->cifradores, buffer, bytes_recibidos);
        fwrite(buffer, 1, bytes_recibidos, stdout);
        //printf("Bytes Recibidos: %d\n", bytes_recibidos);
    } while (bytes_recibidos == server->buffer_size);

    return OK;
}
