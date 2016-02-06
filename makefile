CXX = g++

CPPFLAGS = -std=c++11 -Wall -Wextra \
           -Wno-sign-compare -Werror=return-type

ifeq ($(CXX),g32)
	CPPFLAGS =
endif


all : landmark linear maze tree


clean :
	rm -f *.o *.out


landmark : landmark.cpp
	$(CXX) $(CPPFLAGS) -o landmark.out landmark.cpp

linear : linear.cpp test_linear.cpp
	$(CXX) $(CPPFLAGS) -o linear.out linear.cpp test_linear.cpp

maze : maze.cpp test_maze.cpp
	$(CXX) $(CPPFLAGS) -o maze.out maze.cpp test_maze.cpp

tree : tree.cpp test_tree.cpp
	$(CXX) $(CPPFLAGS) -o tree.out tree.cpp test_tree.cpp
