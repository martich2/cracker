CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -pedantic-errors

TARGET = main
SOURCE = ${TARGET}.c
INCLUDE = cracker.o

default: compile

compile: ${INCLUDE} ${SOURCE} 
	${CC} ${CFLAGS} ${SOURCE} cracker.o -o ${TARGET}

cracker.o: cracker.c cracker.h
	gcc -c -o cracker.o cracker.c $(CflAGS)

debug: ${SOURCE} ${INCLUDE}
	${CC} ${CFLAGS} ${SOURCE} -g -D DEBUG -o ${TARGET}

clean:
	rm *.o ${TARGET}
