parser: parse.o
	gcc parse.o -o parser

parse.o: parse.c
	gcc -c parse.c

run: parser
	./parser

clean:
	rm *o
