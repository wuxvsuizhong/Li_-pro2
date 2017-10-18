COMPILE=g++ -std=c++11
libs=pthread

TARGET=client

src=$(wildcard *.cpp)
obj=$(patsubst %.cpp,%.o,$(src))


$(TARGET):$(obj)
	$(COMPILE) $^ -o $@ -l$(libs)

%.o:%.cpp
	$(COMPILE) -c $< -o  $@
	

.PHONY:clean
clean:
	rm -f *.o
	rm -f $(TARGET) 
