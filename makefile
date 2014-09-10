CC = gcc
COPTS = -g -O1 -Wall

arrayList: main.o arrayList.o

arrayList.o: arrayList.h

main.o: arrayList.o

clean:
	rm -f*.o
