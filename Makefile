CC = gcc
CFLAGS = -Wall
	
all: listadinam.o listadinam_main.c
	$(CC) -o main listadinam.o listadinam_main.c
	
listadinam.o: listadinam.c listadinam.h
	$(CC) -c listadinam.c
	
clean:
	rm main *.o

run: main
	./main