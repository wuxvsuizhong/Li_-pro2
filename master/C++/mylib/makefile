CC=g++

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

EXEC=myapp

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -lmylib 
.cpp.o:
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS)
