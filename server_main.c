#include "server_server.h"
//#include "server_server.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	char *port = malloc(strlen(argv[1]) + 1);
	snprintf(port, strlen(argv[1]) + 1,"%s", argv[1]);

	char *method = malloc(strlen(argv[2]) + 1);
	snprintf(method, strlen(argv[2]) + 1,"%s", argv[2]);

	char *key = malloc(strlen(argv[3]) + 1);
	snprintf(key, strlen(argv[3]) + 1,"%s", argv[3]);

	struct ServerStruct server;

	server_init(&server, port, method, key);
	server_receive(&server);
	server_uninit(&server);

	free(port);
	free(method);
	free(key);
}


