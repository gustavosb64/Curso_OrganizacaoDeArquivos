all:
	gcc -g -Wall -Wpedantic -o main main.c

c:
	gcc -g -o main main.c

run:
	./main

debug:
	valgrind --leak-check=full --show-leak-kinds=all ./main
