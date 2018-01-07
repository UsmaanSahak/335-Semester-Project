#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"
#include <vector>
using namespace std;

namespace UsmaanSahak {

	struct edgeChar {
		char v1;
		char v2;
		int weight;
	};
	struct edge {
		int v1;
		int v2;
		float weight;
	};
	class graph {
		public:
			graph() {};
			//vector<edge> quickSortEdges(vector<edge> e);
			graph(vector<char> newVertices);
			vector<edge> getMST();
			vector<edge> minPerfectMatching(vector<char> oddVertices);
			vector<int> getDegrees(vector<edge> mst); 
			vector<edge> christofideMAGIC();
		//private:
			vector<char> vertices; //When operating, turn to sets.
			vector<edge> edges; //Lightest first, heaviest last.
	};
	
	
	
}















#endif
