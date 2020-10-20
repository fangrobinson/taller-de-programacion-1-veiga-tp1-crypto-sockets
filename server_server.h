#ifndef __SERVER_H__
#define __SERVER_H__

struct ServerStruct;

#ifndef __SERVER_T__
#define __SERVER_T__
typedef struct ServerStruct *server_t;
#endif


void server_init(server_t server, char *port, char *method, char *key);
void server_uninit(server_t server);
//void server_connect(server_t server);
void server_send_msg(server_t server, char *msg);

#endif