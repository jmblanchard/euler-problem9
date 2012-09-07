CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic

euler9.o: euler9.cpp
	$(CC) $(CFLAGS) -o euler9.o euler9.cpp

clean:
	rm -f *.o
