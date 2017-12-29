make: Dict_client.o dictionary.o scanner.o
	gcc -o client Dict_client.o dictionary.o scanner.o

#client: Dict_client.c dictionary.c scanner.c
#	gcc -o client Dict_client.c dictionary.c scanner.c

Dict_client.o: Dict_client.c dictionary.h scanner.h
	gcc -c -Wall Dict_client.c 

dictionary.o: dictionary.c dictionary.h
	gcc -c -Wall dictionary.c

scanner.o: scanner.c scanner.h
	gcc -c -Wall scanner.c

clean:
	rm client Dict_client.o dictionary.o scanner.o
