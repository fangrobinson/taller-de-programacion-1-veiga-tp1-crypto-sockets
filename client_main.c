#include "client_client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_CHUNK 64
#define ERROR 1
#define OK 0

// ./client 127.0.0.1 8080 --method=cesar --key=5 < __client_stdin__

int main(int argc, char const *argv[])
{
    if (argc != 5) {
        printf("Cantidad de argumentos incorrecta \n");
        return 0;
    }
    const char *host = argv[1];
    const char *port = argv[2];
    const char *method = argv[3] + 9;
    const char *key = argv[4] + 6;

    printf("%s\n", host);
    printf("%s\n", port);
    printf("%s\n", method);
    printf("%s\n", key);

    client_t client;
    client_init(&client, SIZE_OF_CHUNK, host, port, method, key);
    if (client_run(&client)) {
        client_uninit(&client);
        printf("ERROR CLIENT - RUN\n");
        return ERROR;
    }
    client_uninit(&client);
    return OK;


	/*

	
	struct ClientStruct client;

	client_init(&client, server, port, metodo, key);
	client_connect(&client);
	client_send_msg(&client, NULL);
	client_uninit(&client);

	*/
}
