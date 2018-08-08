all: ctrings.o main.o
	gcc main.o ctrings.o -o strings_test

main.o: main.c ctrings.h
	gcc -c main.c

ctrings.o: ctrings.c ctrings.h
	gcc -c ctrings.c

clean:
	rm *.o

run: all
	./strings_test
