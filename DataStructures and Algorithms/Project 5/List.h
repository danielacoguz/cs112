/*List.h
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 10/7/2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

template<class Item>

class List {
public:
	List();
	unsigned getSize()const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);
	virtual ~List();
	// Project 5 //
	bool operator ==(const List<Item>& list2);
	bool operator!=(const List& ls);
	void readFrom(istream& cin);
	void writeTo(ostream& out) const;
	void readFrom(const string& fileName);
	void writeTo(const string& fileName);
	void prepend(Item it);
	void insert(Item it, int index);
	Item getIndexOf(const Item& it) const;
	Item remove(double index);
private:
	struct Node { //inner struct
		Node();
		Node(Item it, Node *next);
		~Node();

		Item myItem;
		Node *myNext;

	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	friend class ListTester;
};
template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = nullptr;

}

template <class Item>
List<Item>::Node::Node() {
	myNext = nullptr;
	myItem = Item();
}
template <class Item>
List<Item>::Node::Node(Item it, Node *next) {
	myNext = next;
	myItem = it;
}
template <class Item>
unsigned List<Item>::getSize()const{
	return mySize;
}

template <class Item>
Item List<Item>::getFirst() const{
	if (mySize == 0) {
		throw underflow_error ("index error!");
	}
	return myFirst -> myItem;
}

template <class Item>
Item List<Item>::getLast()const {
	if (mySize == 0) {
		throw underflow_error ("index error!");
	}
	return myLast -> myItem;
}

template <class Item>
void List<Item>::append(const Item& it) {
	Node* newNode = new Node(it, nullptr);

	if ((mySize == 0)) {
		myFirst = newNode;
		myLast = newNode;

	} else {
		myLast -> myNext = newNode;
		myLast = newNode;
	}
	mySize++;
}

template <class Item>
List<Item>::~List() {
	delete myFirst;             // delete first node, invoking ~Node()
	//  (does nothing if myFirst == nullptr)
	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
	mySize = 0;                 // clear mySize (optional)
}
template <class Item>
List<Item>::Node::~Node() {

	delete myNext;       // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == nullptr)

	//cout << "~Node() is deallocating the node containing item "
	//<< myItem << endl;
}

template <class Item>
List<Item>::List(const List& original) {
	myFirst = myLast = nullptr;    //  set pointers
	mySize = 0;                    //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at original's first node
	while (oPtr != nullptr) {      //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
}

template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& rhs) { // rhs == right hand side
	if (&rhs != this) {
		delete myFirst;  //  Deallocate my chain of nodes.
		myFirst = myLast = nullptr;  //  Set myFirst and myLast to nullptr.
		mySize = 0;  //  Set mySize to zero.
		Node*nPtr = rhs.myFirst; //  Declare nPtr containing the address of rhs's first node.
		while (nPtr != nullptr) {  //  While nPtr is pointing at something:
			append(nPtr->myItem);  //  Append (to me) a copy of the item in the node to which nPtr is pointing.
			nPtr = nPtr->myNext;  //  Advance nPtr to the next node.
		}
	}
	return *this;

}

//Project 5 //

/*equality operator for list objects
 * Done by: Daniela C
 */
template<class Item>
bool List<Item>::operator ==(const List<Item>& list2){
	if (mySize!= list2.mySize){
		return false;
	}
	else{
		Node* myPtr = myFirst;
		Node* list2Ptr = list2.myFirst;
		while (myPtr != nullptr){
			if (myPtr->myItem != list2Ptr->myItem){
				return false;
			}
			list2Ptr = list2Ptr ->myNext;
			myPtr = myPtr->myNext;
		}
		return true;
	}
}


/*Inequality method
 *checks for inequality
 *Done by: John Cho
 */
template<class Item>
bool List<Item>::operator!=(const List& l2){
	if (getSize() != l2.getSize()){
		return true;
	}
	else{
		Node* ptr1 = myFirst; //start at the first node
		Node*ptr2 = l2.myFirst;

		while(ptr1 != NULL){
			if (ptr1->myItem != ptr2->myItem){
				return true;
			}
			ptr1 = ptr1->myNext;
			ptr2 = ptr2->myNext;
		}
	}
	return false;
}
/*Readfrom(istream) operator
 *Done by: Daniela C
 */
