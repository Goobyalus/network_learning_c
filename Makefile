CC = gcc
CFLAGS = -g -Wall

BIN = server client

all:
	$(CC) -o server server.c $(CFLAGS)
	$(CC) -o client client.c $(CFLAGS)

clean:
	rm -f *.o server client
