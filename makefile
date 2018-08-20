CXX = clang++
OBJS = deque.hpp

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o deque

clean:
	-rm -f *.o core *.core
