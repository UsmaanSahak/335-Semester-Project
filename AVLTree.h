#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.h"

namespace UsmaanSahak {

   class AVLTree {
    public:
      AVLTree() : root(nullptr), size(0), capacity(0) {}
      AVLTree(int c) : root(nullptr), size(0), capacity(c) {}
      node* getRoot() { return root; }
      void setRoot(node* n) { root = n; }
      bool readTree(int64_t num);
      bool writeTree(int64_t num);
      bool deleteTree(int64_t num);
      void outputTree();
      void helperOutputTree(node* subtree);
      void outputTree(std::ofstream& file);
      void helperOutputTree(node* subtree, std::ofstream& file);
      void reinsert(node* subtree);
      int getSize() { return size; }
      void setSize(int newSize) { size = newSize; }
      int getCapacity();
      void setCapacity(int newCapacity) { capacity = newCapacity; }
      void raiseHeight(node* subtree);
      void lowerHeight(node* subtree);
      void iterate(node* s); //debugging
      int gsh();
      int gshRoot(node* s);
      int gsh(node* witness, node* s);
      void rightRotationRoot(node* oldRoot, node* prevNode, node* subtree);
      void leftRotationRoot(node* oldRoot, node* prevNode, node* subtree);
      void leftRightRotationRoot(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      void rightLeftRotationRoot(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      void rightRotation(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      void leftRotation(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      void leftRightRotation(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      void rightLeftRotation(int dir, node* witness, node* prevNode, node* subtree, node* subchild);
      int totalHeight;
      ~AVLTree();
    private: 
      node* root;
      int size;
      int capacity;
      
      bool helperReadTree(int64_t num, node* subtree);
      bool helperWriteTree(int64_t num, node* prevNode, node* subtree);
      bool helperWriteTree(int64_t num, node* witness, node* prevNode, node* subtree);
      bool helperDeleteTree(int64_t num, node* subtree);
  };











}








#endif
