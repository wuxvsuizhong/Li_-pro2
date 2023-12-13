CFLAGS= --std=c++11 -g -W -fexec-charset=GBK
RM = rm -f
ifeq ($(OS),Windows_NT)
	RM = del /f
endif

ifndef $(src)
	src = (patsubst %*.cpp)
endif
obj=$(patsubst %.cpp,%.o,${src})
targets=$(patsubst %.o,%.exe,$(obj))

target:all $(targets)


all:
	@echo "src=${obj} $(OS)"


%.o:%.cpp
	g++ -c $^ $(CFLAGS) -o $@

%.exe:%.o
	g++ $^ $(CFLAGS) -o $@

.PHOEY: clean
clean:
	$(RM) *.exe
