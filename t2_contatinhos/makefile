CC = gcc
CFLAGS = -Wall
objects = main.o contatinho.o

executa: main
	./main
	
main: contatinho.o main.c
	$(CC) -o main contatinho.o main.c
	
contatinho.o: contatinho.c contatinho.h
	$(CC) -c contatinho.c
	
clean:
	rm main $(objects)