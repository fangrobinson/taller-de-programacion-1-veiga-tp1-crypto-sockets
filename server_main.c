#include "server_server.h"
//#include "server_server.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_CHUNK 64
#define OK 0
#define ERROR 1

int main(int argc, char const *argv[])
{
    if (argc != 4) {
        printf("Cantidad de argumentos incorrecta \n");
        return 0;
    }
    const char *port = argv[1];
    const char *method = argv[2] + 9;
    const char *key = argv[3] + 6;

    printf("%s\n", port);
    printf("%s\n", method);
    printf("%s\n", key);

    server_t server;

    server_init(&server, SIZE_OF_CHUNK, port, method, key);
    if (server_run(&server)) {
        server_uninit(&server);
        printf("ERROR SERVER - RUN\n");
        return ERROR;
    }
    server_uninit(&server);
    return OK;
}


