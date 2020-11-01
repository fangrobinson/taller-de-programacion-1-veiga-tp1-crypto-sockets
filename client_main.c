#include "client_client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_CHUNK 64
#define ERROR 1
#define OK 0

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

    client_t client;
    client_init(&client, SIZE_OF_CHUNK, host, port, method, key);
    if (client_run(&client)) {
        client_uninit(&client);
        printf("ERROR CLIENT - RUN\n");
        return ERROR;
    }
    client_uninit(&client);
    return OK;
}
