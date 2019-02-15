CFLAGS = -Wall -std=c11 -g -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1
all:
	gcc -o CTypes CTypes.c $(CFLAGS)

clean:
	-rm -rf CTypes
