/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Daniela Contreras
 * Date:11//23/2021
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	void insert(const Item& it);
	bool contains(const Item& item) const ;
	unsigned getHeight()const;




private:
	struct Node {
	    Node(const Item& it);
	    void nodeInsert(const Item& it);
	    bool nodeContains(const Item& item);
	    unsigned getHeightNode()const;
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};
template <class Item>
BST<Item>::BST(){
	myNumItems = 0;
	myRoot = nullptr;
}
template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}
template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}
template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}
template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}
template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}
template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}
template <class Item>
void BST<Item>::Node::traversePreorder() {
	//1.process myItem first (preorder)
	processItem();
	//then recursively process the items in the left subtree
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	//then recursively process the items in the right subtree
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}
template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}
/*
 * The parameters necessary: it, and Item
 * New Node is created containing it
 * MyRoot calls NodeInsert for "it"
 *
 */
template <class Item>
void BST<Item>::insert(const Item& it){
	if(isEmpty()){
		myRoot = new Node(it);
		++ myNumItems;
	} else {
		try{
		myRoot->nodeInsert(it);
		++ myNumItems;
		}
		catch(Exception& e){
			throw e;
		}

	}
//		}else{ if()
//		throw Exception("")
	/*
	 * param: it and Item
	 * MyLeft creates a node that containst it
	 * MyLeft calls nodeInserrt for "it"
	 * MyRight also creates a new Node to hold on to it
	 * then an exception is thrown
	 */
}
template <class Item>
void BST<Item>::Node::nodeInsert(const Item& it){
	if(it < myItem){					//this is when the item goes to the left
		if(myLeft == nullptr){			//basis
			myLeft = new Node(it);
		}else {							//Insertion step 1
			myLeft -> nodeInsert(it);
		}
	}else if(it > myItem) {				//Item goes to the right
		if(myRight == nullptr){			//Basis
			myRight = new Node (it);	//Insertion Step 2
		} else {
			myRight -> nodeInsert(it);
		}
	}else {
		throw Exception ("nodeInsert()", "Item is already in BST");
	}

}
/*
 * returns false if there isn't any items
 * myRoot then calls nodeContainst if everything is fine
 */
template <class Item>
bool BST<Item>::contains(const Item& item) const {
	if(isEmpty()){
		return false;
	}else {
		return myRoot -> nodeContains(item);
	}
}
/*
 * If myLeft is empty then it returns false
 * then nodeContains is called
 * If myRight is empty return false
 * then again nodeCOntains is called
 * However, of ot's equal to myItem return true.
 */
template <class Item>
bool BST<Item>::Node::nodeContains(const Item& item){
	if(item < myItem){
		if(myLeft == nullptr){
			return false;
		}else{
			return myLeft -> nodeContains(item);
		}
	} else if(item > myItem){
		if(myRight == nullptr){
			return false;
		}else{
			return myRight -> nodeContains(item);
		}
	}
//	return false; //default to get rid of warning
	return true;
}
template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}
template <class Item>
void BST<Item>::Node::traversePostorder() {
	//then recursively process the items in the left subtree
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	//then recursively process the items in the right subtree
	if (myRight != nullptr) {
		myRight->traversePreorder();
	// process myItem postorder
	processItem();
	}
}
template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder() {
	//then recursively process the items in the left subtree
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	processItem();
	//then recursively process the items in the right subtree
	if (myRight != nullptr) {
		myRight->traversePreorder();
	// process myItem postorder
	}
}
/*
 * returns zero if no items are there
 * otherwise myRoot nodeGetHeight is called
 */
template <class Item>
unsigned BST<Item>::getHeight()const{
	if(isEmpty()){
		return 0;
	}else{
		return myRoot -> getHeightNode();
	}

}
/*
 * If myLefgt isn't empty call nodeGetHeight
 * same for myRight
 */
template <class Item>
unsigned BST<Item>::Node::getHeightNode()const{
	unsigned leftHeight = 0;
	unsigned rightHeight = 0;
	if(myLeft != nullptr){
		leftHeight = myLeft -> getHeightNode();
	}
	if(myRight != nullptr){
		rightHeight = myRight -> getHeightNode();
	}
	if(leftHeight > rightHeight){
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
	}
}


#endif /*BST_H_*/

