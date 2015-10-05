CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes
PFLAGS=-g -C -H -Rw

all: s1

s1: libs1.a
	gcc -o s1 main.c ./libs1.a

libs1.a: sorted-list.o
	ar -cvq libs1.a sorted-list.o

sorted-list.o:
	gcc -c sorted-list.c

clean:
	rm *.a *.o s1