template <class Item>
void List<Item>::readFrom(istream& cin){
	delete myFirst;
	mySize = 0;
	myFirst = myLast = nullptr;

	Item values;
	cin >> values;

	while (cin) {
		append(values);

		if (cin.peek() == '\n') {
			break;
		}
		cin>>values;
	}
}
/*writToStream method
 *@param: ostream& out
 *writes list to out
 *Done By; John Cho
 */
template<class Item>
void List<Item>::writeTo(ostream& out) const{
	Node*ptr = myFirst;
	while(ptr!=NULL){
		if (ptr->myNext!=NULL){
			out << ptr->myItem << endl;
		}
		else{
			out << ptr->myItem << flush;
		}
		ptr = ptr->myNext;
	}
}

/*readFromFile method
 *@param: const string& fileName
 *Done By: Daniela C
 */
template<class Item>
void List<Item>::readFrom(const string& fileName){
	ifstream fin(fileName.c_str());
	assert(fin.is_open());

	if (myFirst!=NULL and myLast!=NULL){
		delete myFirst;
		myFirst = NULL;
		myLast = NULL;
		mySize=0;
	}

	while(!fin.eof( )){
		double value;
		fin >> value;
		append(value);
	}
}
/*WriteToString Method
 *Done by: John Cho
 */
template<class Item>
void List<Item>::writeTo(const string& fileName){
	ofstream fout(fileName.c_str());
	Node*myPtr = myFirst;
	for(unsigned i = 0; i< mySize; i++){
		fout << myPtr->myItem << endl;
		myPtr = myPtr->myNext;
	}
	fout.close();
}
/*Prepend method
 * Done by:Daniela C
 */
template<class Item>
void List<Item>::prepend(Item it){
	Node* newNodePtr = new List<Item>::Node(it,nullptr);
	if (mySize == 0){
		myLast = newNodePtr;
	}
	else{
		newNodePtr->myNext = myFirst;
	}
	myFirst = newNodePtr;
	mySize++;
}
/*Insert method
 * Done by:John Cho
 */
template<class Item>
void List<Item>::insert(Item it, int index){
	int size = mySize;
	if (index <= 0 || mySize ==0){
		prepend(it);
	}
	else if(index >= size){
		append(it);
	}
	else{
		Node* tempPtr = myFirst;
		for (signed i =0; i<index -1; ++i){
			tempPtr = tempPtr->myNext;
		}
		Node* newNodePtr = new List<Item>::Node(it, tempPtr->myNext);
		tempPtr->myNext = newNodePtr;
		mySize++;
	}
}


/*getIndexOf Method
 *@param: consr Item, it
 *Done by; Daniela C
 */
template<class Item>
Item List<Item>::getIndexOf(const Item& it) const{
	Item index = 0;
	Node*ptr = myFirst;
	while(ptr!=NULL){
		if (ptr->myItem == it){
			return index;
		}
		ptr = ptr->myNext;
		index++;
	}
	return -1;
}
/*remove method
 *@param: double index
 *by: John Cho
 */
template<class Item>
Item List<Item>::remove(double index){
	Node*ptr = myFirst;
	Item number = 0;
	Item item = 0;
	if(myFirst==NULL and myLast == NULL){
		throw range_error("invalid index");
	}
	while(ptr!=NULL){
		if(index<=0){
			item = myFirst->myItem;
			myFirst = myFirst->myNext;
			ptr->myNext = NULL;
			delete ptr;
			mySize--;
			return item;
		}
		else if (index >= mySize){
			Node* blptr = myFirst;
			for(unsigned i=0; i<(mySize-2) ; i++){
				blptr = blptr->myNext;
			}
			ptr = myLast;
			item = myLast->myItem;
			myLast = blptr;
			blptr->myNext = NULL;
			delete ptr;
			mySize--;
			return item;
		}
		if (index == number){
			Node* tmp = myFirst;
			for(unsigned i=0; i<(number-1) ; i++){
				tmp = tmp->myNext;
			}
			item = ptr->myItem;
			ptr = tmp->myNext;
			tmp->myNext = ptr->myNext;
			ptr->myNext = NULL;
			delete ptr;
			mySize--;
			return item;
		}
		ptr = ptr->myNext;
		number++;
	}
	return item;
}


#endif /* LIST_H_ */
