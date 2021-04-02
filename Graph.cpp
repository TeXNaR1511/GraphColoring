#include "Graph.h"
#include <algorithm>
Graph::Graph(int a, int b)
{
	ver = a;
	ed = b;
	V = nullptr;
}

Graph::Graph(int a, int b, Vertex* TV)
{
	ver = a;
	ed = b;
	V = TV;
}

void Graph::getAdjList(int a, int b)
{
	adjl[0].push_back(a);
	adjl[1].push_back(b);
}

void Graph::coutAdjList()
{
	cout << "adjacency list" << endl;
	for (int j = 0; j < ed; j++)
	{
		cout << adjl[0][j] << " " << adjl[1][j] << endl;
	}
}

bool Graph::checkEdgeExist(int a, int b)
{
	bool c = false;
	for (int i = 0; i < adjl[0].size(); i++)
	{
		if ((adjl[0][i] == a && adjl[1][i] == b) || (adjl[0][i] == b && adjl[1][i] == a))
		{
			c = true;
			break;
		}
	}
	return c;
}

void Graph::coutVerEd()
{
	cout << "ver ed" << endl;
	cout << ver << " " << ed << endl;
}

void Graph::countDegrees()
{
	int k = 0;
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < ver; j++)
		{
			if (checkEdgeExist(i, j)==true && i!=j)
			{
				k++;
			}
		}
		verdegrees.push_back(k);
		k = 0;
	}
}

void Graph::coutVerDegrees()
{
	cout << "vertex degrees" << endl;
	for (int i = 0; i < verdegrees.size(); i++)
	{
		cout << verdegrees[i] << " ";
	}
	cout << endl;
}

void Graph::coutVerdegreesSize()
{
	cout << "vd size" << endl;
	cout << verdegrees.size() << endl;
}

void Graph::getSortedvd()
{
	for (int i = 0; i < verdegrees.size(); i++)
	{
		sortedvd.push_back({ verdegrees[i],i });
	}
}

void Graph::coutSortedvd()
{
	cout << "sorted vd" << endl;
	for (int i = 0; i < sortedvd.size(); i++)
	{
		cout << sortedvd[i][0] << " " << sortedvd[i][1] << endl;
	}
}

void Graph::sortVerdegrees()
{
	sort(sortedvd.begin(), sortedvd.end(), [](const vector<int>& a, const vector<int>& b)
		{
			return a[0] > b[0];
		});
}

void Graph::callGetColors()
{
	V->getColors();
}

void Graph::callCoutColors()
{
	V->coutColors();
}

bool Graph::callIsntColoring()
{
	return V->isntColoring();
}

void Graph::findMaxNonCol()
{	
	for (int i = 0; i < sortedvd.size(); i++)
	{
		if (V->verIsntColored(sortedvd[i][1]))
		{
			V->coloringVer(sortedvd[i][1], k);
			break;
		}
	}
}

void Graph::increaseK()
{
	k++;
}

bool Graph::isTieWithSameCol(int a, vector<int> b)
{
	bool c = false;
	for (int i = 0; i < b.size(); i++)
	{
		if (checkEdgeExist(a, b[i]))
		{
			c = true;
			break;
		}
	}
	return c;
}

void Graph::coutNumCol()
{
	cout << "number of colors" << endl;
	cout << k-1 << endl;
}

void Graph::findOtherNonTieVer()
{
	for (int i = 0; i < sortedvd.size(); i++)
	{
		if (V->verIsntColored(sortedvd[i][1]) && !isTieWithSameCol(sortedvd[i][1],V->returnIterWithKCol(k)))
		{
			V->coloringVer(sortedvd[i][1], k);
		}
	}
}


