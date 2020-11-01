#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "client_client.h"
#include "client_file_reader.h"

#define OK 0
#define ERROR 1

void client_init(client_t *client, size_t buffer_size, 
                    const char *server, 
                    const char *port, 
                    const char *method,
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
    int connected = socket_connect(&client->socket, 
                                    client->server, client->port);
    if (connected != OK) {
        return ERROR;
    }
    char *buffer = malloc(client->buffer_size);
    file_reader_t file_reader;
    file_reader_init(&file_reader, client->buffer_size);
    unsigned int amount_read;
    int bytes_sent = 1;
    amount_read = file_reader_next(&file_reader, buffer);
    while ((amount_read > 0) && (bytes_sent > 0)) { //&& socket_open
        controlador_cifradores_cifrar(&client->cifradores, buffer, amount_read);
        bytes_sent = socket_send(&client->socket, buffer, amount_read);
        amount_read = file_reader_next(&file_reader, buffer);
    }
    free(buffer);
    file_reader_uninit(&file_reader);
    return OK;
}
