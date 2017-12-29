
make: maze_client.o maze.o scanner.o
	gcc -o client maze_client.o maze.o scanner.o

client: maze_client.c maze.c scanner.c
	gcc -o client maze_client.c maze.c scanner.c

maze_client.o: maze_client.c maze.h scanner.h
	gcc -c -Wall maze_client.c 

maze.o: maze.c maze.h
	gcc -c -Wall maze.c

scanner.o: scanner.c scanner.h
	gcc -c -Wall scanner.c

clean:
	rm client maze_client.o maze.o scanner.o
