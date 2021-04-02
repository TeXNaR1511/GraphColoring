#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Algorithm.h"
#include "Vertex.h"
using namespace std;
int main()
{
	int a, b;
	ifstream in("gc_4_1.txt");//test file name
	in >> a >> b;
	Vertex v(a);
	Graph g(a, b, &v);
	if (in.is_open())
	{
		while (in >> a >> b)
		{
			g.getAdjList(a, b);
		}
	}
	in.close();
	Algorithm al(&g);
	al.graphColoring();
	return 0;
}
