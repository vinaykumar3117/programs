LIB_DIR = /home/vinay/SharedLibrary

all	: main

main	: main.c myshared.o
	gcc -g -pg -o main -L $(LIB_DIR) -lmyshared main.c

myshared.o    : myshared.c
	gcc -fPIC -g -c -Wall myshared.c
	gcc -shared -Wl,-soname,libmyshared.so.1 -o libmyshared.so.1.0 myshared.o
	ln -sf libmyshared.so.1.0 libmyshared.so.1
	ln -sf libmyshared.so.1.0 libmyshared.so

clean   : 
	rm *.o
