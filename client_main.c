#include "client_client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "client_client.c"

int main(int argc, char const *argv[])
{
	
	printf("server: %s\n", argv[1]);
	printf("port: %s\n", argv[2]);
	printf("method: %s\n", argv[3]);
	printf("key: %s\n", argv[4]);
	printf("stdin: %s\n", argv[5]);


	char *server = malloc(strlen(argv[1]) + 1);
	strcpy(server, argv[1]);

	char *port = malloc(strlen(argv[2]) + 1);
	strcpy(port, argv[2]);

	char *metodo = malloc(strlen(argv[3]) + 1);
	strcpy(metodo, argv[3]);

	char *key = malloc(strlen(argv[4]) + 1);
	strcpy(key, argv[4]);

	char *msg = malloc(strlen(argv[5]) + 1);
	strcpy(msg, argv[5]);
	
	struct ClientStruct client;

	client_init(&client, server, port, metodo, key);
	//client_connect(client);
	client_send_msg(&client, msg);
	client_uninit(&client);
	
	free(server);
	free(port);
	free(metodo);
	free(key);
	free(msg);

	return 0;
}
