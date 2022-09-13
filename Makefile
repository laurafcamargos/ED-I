main: aula1.c conjunto.c aula1.h
	gcc -c aula1.c conjunto.c
	gcc -o main aula1.o conjunto.o

clean: 
	rm aula1.o conjunto.o main

executa: main
	./main