#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <pthread.h>

struct client_thread_arg {
	char *portstr; // string of the port number
	char *hostname;
};

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

void terror(char *msg, int sockfd) {
	if(sockfd > 0) {close(sockfd);}
	pthread_exit(msg);
}

void *client_thread(void *arg) {
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	
	// extract arguments from arg structure
	const char *portstr = 
		((struct client_thread_arg *)arg)->portstr;
	const char *hostname =
		((struct client_thread_arg *)arg)->hostname;
	
	// Open socket
	portno = atoi(portstr);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		terror("ERROR opening socket", sockfd);
	
	// Connect to server
	server = gethostbyname(hostname);
	if (server == NULL) {
		terror("No such host", sockfd);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;				// family
	bcopy((char *)server->h_addr, 
		 (char *)&serv_addr.sin_addr.s_addr,	// address
		 server->h_length);
	serv_addr.sin_port = htons(portno);			// port
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		terror("ERROR connecting", sockfd);
	
	// Communicate with server
	do {
		printf("Please enter the message: ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);
		n = write(sockfd,buffer,strlen(buffer));
		if (n < 0) 
			 terror("ERROR writing to socket", sockfd);
		bzero(buffer,256);
		n = read(sockfd,buffer,255);
		if (n < 0) 
			 terror("ERROR reading from socket", sockfd);
		printf("%s\n",buffer);
	} while (0 != strcmp(buffer, "exit"));
	
	close(sockfd);
	return 0;
}

int main(int argc, char *argv[])
{
	struct client_thread_arg cta;
	cta.portstr = "8000";
	cta.hostname = "127.0.0.1";
	
	pthread_t thread_obj;
	int rv = 
		pthread_create(&thread_obj, NULL, client_thread, &cta);
	if (0 != rv) { error("ERROR creating thread."); }
	char *thread_return_value;
	pthread_join(thread_obj, (void**)(&thread_return_value));
	printf("thread_return_value: %s\n\n", thread_return_value);
	
	return 0;
}
