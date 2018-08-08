prog: pipes.o
	@gcc $^ -o $@

pipes.o: pipes.c
	@gcc -c $<

run: prog
	@./$<

clean:
	@rm *.o
