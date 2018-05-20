CFLAGS = -c -Wall
CC = gcc
GNU = -g

check: check_sym.o stack.o queue.o
	${CC} -o check check_sym.o stack.o queue.o
check_sym.o: check_sym.c stack.h queue.h
	${CC} ${CFLAGS} check_sym.c
stack.o: stack.c stack.h queue.c queue.h
	${CC} ${CFLAGS} stack.c
queue.o: queue.c queue.h stack.c stack.h
	${CC} ${CFLAGS} queue.c
clean:
	rm -f *.o *_
