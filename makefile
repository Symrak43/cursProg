CMP = gcc
LD_LIBRARY_PATH=/home/eremin/cursProg/

all: main

main: main.o libsort.so function.o 
	$(CMP) function.o main.o -L. -lsort -o main

main.o: main.c function.c
	$(CMP) -c main.c function.c	

libsort.so: sort.o
	$(CMP) -shared -o libsort.so sort.o


sort.o: sort.c 
	$(CMP) -fPIC -c sort.c

function.o: function.c 
	$(CMP) -c function.c

clean:
	rm -rf *.o *.so main