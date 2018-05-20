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

stack_implement: main.o stack.o 
	${CC} -o stack_implement main.o stack.o
main.o: main.c stack.h
	${CC} ${CFLAGS} main.c
stack.o: stack.c stack.h
	${CC} ${CFLAGS} stack.c
clean:
	rm -f *.o *_
