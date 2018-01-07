#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
namespace UsmaanSahak {
  class node {
    public:
      node(int64_t v) : value(v), right(nullptr), left(nullptr) {}
      node* getRight() { return right; }
      node* getLeft() { return left; }
      void setRight(node* r) { right = r; }
      void setLeft(node* l) { left = l; }
      int64_t getValue() { return value; }
      void setValue(int64_t v) { value = v; }
      ~node() { delete right; delete left; right = nullptr; left = nullptr; }
      int height;
    private:
      int64_t value;
      node* right;
      node* left;
    };
}





#endif
