GCC = gcc
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})


all:*.o main

main: ${BINAIRES}
	${GCC} $^ -o $@

%.o: %.c %.h
	${GCC} -c $<
	
clean:
	rm main
	rm *.o
