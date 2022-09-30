/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name:Daniela Contreras
 * Date:11/11/2021
 */

#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = nullptr;
	} else {
		myFirstPtr = new Node(original.getFirst(), nullptr);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != nullptr) {
			temp1->myNextPtr = new Node(temp0->myItem, nullptr);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = nullptr;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}
//constructor
LinkedQueue::LinkedQueue(){
	mySize = 0;
	myFirstPtr = nullptr;
	myLastPtr = nullptr;
}

Item LinkedQueue::getFirst()const{
	if(isEmpty()){
		throw (EmptyQueueException("getFirst()"));
	}
	return myFirstPtr -> myItem;
}
Item LinkedQueue::getLast()const{
	if(isEmpty()){
		throw(EmptyQueueException("getFirst()"));
	}
	return myLastPtr -> myItem;
}
void LinkedQueue::append(const Item& it){
	Node* myNodePointer ;
	try{
		myNodePointer = new Node(it, nullptr);
	}
	catch (std::bad_alloc&){
		throw FullQueueException("LinkedQueue::append()");
	}
	if (mySize == 0){
		myFirstPtr = myNodePointer;
	}
	else {
		myLastPtr ->myNextPtr = myNodePointer;
	}
	++ mySize;
	myLastPtr = myNodePointer;
}
Item LinkedQueue::remove(){
	if(isEmpty()){
		throw (EmptyQueueException("remove()"));
	}
	Item result = myFirstPtr -> myItem;
	Node* temporary = myFirstPtr;
	myFirstPtr = myFirstPtr -> myNextPtr;
	temporary -> myNextPtr = nullptr;
	delete temporary;
	--mySize;
	return result;
}
