ifndef $(src)
	src = $(wildcard *.cpp)
endif

targets = $(patsubst %.cpp,%.exe,$(src))
CFLAGS = -W -g -std=c++11 -fexec-charset=GBK

target:$(targets)
	@echo "$(targets)"

%.exe:%.cpp
	g++ $^ -o $@ $(CFLAGS)

.PHONY:clean
clean:
	-del /f *.exe