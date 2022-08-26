main: aula1.c conjunto.c aula1.h
	gcc -c aula1.c conjunto.c
	gcc -o conjunto aula1.o conjunto.o
	./conjunto

clean: 
	rm aula1.o conjunto.o

