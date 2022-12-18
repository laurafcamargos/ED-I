CC = gcc
CFLAGS = -Wall
	
all: contatinho.o main.c
	$(CC) -o main contatinho.o main.c
	
contatinho.o: contatinho.c contatinho.h
	$(CC) -c contatinho.c
	
clean:
	rm main *.o

run: main
	./main