main: main.o stack_void.o
	gcc -o main main.o stack_void.o
main.o: main.c stack_void.h
	gcc -c main.c
stack_void: stack_void.c stack_void.h
	gcc -c stack_void.c
clean:
	rm *.o
