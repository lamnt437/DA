#gan ten bien thay the
CFLAGS = -c -Wall		
CC = gcc
#GNU debug
GNU = -g

#lenh make mac dinh chay dong dau tien cua makefile
#de chay cac dong khac: make + ten. Vi du: make clean, make linkedlist.o
#cau truc:
#ten: input
	#<tab> output
#clean: ko co input nen se chay ngay khi goi make clean
	#lenh rm -f la xoa cac file co duoi .o

queue_implement: main.o queue.o 
	${CC} -o queue_implement main.o queue.o
main.o: main.c queue.h
	${CC} ${CFLAGS} main.c
stack.o: queue.c queue.h
	${CC} ${CFLAGS} queue.c
clean:
	rm -f *.o *_
