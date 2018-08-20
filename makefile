CXX = clang++
OBJS = test_deque.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o deque

clean:
	-rm -f *.o core *.core
