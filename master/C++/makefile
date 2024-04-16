#禁止优化移动构造函数 -fno-elide-constructors
#编译器优化级别 -O0
CFLAGS= --std=c++17 -g -fexec-charset=GBK -O0
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
	@echo "src=${src}"


%.o:%.cpp
	g++ -c $^ $(CFLAGS) -o $@

%.exe:%.o
	g++ $^ $(CFLAGS) -o $@

.PHOEY: clean
clean:
	$(RM) *.exe *.o
