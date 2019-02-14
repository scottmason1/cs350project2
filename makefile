Q=prog2tree

CFLAGS= -Wall -g

all: $(Q)

$(Q): $(Q).o $(R)
	gcc $(CFLAGS) -o $(Q) $(Q).o

$(Q).o: $(Q).c
	gcc $(CFLAGS) -o $(Q).o -c $(Q).c

run: all
	./$(Q)

checkmem: all
	valgrind --leak-check=full ./$(Q) -i myfile.txt -n 5

clean:
	rm -rf *.o
	rm -rf $(Q)
	rm -rf *~
	rm -rf *.c~
	rm -rf *.h~
