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

    // init cifradores
	//client->cifradores = malloc(sizeof(struct ControladorCifradoresStruct));


	//controlador_cifradores_init(client->cifradores, client->method,
	//							client->key);

	// init socket
	//socket_init(&client->socket);

}

void client_uninit(client_t *client){
    socket_shutdown(&client->socket);
    socket_uninit(&client->socket);
    return;
	controlador_cifradores_uninit(client->cifradores);


	free(client->cifradores);
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
    while ((amount_read = file_reader_next(&file_reader, buffer))) {
        int bytes_sending = 0;
        //controlador_cifradores_cifrar(client->cifradores, buffer, client->size_of_buffer);
        printf("%s\n", buffer);
        bytes_sending = socket_send(&client->socket, buffer, amount_read);
        //printf("%d\n", bytes_sending);
    }
    file_reader_uninit(&file_reader);
    return OK;
}


/*
void client_send_msg(client_t *client, char *input){
	file_reader_t file_reader;

	char *buffer = malloc(client->size_of_buffer);

	file_reader_init(&file_reader, input, client->size_of_buffer);

	unsigned int amount_read;

	while ((amount_read = file_reader_next(&file_reader, buffer))) {
		int bytes_sending = 0;
		controlador_cifradores_cifrar(client->cifradores, buffer, client->size_of_buffer);
		printf("%s\n", buffer);
		bytes_sending = socket_send(&client->socket, buffer, amount_read);
		printf("%d\n", bytes_sending);
	}

	file_reader_uninit(&file_reader);
	free(buffer);
	return;
}
*/
