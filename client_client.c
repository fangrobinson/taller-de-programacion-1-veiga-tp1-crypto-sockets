#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "client_client.h"
#include "client_file_reader.h"

#define SIZE_OF_CHUNK 64

#ifndef __CLIENT_T__
#define __CLIENT_T__
typedef struct ClientStruct *client_t;
#endif


void client_init(client_t client, char *server, char *port, char *method, 
				char *key){
	client->server = malloc(strlen(server) + 1);
	strcpy(client->server, server);
	client->port = atoi(port);
	client->method = malloc(strlen(method) + 1);
	strcpy(client->method, method);
	client->key = malloc(strlen(key) + 1);
	strcpy(client->key, key);

	client->size_of_buffer = SIZE_OF_CHUNK;

	client->cifradores = malloc(sizeof(struct ControladorCifradoresStruct));

	controlador_cifradores_init(client->cifradores, client->method, 
								client->key);
	socket_init(&client->socket);

}

void client_uninit(client_t client){
	controlador_cifradores_uninit(client->cifradores);
	socket_shutdown(&client->socket);
	socket_uninit(&client->socket);
	free(client->cifradores);
	free(client->server);
	free(client->method);
	free(client->key);
}


int client_connect(client_t client){
	int connected = socket_connect(&client->socket, client->server, client->port);
	if (connected != 0) {
		return -1;
	}
	return 0;
}

void client_send_msg(client_t client, char *input){
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
