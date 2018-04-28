CC=gcc

SRCS=mylib.c

OBJS=$(SRCS:.c=.o)

EXEC=libmylib.so

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -shared

.c.o:
	$(CC) -o $@ -c $< -fPIC

clean:
	rm -rf $(OBJS)
