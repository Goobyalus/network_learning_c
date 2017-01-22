#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT_STR "8000"

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main() {

	int sockfd;				// listening socket file descriptor
	int newsockfd;			// client file descriptor
	int portno;				// port number
	socklen_t clilen;		// ?
	char buffer[256];		// buffer for message
	struct sockaddr_in serv_addr, cli_addr; // server and client addrs
	int n;

	// Open socket
	sockfd = socket(
				AF_INET,		// Just use AF_INET
				SOCK_STREAM,	// SOCK_STREAM = TCP, SOCK_DGRAM=UDP
				0);				// ?
	if(sockfd < 0) { error("ERROR opening socket"); }

	// Bind socket
	bzero((char *) &serv_addr, sizeof(serv_addr)); // zero addr struct
	portno = atoi(PORT_STR);				// port no fm string
	serv_addr.sin_family = AF_INET;			// address family AF_INET
	serv_addr.sin_port = htons(portno);		// port in network order
	serv_addr.sin_addr.s_addr = INADDR_ANY;	// accept any address (nbo)
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
			sizeof(serv_addr)) < 0) {
		error("ERROR on binding");
	}
	
	// Allow connection requests to queue
	listen(	sockfd, // file descriptor for SOCK_STREAM or SOCK_SEQPACKET
			1		// max length of pending connections
		);
	
	// Pull connection request from queue, or block until request made
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd,
		(struct sockaddr *) &cli_addr,
		&clilen
		);
	if (newsockfd < 0) { error("ERROR on accept"); }

	// Read from client
	bzero(buffer, 256);
	n = read(newsockfd, buffer, 255);
	if (n < 0) { error("ERROR reading from socket"); }
	// TODO: EINTR check

	// Output and echo
	printf("Received %s\n", buffer);
	n = write(newsockfd, buffer, n);
	if (n < 0) { error("ERROR writing to socket"); }

	// Close sockets
	close(newsockfd);
	close(sockfd);
	return 0;
}
