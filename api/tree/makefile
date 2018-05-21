main: main.o queue.o tree.o
	gcc -o main main.o queue.o tree.o
main.o: main.c tree.h
	gcc -c main.c
queue.o: queue.c queue.h tree.h
	gcc -c queue.c
tree.o: tree.c tree.h queue.h
	gcc -c tree.c
clean: 
	rm *.o
