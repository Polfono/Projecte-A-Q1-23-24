OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

all: main.exe

main.exe: main.o Tree.o
	g++ $(OPCIONS) -o main.exe main.o Tree.o RelaxedTree.o

main.o: main.cc
	g++ $(OPCIONS) -c main.cc

Tree.o: Tree.cc Tree.hh
	g++ $(OPCIONS) -c Tree.cc

RelaxedTree.o: RelaxedTree.cc RelaxedTree.hh
	g++ $(OPCIONS) -c RelaxedTree.cc

tar: Makefile Tree.cc Tree.hh main.cc
	tar -cvf practica.tar .cc.hh Makefile

clean: 
	rm *.o *.exe *.tar