#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Vertex
{
private:
	int vercol;
	vector <int> colors;
public:
	Vertex(int a);
	void getColors();
	void coutColors();
	bool isntColoring();
	bool verIsntColored(int a);
	void coloringVer(int a,int k);
	vector<int> returnIterWithKCol(int k);
};