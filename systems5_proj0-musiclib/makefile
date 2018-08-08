linked_list: list.o main.o
	@gcc -o $@ $^

list.o: list.c list.h
	@gcc -c $<

main.o: main.c list.h
	@gcc -c $<

linked_list_debug: list_debug.o main_debug.o
	@gcc -o $@ $^

list_debug.o: list.c list.h
	@gcc -g -c $< -o $@

main_debug.o: main.c list.h
	@gcc -g -c $< -o $@

debug: linked_list_debug
	@valgrind --track-origins=yes --leak-check=yes ./$<

debug-gdb: linked_list_debug
	@gdb ./$<

run: linked_list
	@clear
	@./$<

clean:
	@rm *.o

debug-clean:
	@rm linked_list_debug
	@rm list_debug.o
	@rm main_debug.o
