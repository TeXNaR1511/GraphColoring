#pragma once
#include <vector>
#include "Graph.h"
using namespace std;
class Algorithm
{
private:
	Graph* G;
public:
	Algorithm();
	Algorithm(Graph* TG);
	void graphColoring();
};

