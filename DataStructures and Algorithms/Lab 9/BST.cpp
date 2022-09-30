/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:Daniela Contreras
 * Date:11/16/2021
 */
 
#include "BST.h"
BST::BST(){
	myNumItems = 0;
	myRoot = nullptr;
}

BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
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

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::insert(const Item& it){
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
}
void BST::Node::nodeInsert(const Item& it){
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
bool BST::contains(const Item& item) const {
	if(isEmpty()){
		return false;
	}else {
		return myRoot -> nodeContains(item);
	}
}
bool BST::Node::nodeContains(const Item& item){
	if(item < myItem){
		if(myLeft == nullptr){
			return false;
		}else{
			myLeft -> nodeContains(item);
		}
	} else if(item > myItem){
		if(myRight == nullptr){
			return false;
		}else{
			myRight -> nodeContains(item);
		}
	}else{
		return true;
	}
//	return false; //default to get rid of warning

}
void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}
void BST::Node::traversePostorder() {
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
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}
void BST::Node::traverseInorder() {
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


