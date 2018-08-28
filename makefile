CXX = clang++
OBJS = test_deque.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o test_deque

clean:
	-rm -f *.o core *.core
