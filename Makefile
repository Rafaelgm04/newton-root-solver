CC = gcc
CFLAGS = -Wall -Wextra -g

programa:
	$(CC) $(CFLAGS) main.c Newton.c -lm -o programa

clean:
	rm -f *.o programa