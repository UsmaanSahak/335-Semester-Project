#include "binaryTree.h"



namespace UsmaanSahak {


void binaryTree::raiseHeight(node* subtree) {
		subtree->height = subtree->height+1;
	  if (subtree->getLeft() != nullptr) {
			raiseHeight(subtree->getLeft());
		}
		if (subtree->getRight() != nullptr) {
			raiseHeight(subtree->getRight());
		}
	}
	void binaryTree::lowerHeight(node* subtree) {
		subtree->height = subtree->height-1;
	  if (subtree->getLeft() != nullptr) {
			lowerHeight(subtree->getLeft());
		}
		if (subtree->getRight() != nullptr) {
			lowerHeight(subtree->getRight());
		}
	}
	
	
	
 bool binaryTree::helperDeleteTree(int64_t num, node* subtree) {
//std::cout << subtree->getValue() << "helper\n";
//std::cout << num << "number\n";
//outputTree();
  	if (num > subtree->getValue()) {
//std::cout << "More than.\n";
  		if (subtree->getRight() == nullptr) {  return false; }
  	  else if (subtree->getRight()->getValue() == num) {
//std::cout << "We found a match!\n";
  	  	if ((subtree->getRight()->getLeft() == nullptr) && (subtree->getRight()->getRight() == nullptr)) {
  	  		//Is leaf, delete node.
//std::cout << "LEEAF\n";
  	  		delete subtree->getRight();
  	  		size--;
  	  		node* temp = nullptr;
  	  		subtree->setRight(temp);
//std::cout << "bye line 105 AVLTree.cpp\n";
  	  		return true;
  	  	}
  	  	else if ((subtree->getRight()->getLeft() == nullptr) && (subtree->getRight()->getRight() != nullptr)) {
  	  		//Connect parent of node to right child of node
//std::cout << "connect right\n";
//std::cout << "before\n";
//outputTree();
  	  		node* temp = subtree->getRight();

  	  		subtree->setRight(subtree->getRight()->getRight());
  	  		temp->setRight(nullptr);
  	  		lowerHeight(subtree->getRight());
  	  		delete temp;
  	  		size--;
  	  		temp = nullptr;
//std::cout << "after\n";
//outputTree();
  	  		return true;
  	  	} else if ((subtree->getRight()->getLeft() != nullptr) && (subtree->getRight()->getRight() == nullptr)) {
  	  		//Connect parent of node to left child of node
//std::cout << "connect left\n";
  	  		node* temp = subtree->getRight();
  	  		subtree->setRight(subtree->getRight()->getLeft());
  	  		temp->setLeft(nullptr);
  	  		lowerHeight(subtree->getRight());
  	  		delete temp;
  	  		size--;
  	  		temp = nullptr;
  	  		return true;
  			}
  			else if ((subtree->getRight()->getLeft() != nullptr) && (subtree->getRight()->getRight() != nullptr)) {
  				//Find minimum, then recursively call helperDeleteTree in an if statement on it so all cases are considered.
//std::cout << "find min etc\n";
  				node* temp = subtree->getRight()->getRight();
  				while (temp->getLeft() != nullptr && temp->getLeft()->getLeft() != nullptr) {
  					temp = temp->getLeft();
  				}
					if (temp->getLeft() == nullptr) { //If the right node has no left child... (The above loop did not iterate once)
					//temp is subtree->getRight()->getRight().
					//node to be deleted is subtree->getRight().
						node* deleteThis = subtree->getRight();
						subtree->setRight(temp);
//Note: lowerHeight() before setLeft, because the getleft is already correct height.
						lowerHeight(subtree->getRight());
						temp->setLeft(deleteThis->getLeft());
						deleteThis->setRight(nullptr);
						deleteThis->setLeft(nullptr);
						delete deleteThis;
						size--;
						deleteThis = nullptr;
						temp = nullptr;
//std::cout << "no u\n";
					} else { //The while loop iterated at least once.
//std::cout << "Iterate >1\n";
						subtree->getRight()->setValue(temp->getLeft()->getValue());
						if (!helperDeleteTree(temp->getLeft()->getValue(),temp)) { return false; }
					}
//outputTree();
					return true;
				}
  		} else {
  			//if more than, right is not nullptr nor the value we want, then keep iterating down.
  			if (!helperDeleteTree(num, subtree->getRight())) { return false;}
  			return true;
  		}
  		
  		
  		
  	} else if (num < subtree->getValue()) {
//std::cout << "Less than\n"; 
  		if (subtree->getLeft() == nullptr) { return false; }
  	  else if (subtree->getLeft()->getValue() == num) {
//std::cout << "Match, " << num << std::endl;
  	  	if ((subtree->getLeft()->getLeft() == nullptr) && (subtree->getLeft()->getRight() == nullptr)) {
  	  		//Is leaf, delete node.
//std::cout << "should have been here. line 156.\n";
  	  		//delete subtree->getLeft()->getRight();
  	  		delete subtree->getLeft();
  	  		size--;
  	  		subtree->setLeft(nullptr);
//outputTree();
  	  		return true;
  	  	}
  	  	else if ((subtree->getLeft()->getLeft() == nullptr) && (subtree->getLeft()->getRight() != nullptr)) {
  	  		//Connect parent of node to right child of node
//std::cout << "connect right\n";
  	  		node* temp = subtree->getLeft()->getRight();
  	  		subtree->getLeft()->setRight(nullptr);
  	  		delete subtree->getLeft();
  	  		size--;
  	  		subtree->setLeft(temp);
  	  		lowerHeight(subtree->getLeft());
  	  		temp = nullptr;
  	  		return true;
  	  	} else if ((subtree->getLeft()->getLeft() != nullptr) && (subtree->getLeft()->getRight() == nullptr)) {
  	  		//Connect parent of node to left child of node 
//std::cout << "connect left\n";
  	  		node* temp = subtree->getLeft()->getLeft();
  	  		subtree->getLeft()->setLeft(nullptr);
  	  		delete subtree->getLeft();
  	  		size--;
  	  		subtree->setLeft(temp);
  	  		lowerHeight(subtree->getLeft());
  	  		temp = nullptr;
  	  		return true;
  			}
  			else if ((subtree->getLeft()->getLeft() != nullptr) && (subtree->getLeft()->getRight() != nullptr)) {
  					//Find minimum, then recursively call helperDeleteTree in an if statement on it so all cases are considered.
//std::cout << "get min etc\n";
  				node* temp = subtree->getLeft()->getRight();
  				while (temp->getLeft() != nullptr && temp->getLeft()->getLeft() != nullptr) {
  					temp = temp->getLeft();
  				}
					if (temp->getLeft() == nullptr) { //If the right node has no left child... (The above loop did not iterate once)
					//temp is subtree->getLeft()->getRight().
					//node to be deleted is subtree->getLeft().
//std::cout << "no iteration\n";
						node* deleteThis = subtree->getLeft();
						subtree->setLeft(temp);
						lowerHeight(subtree->getLeft());
						temp->setLeft(deleteThis->getLeft());
						
//outputTree();
						
						deleteThis->setRight(nullptr);
						deleteThis->setLeft(nullptr);
						delete deleteThis;	
						size--;
						deleteThis = nullptr;
						temp = nullptr;

					} else { //The while loop iterated at least once.
//std::cout << "iterated\n";
						subtree->getLeft()->setValue(temp->getLeft()->getValue());
						if (!helperDeleteTree(temp->getLeft()->getValue(),temp)) { return false; }
					}
//outputTree();
					return true;
  			}
  			else { std::cout << "This is impossible.\n"; }
  		} else {
  			if (helperDeleteTree(num, subtree->getLeft())) { return true; }
  			else { return false; }
  		}
  	}
  }
  		
  			
  bool binaryTree::deleteTree(int64_t num) {
    //iterate through tree, find value. If not found, return false.
    if (root == nullptr) {
      return false;
    } else if (root->getValue() == num) {
//std::cout << "deleting the root node.\n";
//Delete the root node
			//If right node, then iterate down the left most of that right node until reach leaf. Make the 'to be deleted' node's value into that, and delete that leaf node that you just copied.
			//if no right node, then check for left 
			
			if ((root->getRight() == nullptr) && (root->getLeft() == nullptr)) {
			delete root;
			root = nullptr;
			size--;
			}
			else if ((root->getRight() == nullptr) && (root->getLeft() != nullptr)) {
				node* temp = root;
				root = root->getLeft();
				temp->setLeft(nullptr);
				delete temp;
				temp = nullptr;
				lowerHeight(root);
				size--;
			}
			else if ((root->getRight() != nullptr) && (root->getLeft() == nullptr)) {
				node* temp = root;
				root = root->getRight();
				temp->setRight(nullptr);
				delete temp;
				temp = nullptr;
				lowerHeight(root);
				size--;
			}
			else { //has two children
				node* it = root->getRight();
				
				//Short circuit so second statement will not segfault us.
				while ((it->getLeft() != nullptr) && (it->getLeft()->getLeft() != nullptr)) {
				it = it->getLeft();
			}
			if (it->getLeft() == nullptr) { //If the right node has no left child... (The above loop did not iterate once)
				lowerHeight(it);
				it->setLeft(root->getLeft());
				node* temp = root;
				root = it;
				temp->setLeft(nullptr);
				temp->setRight(nullptr);
				delete temp;
				temp = nullptr;
				size--;
			}
			else { //The while loop iterated at least once.
				
				root->setValue(it->getLeft()->getValue());
				if (!helperDeleteTree(it->getLeft()->getValue(),it)) { return false; }
				}
				it = nullptr;
				return true;
			}
    } else { //Iterate down tree, find position.
      node* it = root;
      if (num < it->getValue()) {
        if (it->getLeft() == nullptr) {
          //num will be on left of root.
          return false;
        } else {
        
        
//std::cout << "Modified code to eliminate root child nodes here. Line 265.\n";
        	//If one of the root's child nodes is the one, do this instead.
        	//Shortcircuit if there is no respective child node.
        	if (((it->getLeft() != nullptr) && (it->getLeft()->getValue() == num)) || ((it->getRight() != nullptr) && (it->getRight()->getValue() == num))) {
        		if(!helperDeleteTree(num, it)) { return false; }
        		return true;
        	}
        	//Otherwise, just keep iterating down.
//std::cout << "keep iterating down\n";
        	
          //recursive helper function.
          if (!helperDeleteTree(num, it->getLeft())) { return false;}
          return true;
        }
      } else if (num > it->getValue()) {
        if (it->getRight() == nullptr) {
          //num will be on right of root.
          return false;
        } else {
          //same recursive helper function, like above.
          if (!helperDeleteTree(num, it)) { return false; }
        }
      } else { std::cout << "This is impossible, we already checked for root.\n"; return false; /*Already present. */ } 
    }
    return true;
  }

bool binaryTree::helperWriteTree(int64_t num, node* witness, node* prevNode, node* subtree) {
  //prevNode is always root in this version of the function.
//outputTree();
    //base case; see if spot is as a left or right of current node.
    if (num > subtree->getValue()) {
      if (subtree->getRight() == nullptr) {
        node* temp = new node(num);
        subtree->setRight(temp);
        temp->height = subtree->height+1;
        temp = nullptr;
        size++;
        
        
        
        
        //We are adding to right of subtree
        //call gsh()
        
        
        
        
      } else {
        if (!helperWriteTree(num, prevNode, subtree, subtree->getRight())) { return false; }
      }
    } else if (num < subtree->getValue()) {
      if (subtree->getLeft() == nullptr) {
        node* temp = new node(num);
        subtree->setLeft(temp);
        temp->height = subtree->height+1;
        size++;
        
        //We are adding to the left of subtree
        //check if subtree is at right or left of prevNode.
        //if left left, do our single left rotation
//leftRotate(witness, prevNode, subtree, subtree->left);
        //if right left, do our double right-left rotation
        
        
      } else {
        if (!helperWriteTree(num, subtree, subtree->getLeft())) { return false; }
      }
    }
    else { return false; }
    return true;
  }
  
  
  
  

bool binaryTree::helperWriteTree(int64_t num, node* prevNode, node* subtree) {
  //prevNode is always root in this version of the function.
//outputTree();
    //base case; see if spot is as a left or right of current node.
    if (num > subtree->getValue()) {
      if (subtree->getRight() == nullptr) {
        node* temp = new node(num);
        subtree->setRight(temp);
        temp->height = subtree->height+1;
        temp = nullptr;
        size++;
        
        
        
        
        //We are adding to right of subtree
        
        
        
        
        
        
      } else {
        if (!helperWriteTree(num, prevNode, subtree, subtree->getRight())) { return false; }
      }
    } else if (num < subtree->getValue()) {
      if (subtree->getLeft() == nullptr) {
        node* temp = new node(num);
        subtree->setLeft(temp);
        temp->height = subtree->height+1;
        size++;
      } else {
        if (!helperWriteTree(num, prevNode, subtree, subtree->getLeft())) { return false; }
      }
    }
    else { return false; }
    return true;
  }
  
  
  
  
  
  
  
  
  
  
  bool binaryTree::writeTree(int64_t num) {
  /*
  difference from binary:
  1 - After adding, check height of the opposite subtree to see if you need rebalancing.
  2 - Find out which of the four cases this is, and rotate accordingly.
  */
  
  
  
  
    //Check if we have room.
    if (size == capacity) { return false; }
    //Check to see if tree is empty or not.
    if (getRoot() == nullptr) {
      node* temp = new node(num);
      setRoot(temp);
      temp->height = 1;
      size++;
      temp = nullptr;
    } else { //Iterate down tree, find position.
      node* it = getRoot();
      if (num < it->getValue()) {
        if (it->getLeft() == nullptr) {
          //num will be on left of root.
          node* temp = new node(num);
          it->setLeft(temp);
          temp->height = 2;
          size++;
          temp = nullptr;
        } else {
          //recursive helper function.
          if (!helperWriteTree(num, root, it->getLeft())) { return false; }
        }
      } else if (num > it->getValue()) {
        if (it->getRight() == nullptr) {
          //num will be on right of root.
          node* temp = new node(num);
          it->setRight(temp);
          temp->height = 2;
          temp = nullptr;
          size++;
        } else {
          //same recursive helper function, like above.
          if (!helperWriteTree(num, root,it->getRight())) { return false; }
        }
      } else { return false; /*Already present. */ } 
    }
    //outputTree();//Debugging
    return true;
  }
  


