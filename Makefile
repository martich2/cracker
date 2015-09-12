CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -pedantic-errors
LDFLAGS =

TARGET = cracker
SOURCE = ${TARGET}.c
INCLUDE =

default: compile

compile: ${SOURCE} ${INCLUDE}
	${CC} ${CFLAGS} ${SOURCE} -o ${TARGET}

debug: ${SOURCE} ${INCLUDE}
	${CC} ${CFLAGS} ${SOURCE} -g -D DEBUG -o ${TARGET}

clean:
	rm ${TARGET}.o ${TARGET}
