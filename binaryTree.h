#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"
#include "Matrix.h"

namespace UsmaanSahak {

  class binaryTree {
    public:
      binaryTree() : root(nullptr), size(0), capacity(0){}
      binaryTree(int c) : root(nullptr), size(0), capacity(c) {}
      node* getRoot() { return root; }
      void setRoot(node* n) { root = n; }
      bool readTree(int64_t num);
      bool writeTree(int64_t num);
      bool deleteTree(int64_t num);
      void outputTree();
      void outputTree(std::ofstream& file);
      void helperOutputTree(node* subtree);
      void helperOutputTree(node* subtree, std::ofstream& file);
      void reinsert(node* subtree);
      int getSize() { return size; }
      void setSize(int newSize) { size = newSize; }
      int getCapacity();
      void setCapacity(int newCapacity) { capacity = newCapacity; }
      template<class T>
      void loadTree(Matrix<T> ancestor);//Fill with ancestor matrix
      template<class T>
      Matrix<T> storeTree();//Turn to ancestor matrix
      void lowerHeight(node* subtree);
      void raiseHeight(node* subtree);
      int totalHeight;
      ~binaryTree();
    private: 
      node* root;
      int size;
      int capacity;
      
      bool helperReadTree(int64_t num, node* subtree);
      bool helperWriteTree(int64_t num, node* prevNode, node* subtree);
       bool helperWriteTree(int64_t num, node* witness, node* prevNode, node* subtree);
      bool helperDeleteTree(int64_t num, node* subtree);
  };


//Should be save_tree(fname, tree) {
//	mat = tree2mat(tree)
//	writematrix(fname, mat)
//}
template<class T>
Matrix<T> binaryTree::storeTree() {
	
}
//Template it instead of int later
template<class T>
void binaryTree::loadTree(Matrix<T> ancestor) {
	//a[i][j], where if 1, i is an ancestor of j.
	//Base whether or not a node is the left or right child based off of the value
	
//# of columns = number of nodes + value
//# of rows = number of nodes
//So a tree with 12 nodes will have 13 columns, and 12 rows.

//I suppose the only thing we can do is just
//1 - look for the root, which is the one with only one 0.
//2 - Look for the two nodes that are only 1 for the root node.
//3 - Look for the two nodes that are only 1 for the 3 nodes above.
//4 - Look for the two nodes that are only 1 for above.
//5 - Keep going until you reach nodes with all 0s, and place based off of values.

	std::vector<int> nahl; //Node sat height level
	std::vector<std::vector<int>> nodes; //Vector of vectors
	for (int i = 0; i < ancestor.getNumRow(); i++) {
		int found = 0;
		for (int j = 0; j < ancestor.getNumColumn()-1; j++) {
			if (ancestor[i][j] == 1) {
				found++;
			}
		}
		if (found == i) { //leaf would have 0, root would be getNumRow-1. Both supported by the loop.
			nahl.push_back(i);
		}
		nodes.push_back(nahl);
	}
	//we should now have all of the nodes listed by height.
	
	//Create the tree:
	//create root
	root = new node(ancestor[ancestor.getNumColumn()]); //set as the value in the matrix
	//Read each vector from the nodes vector, starting from nodes.size()-1.
	
	//Iterate through nahl[nahl.size()-2] and nahl[nahl.size()-3]
	//Compare which spots nahl[nahl.size()-2] has 1 that nahl[nahl.size()-3] is 0 in.
	//For those, add node with value from ancestor matrix, left if less than parent node's value, right if more.
	//Keep going until nahl.size()-i < 0.
	
	
/*
Compare nahl[x] and nahl[x-1]
For wherever there is a 1 where it is not present in the nahl[x-1], then its index is a child.
Iterate down the GTree and find the node represented by nahl[x][y] and place a node for nahl[x-1][z]
Should keep going until we start accessing nahl[1][], as nahl[0][] are the leaves.

*/
	for (int i = 0; i < nahl.size(); i++) {
		for (int j = 0; j < nahl[nahl.size() - i]; j++) {
			for (int k = 0; k < ancestor.getNumColumn-1; k++) {
				if ((ancestor[nodes[nahl.size() - i]][k] != ancestor[nodes[nahl.size() - (i+1)]][k]) && (ancestor[nodes[nahl.size() - i]][k] == 1)) {
					//This is a child node to the currently iterated parent
					if (ancestor[k][ancestor.getNumColumn()-1] > ancestor[nahl[nahl.size()-i]][ancestor.getNumColumn()-1]) {
						//the node's right child is a new node with the value ancestor[k][ancestor.getNumRow()].
						//Iterate down tree until you get to the node with the parent value.
						node* it;
						while (it->getValue() != ancestor[nahl.size()-i][ancestor.getNumColumn()-1]) {
							if (it->getValue() > ancestor[nahl.size()-i][ancestor.getNumColumn()-1]) {
								it = it->getRight();
							} else {
								it = it->getLeft();
							}
						}
						it->setRight(new node(ancestor[k][ancestor.getNumColumn()-1]));
					} else {
						//node's left child is the value of ancestor[k][ancestor.getNumRow()].
						//Iterate down GTree until getValue() == ancestor[nahl.size()-i]][getNumRow()]]
						node* it;
						while (it->getValue() != ancestor[nahl.size()-i][ancestor.getNumColumn()-1]) {
							if (it->getValue() > ancestor[nahl.size()-i][ancestor.getNumColumn()-1]) {
								it = it->getRight();
							} else {
								it = it->getLeft();
							}
						}
						it->setLeft(new node(ancestor[k][ancestor.getNumColumn()-1]));
					}
					}}}}} //Temporary brackets for make
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	Part 1:
	Lets start from the bottom.
	Get all leaves, or rows with only 0s (except last element, which is value)
	Next, get the ones with only 1s above the above node indices.
	Next get the ones with only 1s above the two node index sets.
	Next get the ones with only 1s above the three node index sets.
	..
	...
	.....
	Finally, a 1 above all index sets, with only a single zero in its own index (Other than the value element.).
	
	Part 2:
	Now we have a bunch of vectors of indices, with each corresponding to their height.
	So lets
	*/

	






}








#endif
