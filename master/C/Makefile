CFLAGS= -g -W -fexec-charset=GBK
RM = rm -f
ifeq ($(OS),Windows_NT)
	RM = del /f
endif

# ifeq (, $(shell which rm))
# 	$(info "no rm command in current env")
# else
# 	RM = rm -f
# endif



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
	$(RM) *.exe
