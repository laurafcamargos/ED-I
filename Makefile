main: main.c conjunto1.c cod1.h
	gcc -c main.c conjunto1.c
	gcc -o exemplo main.o conjunto1.o
	./exemplo

clean: 
	rm edit main.o conjunto1.o

