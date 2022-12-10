ifndef $(src)
	src = $(wildcard *.c)
endif

ifeq ($(DEBUG),1)
	CFLAGS = -W -g -fexec-charset=GBK
else
	CFLAGS = -W -fexec-charset=GBK
endif

targets = $(patsubst %.c,%.exe,$(src))

target:$(targets)


%.exe:%.c
	gcc $^ $(CFLAGS)  -o $@

.PHONY:clean
clean:
	-del /f *.exe