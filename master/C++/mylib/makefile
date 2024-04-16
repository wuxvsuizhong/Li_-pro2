CC=g++

RM=rm -f
ifeq ($(OS),Windows_NT)
	RM=del /f
endif

SRCS=main.cpp

# OBJS = $(SRCS:.cpp=.o)  # 再把剩下的.cpp替换成.o
OBJS=$(patsubst %.cpp,%.o,${SRCS})

EXEC=myapp.exe

start: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)  -L. -lmylib 
.o: .cpp
	$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
