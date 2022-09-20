CC = gcc
CFLAGS = -Wall
	
main: fila1.o fila1_main.c
	$(CC) -o main fila1.o fila1_main.c
	
fila1.o: fila1.c fila1.h
	$(CC) -c fila1.c
	
clean:
	rm main *.o

executa: main
	./main