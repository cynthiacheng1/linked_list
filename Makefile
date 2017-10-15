all: node.c
	gcc -o all node.c

clean:
	rm *.o

run: all
	./node
