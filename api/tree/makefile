main: main.o queue.o tree.o
	gcc -o main main.o queue.o tree.o
main.o: main.c tree.h
	gcc -c main.c
tree.o: tree.c tree.h queue.c queue.h
	gcc -c tree.c queue.c
clean: 
	rm *.o
