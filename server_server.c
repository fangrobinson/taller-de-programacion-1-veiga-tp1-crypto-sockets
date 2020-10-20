#include "common_controlador_cifradores.h"
#include "common_controlador_cifradores.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ServerStruct{
	char *port;
	char *method;
	char *key;
	unsigned int size_of_buffer;
	cifradores_t cifradores;
};


#ifndef __SERVER_T__
#define __SERVER_T__
typedef struct ServerStruct *server_t;
#endif


void server_init(server_t server, char *port, char *method, char *key);
void server_uninit(server_t server);
//void server_connect(server_t server);
void server_send_msg(server_t server, char *msg);
