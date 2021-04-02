#include "Algorithm.h"
Algorithm::Algorithm()
{
	G = nullptr;
}

Algorithm::Algorithm(Graph* TG)
{
	G = TG;
}

void Algorithm::graphColoring()
{
	//G->coutVerEd();
	//G->coutAdjList();
	G->countDegrees();
	//G->coutVerdegreesSize();
	//G->coutVerDegrees();
	G->getSortedvd();
	//G->coutSortedvd();
	G->sortVerdegrees();
	//G->coutSortedvd();
	G->callGetColors();
	//G->callCoutColors();
	while (G->callIsntColoring())
	{
		G->findMaxNonCol();
		G->findOtherNonTieVer();
		//G->callCoutColors();
		G->increaseK();
	}
	G->coutNumCol();
	G->callCoutColors();
}