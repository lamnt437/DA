main: main.o queue_void.o
	gcc -o main main.o queue_void.o
main.o: main.c queue_void.h
	gcc -c main.c
queue_void.o: queue_void.c queue_void.h
	gcc -c queue_void.c
clean:
	rm *.o
