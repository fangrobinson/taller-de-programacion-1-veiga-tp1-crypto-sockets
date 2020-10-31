#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "client_client.h"
#include "client_file_reader.h"

#define OK 0
#define ERROR 1
#define SIZE_OF_CHUNK 64

void client_init(client_t *client, size_t buffer_size,const char *server, const char *port, const char *method,
				const char *key){
    client->buffer_size = buffer_size;
	client->server = server;
	client->port = port;
	client->method = method;
	client->key = key;

    socket_init(&client->socket);

	controlador_cifradores_init(&client->cifradores, client->method,
								client->key);
}

void client_uninit(client_t *client){
    socket_shutdown(&client->socket);
    socket_uninit(&client->socket);
    controlador_cifradores_uninit(&client->cifradores);
}

int client_run(client_t *client) {
    int connected = socket_connect(&client->socket, client->server, client->port);
    if (connected != OK) {
        return ERROR;
    }
    printf("CONECTADO");
    char buffer[client->buffer_size];
    file_reader_t file_reader;
    file_reader_init(&file_reader, client->buffer_size);
    unsigned int amount_read;
    int socket_open = 1;
    while ((amount_read = file_reader_next(&file_reader, buffer)) && socket_open) {
        printf("AMOUNT READ: %d\n", amount_read);
        controlador_cifradores_cifrar(&client->cifradores, buffer, amount_read);
        printf("%s\n", buffer);
        socket_open = socket_send(&client->socket, buffer, amount_read);
        /*if (!socket_open) {
            return ERROR;
        }*/
    }
    file_reader_uninit(&file_reader);
    return OK;
}
