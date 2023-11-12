CC = gcc
CFLAGS=
OBJS=test3.o test4.o
LIBS=
all:    add

add:    $(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)

test3.o:        test3.c
	$(CC) $(CFLAGS) -c test3.c
test4.o:        test4.c
	$(CC) $(CFLAGS) -c test4.c
clean:
	rm -f $(OBJS) add
