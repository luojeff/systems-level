linked_list: list.o main.o
	gcc -o $@ $^

list.o: list.c list.h
	gcc -c $<

main.o: main.c list.h
	gcc -c $<

run: linked_list
	./$<

clean:
	rm *.o;
