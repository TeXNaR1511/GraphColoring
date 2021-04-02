all: grcol

grcol: main.o Algorithm.o Graph.o Vertex.o
	g++ main.o Algorithm.o Graph.o Vertex.o -o grcol

main.o: main.cpp
	g++ -c main.cpp

Algorithm.o: Algorithm.cpp Algorithm.h
	g++ -c Algorithm.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Vertex.o: Vertex.cpp Vertex.h
	g++ -c Vertex.cpp

clean:
	rm -rf *.o grcol