  /*bool binaryTree::helperWriteTree(int64_t num, node* subtree) {
    //base case; see if spot is as a left or right of current node.
    if (num > subtree->getValue()) {
      if (subtree->getRight() == nullptr) {
        node* temp = new node(num);
        subtree->setRight(temp);
        size++;
      } else {
        if (!helperWriteTree(num, subtree->getRight())) { return false; }
      }
    } else if (num < subtree->getValue()) {
      if (subtree->getLeft() == nullptr) {
        node* temp = new node(num);
        subtree->setLeft(temp);
        size++;
      } else {
        if (!helperWriteTree(num, subtree->getLeft())) { return false; }
      }
    }
    else { std::cout << "ALREADY PRESENT\n"; return false; }
    return true;
  }
  
  
  bool binaryTree::writeTree(int64_t num) {
    //Check if we have room.
    if (size == capacity) { std::cout << "Capacity reached\n"; return false; }
    //Check to see if tree is empty or not.
    if (getRoot() == nullptr) {
      node* temp = new node(num);
      setRoot(temp);
      size++;
      temp = nullptr;
    } else { //Iterate down tree, find position.
      node* it = getRoot();
      if (num < it->getValue()) {
        if (it->getLeft() == nullptr) {
          //num will be on left of root.
          node* temp = new node(num);
          it->setLeft(temp);
          size++;
        } else {
          //recursive helper function.
          if (!helperWriteTree(num, it->getLeft())) { return false; }
        }
      } else if (num > it->getValue()) {
        if (it->getRight() == nullptr) {
          //num will be on right of root.
          node* temp = new node(num);
          it->setRight(temp);
          size++;
        } else {
          //same recursive helper function, like above.
          if (!helperWriteTree(num, it->getRight())) { return false; }
        }
      } else { std::cout << "ALREADY PRESENT!\n"; return false;  } 
    }
    outputTree();//Debugging
    return true;
  }
  
*/
    
 

