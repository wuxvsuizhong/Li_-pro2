CFLAGS= -g -W -fexec-charset=GBK -lwsock32

ifndef $(src)
	src = (patsubst %*.c)
endif
obj=$(patsubst %.c,%.o,${src})
targets=$(patsubst %.o,%.exe,$(obj))

target:all $(targets)


all:
	@echo "src=${obj} $(OS)"


%.o:%.c
	gcc -c $^ $(CFLAGS) -o $@

%.exe:%.o
	gcc $^ $(CFLAGS) -o $@

.PHOEY: clean
clean:
	-$(RM) *.exe