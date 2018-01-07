#include "graph.h"


namespace UsmaanSahak {
	
	graph::graph(vector<char> newVertices) {
		//Now that we have all the vertices, we can cast each char vert to float
		//Once done, we get each vertex and compare to each other, using float.
		//We fill the edge using v1 and v2 and calculated weight.
		//Finally, push back to the "edges" vector for graph object.
		vertices = newVertices;
	}
	vector<edge> quickSortEdges(vector<edge> e) {
		if (e.size() <= 1) {
			return e;
		}
		int front = 0; int back = e.size(); int pivot = e.size()/2;
		
		while ((e[front].weight < e[pivot].weight) && (front+1 != back)) {
			front++;
		}
		while ((e[back].weight > e[pivot].weight) && (front+1 != back)) {
			back--;
		}
		if ((e[front].weight > e[pivot].weight) && (e[back].weight < e[pivot].weight)) {
			edge temp = e[front];
			e[front] = e[back];
			e[back] = temp;
		}
		vector<edge> first; vector<edge> second;
		for (int i=0; i < front; i++) {
			first.push_back(e[i]);
		}
		for (int i=back; i < e.size(); i++) {
			second.push_back(e[i]);
		}
		vector<edge> newFirst = quickSortEdges(first);
		vector<edge> newSecond = quickSortEdges(second);
		for (int i = 0; i < newSecond.size(); i++) {
			newFirst.push_back(newSecond[i]);
		}
		return newFirst;
	}
	
	
			
	vector<edge> graph::getMST() {
		vector<edge> mst;
		dSet disjoint;
		for (int i = 0; i < vertices.size(); i++) {
			//Make each vertex a set;
			disjoint.makeSet(vertices[i]); //Now in disjoint's vector.
		}

		for (int i = 0; i < edges.size(); i++) { //edges is sorted.
			if (disjoint.findSet('0'+edges[i].v1)->vertex != disjoint.findSet('0'+edges[i].v2)->vertex) {
				//cout << edges[i].v1 << "-" << edges[i].v2 << " mst pushback\n";
				mst.push_back(edges[i]);
				disjoint.unionSet(disjoint.findSet('0'+edges[i].v1),disjoint.findSet('0'+edges[i].v2));
				
				//cout << disjoint.findSet(edges[i].v1)->vertex << endl;
			}
			else {
				//cout << edges[i].v1 << " was rejected!\n";
			}
		}
		return mst;
	}
	
	/*
	Iterates through mst edges and finds the degrees of each vertex.
	*/
	vector<int> graph::getDegrees(vector<edge> mst) {
		vector<int> degrees;
		for (int i = 0; i <  mst.size(); i++) {
			for (int j = 0; j < vertices.size(); j++) {
				if (mst[i].v1 == vertices[j] || mst[i].v2 == vertices[j]) {
					degrees[j]++;
				}
			}
		}
		return degrees;
	}
	vector<edge> graph::minPerfectMatching(vector<char> oddVert) {
		//Find all the edges that connect each vertex to eachother, and push onto tempEdges, which also has edges elements.
		vector<edge> subGraph;
		for (int i=0; i < oddVert.size(); i++) {
			for (int j=0; j < oddVert.size(); j++) {
				int found = 0; int k = 0;
				while (found < edges.size()) {
					if ((edges[k].v1 == oddVert[i] && edges[k].v2 == oddVert[j]) || (edges[k].v1 == oddVert[j] && edges[k].v2 == oddVert[i])) {
						subGraph.push_back(edges[k]);
						found = edges.size();
					}
					found++;
				}
			}
		}//Subgraph should have graph of connected odd vertices.
		vector<edge> orderedGraph = quickSortEdges(subGraph);
		dSet oddSet;
		for (int i=0; i < oddVert.size(); i++) {
			oddSet.makeSet(oddVert[i]);
		}
		vector<edge> perfect;
		for (int i=0; i < orderedGraph.size(); i++) {
			if (oddSet.findSet(orderedGraph[i].v1) != oddSet.findSet(orderedGraph[i].v2)) {
				perfect.push_back(orderedGraph[i]);
				oddSet.unionSet(oddSet.findSet(orderedGraph[i].v1),oddSet.findSet(orderedGraph[i].v2));
			}
		}
		return perfect;
	}
		
					
		
		
		
		//Now lets only keep the ones that are perfect Matching.
		
		//Lets order tempEdges.
		//Add the minimum to the mpm, and add the two vertices to set.
		//Go to second minimum; if both vert not in set, add that to mpm as well, adding those two vertices to set.
		//Keep going until all vertices have been matched.(Assumed that all degrees are even from step 1.)
		
		//Now add these mpm to tempEdges2, which is edges + mpm.
		//Return tempEdges2.
	
	
	
	
	vector<edge> graph::christofideMAGIC() {
		vector<edge> mst = getMST();
		/*
		for (int i=0; i < mst.size(); i++) {
			cout << mst[i].v1 << "-" << mst[i].v2 << endl;
		}
		*/
		//Could not reliably finish, decided to debug Krustal's MST and finish at that.
/*
		cout << "mst\n";
		for (int i = 0; i < mst.size(); i++) {
		cout << mst[i].v1 << " " << mst[i].v2 << ", ";
	}
*/		
		/*
		vector<int> degrees = getDegrees(mst); //Fills degrees vector.
		vector<char> oddVertices;
		for (int i=0; i < degrees.size(); i++) { //assumed size=vertsiz
			if (degrees[i] % 2 == 1) {
				oddVertices.push_back(vertices[i]);
			}
		}
		vector<edge> nowEven = minPerfectMatching(oddVertices);
		for(int i = 0; i < mst.size(); i++) {
			nowEven.push_back(mst[i]);
		}
		vector<edge> multigraph = quickSortEdges(nowEven);
		
		//Finally, just iterate through multigraph, removing doubles via sets.
		dSet removeDoubles; vector<edge> output;
		for (int i = 0; i < vertices.size(); i++) {
			removeDoubles.makeSet(vertices[i]);
		}
		for (int i = 0; i < multigraph.size(); i++) {
			if (removeDoubles.findSet(multigraph[i].v1) != removeDoubles.findSet(multigraph[i].v2)) {
				output.push_back(multigraph[i]);
			}
		}
		return output;
		*/
		return mst;
	}
}

