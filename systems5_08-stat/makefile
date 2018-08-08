app: stat.o
	@gcc stat.o -o app

app_debug: stat_debug.o
	@gcc stat_debug.o -o app_debug

stat.o: stat.c
	@gcc -c stat.c

stat_debug.o: stat.c
	@gcc -g -c stat.c -o stat_debug.o

run: app
	@./app

clean:
	@rm *.o

debug-clean:
	@rm *.o
	@rm stat_debug.o
	@rm app_debug

debug: app_debug
	@valgrind --track-origins=yes --leak-check=yes ./$<
