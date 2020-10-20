#ifndef __CLIENT_H__
#define __CLIENT_H__

struct ClientStruct;

#ifndef __CLIENT_T__
#define __CLIENT_T__
typedef struct ClientStruct *client_t;
#endif


void client_init(client_t client, char *server, char *port, char *method, char *key);
void client_uninit(client_t client);
//void client_connect(client_t client);
void client_send_msg(client_t client, char *msg);

#endif