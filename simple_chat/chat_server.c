#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "utils.h"

const int BUFFER_LENGTH = 512;

pthread_mutex_t incoming_lock;
pthread_mutex_t outgoing_lock;

/*	connect [host] [port]: attempt to connect to host
 *	arguments: string containing "connect", host, and port
 *	return value:
 *		0: connection closed
 *		1: connection failed
 *	notes: This function should block until the connection is closed,
 *		or the connection attempt fails.
 */
int connect_to(char *buffer) {
	// Validate arguments
	
	// Attempt to connect
	
	// Wait for connection to close
	
	return 0;
}

lfc_ret_t listen_for_connections(lfc_args_t *args) {
	int sockfd;
	socklen_t clilen;
	char in_buffer[BUFFER_LENGTH];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		return SOCKET_ERROR;
	}
	
}

int main() {
	char buffer[BUFFER_LENGTH];
	
	// Initialize mutexes
	if (! ( pthread_mutex_init(&incoming_lock) &&
			pthread_mutex_init(&outgoing_lock)) ) {
		printf("Error initializing mutexes.\n\n");
		return 1;
	}
	
	// Set up socket to listen for connections
	
	
	while(1) {
		bzero(buffer, BUFFER_LENGTH);
		readline("> ", buffer, BUFFER_LENGTH);
		
		if (0 == strcmp("exit", buffer)) {
			break;
		}
		else if (0 == strncmp("connect", buffer, 7) {
			connect(buffer);
		}
		else {
			printf("Unknown command\n\n");
		}
	}
	
	return 0;
}
