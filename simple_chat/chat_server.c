#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "utils.h"


/*	connect [host] [port]: attempt to connect to host
 *	arguments: string containing "connect", host, and port
 *	return value:
 *		0: connection closed
 *		1: connection failed
 *	notes: This function should block until the connection is closed,
 *		or the connection attempt fails.
 */
int connect(char *buffer) {
	// Validate arguments
	
	// Attempt to connect
	
	// Wait for connection to close
	
	return 0;
}

int main() {
	const int BUFFER_LENGTH = 512;
	char buffer[BUFFER_LENGTH];
	
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
