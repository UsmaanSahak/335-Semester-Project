#include "set.h"

namespace UsmaanSahak {


	set* dSet::findSet(set* s) {
		set* temp = s;
		while (temp->vertex != temp->parent->vertex) {
			//iterate up tree.
			temp = temp->parent;
		}
		return temp;
	}

	set* dSet::findSet(const char& v) {
		set* temp = nullptr;
		//Find the node being referenced.
		for (int i = 0; i < sets.size(); i++) {
			if (sets[i]->vertex == v) {
				temp = sets[i];
			}
		}
			//If found, then find the set the node is in. Else return np.
		if (temp != nullptr) {
			temp = findSet(temp);
		}
		else {
			cout << "set for " << v << " not found!\n";
		}
		return temp;
	}
	/*
	set* dSet::findSet(const int v) {
		set* temp = nullptr;
		for (int i = 0; i < sets.size(); i++) {
			if (sets[i]->vertex == v) {
				temp = sets[i];
			}
		}
		if (temp != nullptr) {
			temp =findSet(temp);
		}
		return temp;
	}
	*/
	
	set* dSet::makeSet(const char& v) {
		//make set
		//set the set's parent to itself.
		//put set into dSet vector, sets.
		set* temp = new set();
		temp->vertex = v;
		temp->parent = temp;
		sets.push_back(temp);
		return temp;
	}
	/*
	set* dSet::makeSet(const int v) {
		set* temp = new set();
		temp->vertex = '0' + v;
		cout << temp->vertex << " is temp's vertex.\n";
		temp->parent = temp;
		sets.push_back(temp);
		cout << "returning set* from an int\n";
		return temp;
	}
	*/
	
	void dSet::unionSet(set* a, set* b) {
		/*
		1 - Check if root != b.root; distinct?
		2 - if rank == b.rank? root parent b.root, rank++.
		3 - if rank < b.rank? root parent b.root : b.root parent root
		4 - if b.root is parent, root = b.root and rank = b.rank.
		5 - delete b; not needed anymore. *this will be unioned set.
		*/
		set* aRoot = findSet(a);
		set* bRoot = findSet(b);
		if (aRoot->vertex == bRoot->vertex) {
			std::cout << aRoot->vertex << " " << bRoot->vertex << " NOT DISTINCT.\n";
			exit(1);
		}
		if (aRoot->rank == bRoot->rank) { 
			bRoot->parent = aRoot;
			aRoot->rank = aRoot->rank + 1;
		}
		else if (aRoot->rank > bRoot->rank) {
			bRoot->parent = aRoot;
		}
		else if (aRoot->rank < bRoot->rank) {
			aRoot->parent = bRoot;
		}
	}
}

/*
using namespace UsmaanSahak;
int main() {

	dSet e;
	set* s0 = e.makeSet('a');
	
	set* s1 = e.makeSet('b');
	set* s2 = e.makeSet('c');
	
	e.unionSet(s0,s1);
	e.unionSet(s0,s2);
	cout << e.findSet(s1)->vertex << " is e's set.\n";
	//cout << e.rep->vertex << "\n";
	for (int i = 0; i < e.sets.size(); i++) {
		cout << e.sets[i]->vertex << " 's parent is " << e.sets[i]->parent->vertex << std::endl;
	}
	
	cout << "\n";
	std::cout << "test\n";
}
*/






//Implement Christofide's algoritim using Kruskal's method of finding the MST.

/* Kruskal's Algorithm
1 - Make each vertex to its own set (in the disjoint sets obj)
2 - Order edges from smallest weight to largest. 
3 - Iterate through edges.
 a - if vertices of edge not same set, union them.
 b - add the edge to a vector that we will return, A.
4 - By now, all vertices should be in the same set, and A will contain the minimum spanning tree. O(ElogE)
*/

/* Christofide's algorithm
1 - Create MST (above)
2 - Get all vertices in MST with odd degree, O
3 - Match O with minimum perfect matching, or edges that don't share vertices.
4 - Take edges created above and fuse with MST, making all vertices with even degree.
5 - Starting from set rep, choose an edge in A that has current vertex add that edge to vector B. The other vertex of that edge becomes new current vertex. 
6 - Now look for another edge that connects to a vertex that was not already used. Keep going until you get every vertex in set.
7 - Connect the last vertex you are on to the rep vertex. 
*/

/*
Make set object.
set.makeSet('a') creates a setNode with itself as its parent.
set.unionSet('a','b') finds the nodes and unions them to one group.
set.findSet('a') returns the 'root' to the node corresponding to a.
*/
