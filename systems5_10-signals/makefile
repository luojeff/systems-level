sig_run: signals.o
	@gcc signals.o -o sig_run

signals.o: signals.c
	@gcc -c signals.c

run: sig_run
	@./sig_run

clean:
	@rm *.o
