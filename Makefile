CC = gcc
CFLAGS = -std=c99 -Wall -g

OBJECTS = lib_beale.o lib_utils.o lib_list.o

all: beale

beale: $(OBJECTS)

lib_beale.o: lib_beale.c lib_beale.h lib_utils.h lib_list.h
 
lib_utils.o: lib_utils.c lib_utils.h

lib_list.o: lib_list.c lib_list.h

clean:
	rm -f *.o beale

purge: clean
	rm -f *~