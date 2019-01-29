all:
	gcc -o CTypes CTypes.c -Wall -std=c11 -g

clean:
	-rm -rf CTypes
