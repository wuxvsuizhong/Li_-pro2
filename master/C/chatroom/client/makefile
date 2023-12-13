CFLAGS= -g -W -fexec-charset=GBK -lwsock32
lib=../common/message

INCLUDE = -I${lib}
CUR_DIR=$(CURDIR)

libsrc=$(wildcard ${lib}/*.c)
src=$(wildcard ${CUR_DIR}/*.c)
src+=${libsrc}
obj=$(patsubst %.c,%.o,$(src))

# all:
# 	@echo ${src}

all=client.exe
${all}:${obj}
	gcc $^ $(CFLAGS) -o $@

%.o:%.c
	gcc $^ -c $(CFLAGS) $(INCLUDE) -o $@


.PHOEY: clean
clean:
	del *.exe ${obj}

