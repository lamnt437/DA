#list: linkedlist.o main.o
#	gcc -o list main.o linkedlist.o
#linkedlist.o: linkedlist.c linkedlist.h
#	gcc -c linkedlist.c
#main.o: main.c linkedlist.h
#	gcc -c main.c
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

list: linkedlist.o main.o 
	${CC} -o list main.o linkedlist.o
main.o: main.c linkedlist.h
	${CC} ${CFLAGS} main.c
linkedlist.o: linkedlist.c linkedlist.h
	${CC} ${CFLAGS} linkedlist.c
clean:
	rm -f *.o *_
