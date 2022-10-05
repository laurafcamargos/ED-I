CC = gcc
CFLAGS = -Wall
	
all: trabalho1.o trabalho1_main.c
	$(CC) -o main trabalho1.o trabalho1_main.c
	
trabalho1.o: trabalho1.c trabalho1.h
	$(CC) -c trabalho1.c
	
clean:
	rm main *.o

run: main
	./main