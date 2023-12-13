CFLAGS= -g -W -fexec-charset=GBK -lwsock32
INCLUDE = -I../common/message


CUR_DIR=$(CURDIR)

src=$(wildcard ${CUR_DIR}/*.c)
obj=$(patsubst %.c,%.o,$(src))

# all:
# 	@echo ${obj}

all=server.exe
${all}:${obj}
	gcc $^ $(CFLAGS) -o $@

%.o:%.c
	gcc $^ -c $(CFLAGS) $(INCLUDE) -o $@


.PHOEY: clean
clean:
	del *.exe *.o

