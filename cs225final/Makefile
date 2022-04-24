LD = clang++
CXX = clang++
INCLUDES = -Igraph.h
CXXEXTRAS = -Wall -Werror -pedantic
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
CXXFLAGS2=-std=c++2a -g -fstandalone-debug
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

exec: final
#tests: bin/tests

final: graph.cpp main.cpp
	$(CXX) $(CXXFLAGS2) $(CXXEXTRAS) $(INCLUDES) $^ -o $@

test: catchmain.o tests.o
	$(LD) catchmain.o tests.o $(LDFLAGS) -o test

catchmain.o : catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

tests.o : tests.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) tests.cpp

final.o : 

.DEFAULT_GOAL := final
.PHONY: clean final tests

clean:rm -rf *.o *.d rm -f final rm -f test