  bool binaryTree::helperReadTree(int64_t num, node* subtree) { 
    //base case; see if spot is as a left or right of current node.
    if (num > subtree->getValue()) {
      if (subtree->getRight() == nullptr) {
        return false;
      } else if (subtree->getRight()->getValue() == num) {
        return true;
      } else {
        if (!helperReadTree(num, subtree->getRight())) { return false;}
      }
    } else if (num < subtree->getValue()) {
      if (subtree->getLeft() == nullptr) {
        return false;
      } else if (subtree->getLeft()->getValue() == num) {
        return true;
      } else {
        if (!helperReadTree(num, subtree->getLeft())) { return false; }
      }
    }
    else { return false; }
    return true;
  }
  
  
  
  
  bool binaryTree::readTree(int64_t num) {
    //iterate through tree, find value. If not found, return false.
    if (getRoot() == nullptr) {
      return false;
    } else { //Iterate down tree, find position.
      node* it = getRoot();
      if (num < it->getValue()) {
        if (it->getLeft() == nullptr) {
          //num will be on left of root.
          return false;
        } else {
          //recursive helper function.
          if (!helperReadTree(num, it->getLeft())) { return false;}
        }
      } else if (num > it->getValue()) {
        if (it->getRight() == nullptr) {
          //num will be on right of root.
          return false;
        } else {
          //same recursive helper function, like above.
          if (!helperReadTree(num, it->getRight())) {return false;}
        }
      } else { return true; /*Already present. */ } 
    }
    return true;
  }
  static int count = 0;
  void binaryTree::outputTree() {
  	totalHeight = 0; //Will be reinitialized here.
  	//post order
  	std::cout << "\nOutputting binary tree:\n";
  	if (root == nullptr) { std::cout << "root is boot\n"; return;}
  	if (root->getLeft() != nullptr) {
  		helperOutputTree(root->getLeft());
  	}
  	if (root->getRight() != nullptr) {
  		helperOutputTree(root->getRight());
  	}
  	std::cout << root->getValue() << " Height: " << root->height << std::endl;
  	std::cout << "Count: (delete later) " << ++count << std::endl;
  	std::cout << "Size: " << size << std::endl;
  	count = 0;
  }
  
  
  void binaryTree::outputTree(std::ofstream& file) {
  	totalHeight = 0; //Will be reinitialized here.
  	//post order
  	file << "\nOutputting binary tree:\n";
  	if (root == nullptr) { file << "root is boot\n"; return;}
  	if (root->getLeft() != nullptr) {
  		helperOutputTree(root->getLeft(),file);
  	}
  	if (root->getRight() != nullptr) {
  		helperOutputTree(root->getRight(),file);
  	}
  	file << root->getValue() << " Height: " << root->height << std::endl;
  	file << "Count: (delete later) " << ++count << std::endl;
  	file << "Size: " << size << std::endl;
  	count = 0;
  }
  
  
  
  
  void binaryTree::helperOutputTree(node* subtree) {
  	if (subtree->getLeft() != nullptr) {
  		helperOutputTree(subtree->getLeft());
  	}
  	if (subtree->getRight() != nullptr) {
  		helperOutputTree(subtree->getRight());
  	}
  	std::cout << subtree->getValue() << " height: " << subtree->height << std::endl;
  	if (subtree->height > totalHeight) {
  		totalHeight = subtree->height;
  	}
  	count++;
  }
  
  void binaryTree::helperOutputTree(node* subtree, std::ofstream& file) {
  	if (subtree->getLeft() != nullptr) {
  		helperOutputTree(subtree->getLeft(),file);
  	}
  	if (subtree->getRight() != nullptr) {
  		helperOutputTree(subtree->getRight(),file);
  	}
  	file << subtree->getValue() << " height: " << subtree->height << std::endl;
  	if (subtree->height > totalHeight) {
  		totalHeight = subtree->height;
  	}
  	count++;
  }
  
  
  
  binaryTree::~binaryTree() {
  	delete root;
  }
}
