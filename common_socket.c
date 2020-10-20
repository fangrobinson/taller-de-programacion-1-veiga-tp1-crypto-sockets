#define _XOPEN_SOURCE 600

#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>
#include "common_socket.h"

void socket_init(socket_t *socket){

}

int socket_uninit(socket_t *socket){
	return close(socket->socket);
}

int socket_bind_and_listen(socket_t *a_socket, unsigned short port){
	struct addrinfo hints;
	struct addrinfo *results;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;     
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = AI_PASSIVE;

	char port_string[4];
	sprintf(port_string, "%hu", port);
	int status = getaddrinfo(0, port_string, &hints, &results);
	if (status == 1) {
		return status;
	}

	a_socket->socket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	if (a_socket->socket == -1) {
		freeaddrinfo(results);
		return 1;
	}

	int valid_bind = bind(a_socket->socket, results->ai_addr, results->ai_addrlen);
	if (valid_bind != 0) {
		freeaddrinfo(results);
		socket_uninit(a_socket);
		return 1;
	}
	
	int valid_listen = listen(a_socket->socket, 1);
	if (valid_listen != 0) { 
		freeaddrinfo(results);
		socket_uninit(a_socket);
		return 1;
	}

	freeaddrinfo(results);
	return 0;
}

int socket_connect(socket_t *a_socket, const char *server, unsigned short port){

	struct addrinfo hints;
	struct addrinfo *results;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;
	
	char port_string[4];
	sprintf(port_string, "%d", port);
	int status = getaddrinfo(server, port_string, &hints, &results);
	if (status == 1) {
		return 1;
	}
	
	a_socket->socket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	if (a_socket->socket == -1) {
		freeaddrinfo(results);
		return 1;
	}

	int valid_connect = connect(a_socket->socket, results->ai_addr, results->ai_addrlen);
	if (valid_connect == 1) {
		freeaddrinfo(results);
		socket_uninit(a_socket);
		return 1;
	}
	
	freeaddrinfo(results);
	return 0;
}

int socket_accept(socket_t *socket, socket_t *socket_to_accept){
	socket_to_accept->socket = accept(socket->socket, NULL, NULL);
	if (socket_to_accept->socket == -1) {
		socket_uninit(socket_to_accept);
		return 1;
	}
	return 0;
}

void socket_shutdown(socket_t *socket){
	shutdown(socket->socket, SHUT_RDWR);
}

int socket_send(socket_t *socket, const char *buffer, size_t length){
	int bytes_sent = 0;
	int socket_open = 1;

	while (length >= bytes_sent && socket_open) {
		int bytes_to_add = send(socket->socket, (buffer + bytes_sent), length - bytes_sent,
		MSG_NOSIGNAL);
		if (bytes_to_add > 0){
			bytes_sent += bytes_to_add;
		} else {
			socket_open = 0;
		}
	}

	return socket_open;
}

