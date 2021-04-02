#pragma once
#include <iostream>
#include <vector>
#include "Vertex.h"
using namespace std;
class Graph
{
private:
	Vertex* V;
	int ver;
	int ed;
	vector<vector<int>> adjl = { {},{} };
	vector<int> verdegrees;
	vector<vector<int>> sortedvd;
	int k = 1;
public:
	Graph(int a, int b);
	Graph(int a, int b, Vertex* TV);
	void getAdjList(int a, int b);
	void coutAdjList();
	bool checkEdgeExist(int a, int b);
	void coutVerEd();
	void countDegrees();
	void coutVerDegrees();
	void coutVerdegreesSize();
	void getSortedvd();
	void coutSortedvd();
	void sortVerdegrees();
	void callGetColors();
	void callCoutColors();
	bool callIsntColoring();
	void findMaxNonCol();
	void increaseK();
	void findOtherNonTieVer();
	bool isTieWithSameCol(int a, vector<int>b);
	void coutNumCol();
};

