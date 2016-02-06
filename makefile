CXX = g++

CPPFLAGS = -std=c++11 -Wall -Wextra \
           -Wno-sign-compare -Werror=return-type

ifeq ($(CXX),g32)
	CPPFLAGS -= -std=c++11 -Wall -Wextra
	CPPFLAGS -= -Wno-sign-compare -Werror=return-type
endif


all : stack queue eval


stack : test_maze.o mazestack.o
	$(CXX) $(CPPFLAGS) -o stack.out test_maze.o mazestack.o


queue : test_maze.o mazequeue.o
	$(CXX) $(CPPFLAGS) -o queue.out test_maze.o mazequeue.o


eval : test_eval.o eval.o Map.o
	$(CXX) $(CPPFLAGS) -o eval.out test_eval.o eval.o Map.o


clean :
	rm -f *.o *.out


mazestack.o : mazestack.cpp
	$(CXX) $(CPPFLAGS) -c mazestack.cpp

mazequeue.o : mazequeue.cpp
	$(CXX) $(CPPFLAGS) -c mazequeue.cpp

eval.o : eval.cpp Map.h
	$(CXX) $(CPPFLAGS) -c eval.cpp

Map.o : Map.cpp Map.h
	$(CXX) $(CPPFLAGS) -c Map.cpp

test_maze.o : test_maze.cpp
	$(CXX) $(CPPFLAGS) -c test_maze.cpp

test_eval.o : test_eval.cpp Map.h
	$(CXX) $(CPPFLAGS) -c test_eval.cpp
