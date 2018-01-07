#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::string;

namespace UsmaanSahak {
	class setChar {
		public:
			setChar() : rank(0), vertex('$'), parent(nullptr) {}
			int rank;
			int vertex;
			setChar* parent;
		//private:
	};
	class set {
		public:
			set(): rank(0), vertex(0), parent(nullptr) {}
			int rank;
			char vertex;
			set* parent;
		};
		
		
	
	class dSet {
		public:
			set* makeSet(const char& v);
			set* makeSet(const int v);
			void unionSet(set* a, set* b);
			set* findSet(set* s);
			set* findSet(const char& v);
			//set* findSet(const int v);
			//void outputSet;
		
		//private:
			vector<set*> sets;
		
		
	};
}
	
	
	
	
	/* Set
	each set obj would basically be nodes to a tree. 
	each set obj will have a pointer to its parent.
	each set obj will have pointer to repV, initialized at union.
	each set obj will have a rank, initialized at union.
	*/
	
	/*
	makeSet //make set with only 1 element
	Union //Take two different sets and merge them into one.
	findSet //Get rep of set
	
	Call makeSet on each element
	Each element of set has a pointer to the rep element.
	*/


#endif
