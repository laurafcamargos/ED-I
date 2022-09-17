CC = gcc
CFLAGS = -Wall
	
main: listadinam.o listadinam_main.c
	$(CC) -o main listadinam.o listadinam_main.c
	
listadinam.o: listadinam.c listadinam.h
	$(CC) -c listadinam.c
	
clean:
	rm main *.o

executa: main
	./main