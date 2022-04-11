CXX=clang++
INCLUDES=-Igraph.h
CXXEXTRAS=-Wall -Werror -pedantic
CXXFLAGS=-std=c++2a -g -fstandalone-debug

exec: final
#tests: bin/tests

final: graph.cpp main.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) $^ -o $@

# bin/tests: ./tests/tests.cc obj/catch.o ./src/cord.cc ./src/cord-utilities.cc
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# obj/catch.o: tests/catch.cc
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := final
.PHONY: clean final tests

clean: rm final


