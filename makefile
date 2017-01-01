
FLAGS = -g -Wall -std=c++11

all:	driver

driver:	UnionFind.o driver.o
	g++ $(FLAGS) UnionFind.o driver.o -o driver
driver.o:	driver.cpp
	g++ $(FLAGS) -c driver.cpp -o driver.o	
UnionFind.o:
	g++ $(FLAGS) -c UnionFind.cpp -o UnionFind.o

clean:
	rm -f *.o driver
