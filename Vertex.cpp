#include "Vertex.h"
#include <iostream>
using namespace std;
Vertex::Vertex(int a)
{
	vercol = a;
}

void Vertex::getColors()
{
	for (int i = 0; i < vercol; i++)
	{
		colors.push_back(0);
	}
}

void Vertex::coutColors()
{
	//cout << "colors size" << endl;
	//cout << colors.size() << endl;
	cout << "graph coloring" << endl;
	for (int i = 0; i < colors.size(); i++)
	{
		cout << colors[i] << " ";
	}
	cout << endl;
}

bool Vertex::isntColoring()
{
	return any_of(colors.begin(), colors.end(), [](int i)
		{
			return i == 0;
		});
}

bool Vertex::verIsntColored(int a)
{
	bool c = true;
	if (colors[a] > 0)
	{
		c = false;
	}
	return c;
}

void Vertex::coloringVer(int a, int k)
{
	colors[a] = k;
}

vector<int> Vertex::returnIterWithKCol(int k)
{
	vector<int> c;
	for (int i = 0; i < colors.size(); i++)
	{
		if (colors[i] == k)
		{
			c.push_back(i);
		}
	}
	return c;
}
