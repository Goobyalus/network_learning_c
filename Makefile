CC = gcc
CFLAGS = -g -Wall

BIN = server client server_threaded

.DEFAULT_GOAL = all

server_threaded:
	$(CC) -o server_threaded server_threaded.c $(CFLAGS) -lpthread

client_threaded:
	$(CC) -o client_threaded client_threaded.c $(CFLAGS) -lpthread

server:
	$(CC) -o server server.c $(CFLAGS)

client:
	$(CC) -o client client.c $(CFLAGS)

all:$(BIN)

clean:
	rm -f *.o $(BIN)
