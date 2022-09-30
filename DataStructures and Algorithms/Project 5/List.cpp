///*List.cpp
// * Student Name: John Cho
// * Student Name: Daniela Contreras ldc6
// * Date: 10/7/2021
// * Begun by: Joel C. Adams, for CS 112 at Calvin University.
// */
//
//#include "List.h"
//
//List::List() {
//	mySize = 0;
//	myFirst = myLast = nullptr;
//
//}
//
//List::Node::Node() {
//	myNext = nullptr;
//	myItem = Item();
//}
//List::Node::Node(Item it, Node *next) {
//	myNext = next;
//	myItem = it;
//}
//unsigned List::getSize()const{
//	return mySize;
//}
//
//Item List::getFirst() const{
//	if (mySize == 0) {
//		throw underflow_error ("index error!");
//	}
//	return myFirst -> myItem;
//}
//
//Item List::getLast()const {
//	if (mySize == 0) {
//		throw underflow_error ("index error!");
//	}
//	return myLast -> myItem;
//}
//
//void List::append(const Item& it) {
//	Node* newNode = new Node(it, nullptr);
//
//	if ((mySize == 0)) {
//		myFirst = newNode;
//		myLast = newNode;
//
//	} else {
//		myLast -> myNext = newNode;
//		myLast = newNode;
//	}
//	mySize++;
//}
//List::~List() {
//   delete myFirst;             // delete first node, invoking ~Node()
//                               //  (does nothing if myFirst == nullptr)
//   myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
//   mySize = 0;                 // clear mySize (optional)
//}
//List::Node::~Node() {
//
//	delete myNext;       // delete the next node, invoking ~Node() in it
//	// (does nothing if myNext == nullptr)
//
//	//cout << "~Node() is deallocating the node containing item "
//			//<< myItem << endl;
//}
//List::List(const List& original) {
//      myFirst = myLast = nullptr;    //  set pointers
//      mySize = 0;                    //   and size to 'empty' values
//      Node* oPtr = original.myFirst; //  start at original's first node
//      while (oPtr != nullptr) {      //  while there are nodes to copy:
//         append(oPtr->myItem);       //   append the item in that node
//         oPtr = oPtr->myNext;        //   advance to next node
//      }
//   }
//List& List::operator=(const List& rhs) { // rhs == right hand side
//	if (&rhs != this) {
//		delete myFirst;  //  Deallocate my chain of nodes.
//		myFirst = myLast = nullptr;  //  Set myFirst and myLast to nullptr.
//		mySize = 0;  //  Set mySize to zero.
//		Node*nPtr = rhs.myFirst; //  Declare nPtr containing the address of rhs's first node.
//		while (nPtr != nullptr) {  //  While nPtr is pointing at something:
//			append(nPtr->myItem);  //  Append (to me) a copy of the item in the node to which nPtr is pointing.
//			nPtr = nPtr->myNext;  //  Advance nPtr to the next node.
//		}
//	}
//	return *this;
//
//}
//bool List::operator==(const List& original) {
//	if (mySize == original.mySize) {
//		if(mySize == 0) {
//			return true;
//		}
//		Node *myPtr = original.myFirst;
//		Node *myPtr2 = myFirst;
//
//		while (myPtr != nullptr){
//			if(myPtr2-> myItem != myPtr -> myItem) {
//				return false;
//			}
//			else {
//				return true;
//			}
//			myPtr = myPtr -> myNext;
//			myPtr2 = myPtr2 -> myNext;
//		}
//	}
//	if (mySize != original.mySize) {
//		return false;
//	}
//}
