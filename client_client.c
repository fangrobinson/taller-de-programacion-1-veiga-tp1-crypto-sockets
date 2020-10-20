#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client_client.h"

#define SIZE_OF_CHUNK 64


#ifndef __CLIENT_T__
#define __CLIENT_T__
typedef struct ClientStruct *client_t;
#endif


void client_init(client_t client, char *server, char *port, char *method, 
				char *key){
	client->server = malloc(strlen(server) + 1);
	strcpy(client->server, server);
	client->port = malloc(strlen(port) + 1);
	strcpy(client->port, port);
	client->method = malloc(strlen(method) + 1);
	strcpy(client->method, method);
	client->key = malloc(strlen(key) + 1);
	strcpy(client->key, key);

	client->size_of_buffer = SIZE_OF_CHUNK;

	client->cifradores = malloc(sizeof(struct ControladorCifradoresStruct));

	controlador_cifradores_init(client->cifradores, client->method, 
								client->key);

}

void client_uninit(client_t client){
	controlador_cifradores_uninit(client->cifradores);
	free(client->cifradores);
	free(client->server);
	free(client->port);
	free(client->method);
	free(client->key);
}


void client_connect(client_t client){

}

void client_send_msg(client_t client, char *msg){
	char *buffer = malloc(client->size_of_buffer);
	int len_to_send = strlen(msg);
	int bytes_sent = 0;
	int bytes_sending = 0;

	while (len_to_send > bytes_sent){

		bytes_sending = snprintf(buffer, client->size_of_buffer, "%s", msg + bytes_sent);


		printf("%d\n", bytes_sending);
	


		controlador_cifradores_cifrar(client->cifradores, buffer, client->size_of_buffer);
		buffer[bytes_sending] = '\0';

		bytes_sent += bytes_sending;

	}
	free(buffer);
}
