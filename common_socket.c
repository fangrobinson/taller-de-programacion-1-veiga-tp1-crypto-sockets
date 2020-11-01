//#define _XOPEN_SOURCE 600
#define _POSIX_C_SOURCE 200112L

#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>
#include "common_socket.h"

void socket_init(socket_t *socket){}

int socket_uninit(socket_t *socket){
	return close(socket->socket);
}

int socket_bind_and_listen(socket_t *a_socket, const char *port){
	struct addrinfo hints;
	struct addrinfo *results, *rp;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;     
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = AI_PASSIVE;

	int status = getaddrinfo(0, port, &hints, &results);
	if (status == 1) {
		return status;
	}

	int sfd;
	int val = 1;

    for (rp = results; rp != NULL; rp = rp->ai_next) {
       	sfd = socket(rp->ai_family, rp->ai_socktype,
               rp->ai_protocol);
       	if (sfd == -1)
           continue;
		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
       	if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
           break;
    	close(sfd);
    }


    if (rp == NULL) {
    	freeaddrinfo(results);
    	return 1;
    }
	
    a_socket->socket = sfd;

	int valid_listen = listen(a_socket->socket, 1);
	if (valid_listen != 0) { 
		freeaddrinfo(results);
		socket_uninit(a_socket);
		return 1;
	}

	freeaddrinfo(results);
	return 0;
}

int socket_connect(socket_t *a_socket, const char *server, const char *port){
	struct addrinfo hints;
	struct addrinfo *results, *rp;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;

	int status = getaddrinfo(server, port, &hints, &results);
	if (status == 1) {
		return 1;
	}
	
	int sfd;
	int val = 1;

    for (rp = results; rp != NULL; rp = rp->ai_next) {
       	sfd = socket(rp->ai_family, rp->ai_socktype,
               rp->ai_protocol);
       	if (sfd == -1)
           continue;
		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
       	if (connect(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
           break;
    	close(sfd);
    }


    if (rp == NULL) {
    	freeaddrinfo(results);
    	return 1;
    }
	

    a_socket->socket = sfd;
	
	freeaddrinfo(results);
	return 0;
}

int socket_accept(socket_t *socket, socket_t *socket_to_accept) {
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
		int bytes_to_add = send(socket->socket, (buffer + bytes_sent), 
			length - bytes_sent, 0);
		if (bytes_to_add > 0){
			bytes_sent += bytes_to_add;
		} else if (bytes_to_add == 0){
			socket_open = 0;
		} else {
			return -1;
		}
	}

	return bytes_sent;
}

int socket_receive(socket_t *socket, char *buffer, size_t length){
	int bytes_received = 0;
	int socket_open = 1;

	while (length > bytes_received && socket_open == 1) {
		int bytes_to_add = recv(socket->socket, &buffer[bytes_received], 
			length - bytes_received, 0);
		
		if (bytes_to_add > 0){
			bytes_received += bytes_to_add;
		} else {
			socket_open = bytes_to_add;
		}
	}
	return bytes_received;
}
