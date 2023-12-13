CFLAGS= -g -W -std=c++11 -fexec-charset=GBK
RM = rm -f
ifeq ($(OS),Windows_NT)
	RM = del /f
endif

ifeq (, $(shell which rm))
	$(info "no rm command in current env")
else
	RM = rm -f
endif



ifndef $(src)
	src = (patsubst %*.cpp)
endif
obj=$(patsubst %.cpp,%.o,${src})
targets=$(patsubst %.o,%.exe,$(obj))

target:all $(targets)


all:
	@echo "src=${obj} $(OS)"


%.o:%.c
	g++ -c $^ $(CFLAGS) -o $@

%.exe:%.o
	g++ $^ $(CFLAGS) -o $@

.PHOEY: clean
clean:
	-$(RM) *.exe
