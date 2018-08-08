EXEC = semaphore

$(EXEC): main.o
	@gcc main.o -o $(EXEC)

run: $(EXEC)
	./$(EXEC) -c 31415
	./$(EXEC) -v
	ipcs -s
	./$(EXEC) -c 100
	./$(EXEC) -v
	./$(EXEC) -r

clean:
	@rm *o
