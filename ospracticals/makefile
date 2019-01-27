CC = gcc
FLAGS = -static

all : MYCAT

MYCAT : mycat.o filecopy.o
	$(CC) ($FLAGS) -o MYCAT mycat.o filecopy.o

mycat.o : mycat.c
	$(CC) ($FLAGS) -c mycat.c

filecopy.o : filecopy.c
	$(CC) ($FLAGS) -c filecopy.c

clean :
	rm *.o
