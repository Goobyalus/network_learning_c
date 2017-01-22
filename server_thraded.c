#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT_STR "8000"

int main() {

	int sockfd;				// Socket file descriptor
	int newsockfc;			//
	int portno;				// Port number
	socklen_t clilen;		//
	char buffer[256]		// buffer for message
	struct sockaddr_in serv_addr, cli_addr; // server and client addrs
	int n;

	sockfd = socket(
					AF_INET,		// Just use AF_INET
					SOCK_STREAM,	// SOCK_STREAM = TCP, SOCK_DGRAM=UDP
					0);				// 

	return 0;
}
