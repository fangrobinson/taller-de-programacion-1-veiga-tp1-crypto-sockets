
void socket_init(socket_t *socket){

}
int socket_uninit(socket_t *socket){
	return close(self->socket);
}


int socket_bind_and_listen(socket_t *socket, unsigned short port){
	struct addrinfo hints;
	struct addrinfo *results;

	char port_string[4];
	sprintf(port_string, "%hu", port);
	int status = getaddrinfo(0, port_string, &hints, &results);
	freeaddrinfo(results);
	return SUCCESS;

}

int socket_connect(socket_t *socket, const char *server, unsigned short port);
int socket_accept(socket_t *socket, socket_t *socket_to_accept);
void socket_shutdown(socket_t *socket);