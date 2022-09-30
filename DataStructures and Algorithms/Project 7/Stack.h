/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:Daniela Contreras
 * Date:10/26/2021
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

//typedef int Item;
template<class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty()const;
	bool isFull()const;
	Item peekTop()const;
	void push(const Item& it);
	Item pop();
	unsigned getSize()const;
	unsigned getCapacity()const;
	void setCapacity(unsigned newCapacity);


	
protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};
template <class Item>
Stack<Item>::Stack(unsigned capacity) {
	/*
	 * Here we throw the exception before the previous statement because it will act like a pre-requisite to be fulfilled before
	 * continuing to check size capacity etc
	 * Also, since the capacity is grater than 0 we must assure the opposite (capacity <= 0) is taking place in order to thrown exception
	 */
	   if ( capacity <= 0 ) {
	      throw StackException("Stack(unsigned capacity)", "capacity must be positive");
	   }
   mySize = 0;
   myCapacity = capacity;
   myArray = new Item[capacity];

}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template <class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template <class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; ++i) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template <class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = nullptr;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}
/*
 *returns true or returns empty size if stack contains no items inside
 */
template <class Item>
bool Stack<Item>::isEmpty()const{
	return mySize == 0;
//		return mySize == 0;
//
//		return true;

}
/* checks to see if Stack has no more room to store the items
 */
template <class Item>
bool Stack<Item>::isFull() const{
	return mySize == myCapacity;
}
/*
 * Return the top item from the Stack without modifying the stack
 */
template <class Item>
Item Stack<Item>:: peekTop() const{
    if ( isEmpty() ) {
       throw StackException("peekTop()", "stack is empty");
    }
	return myArray[mySize -1];

}
/*
 * places "it" on top of the Stack
 */
template <class Item>
void Stack<Item>::push(const Item& it){
	if ( isFull()) {
	      throw StackException("push()", "stack is full!");
	   }
	myArray[mySize ++] = it;

}
/*
 * Operation that removes and returns the top item from the Stack
 */
template <class Item>
Item Stack<Item>::pop(){
	/*
	 * right here we are assuring first that if sack is empty we throw an exception
	 */
	if ( isEmpty()) {
	      throw StackException("pop()", "stack is empty!");
	   }
//	mySize --;
	/*if not empty we proceed and
	 * decrements the size
	 */
	return myArray[--mySize];
}
/*
 * Project 6 start
 *
 * Returns size
 */
template <class Item>
unsigned Stack<Item>::getSize()const{
	return mySize;
/*
 * obtains capacity and returns it
 */
}
template <class Item>
unsigned Stack<Item>::getCapacity()const{
	return myCapacity;
}
/*
 * first it has to pass the pre-requiste that the new capacity can not be smaller than the older capacity
 * we then assign the items from the old array into the new array then deallocate the old array
 * New array with new size is also implemented
 * then we converted it to a template by placing it in this file (.h)
 */
template <class Item>
void Stack<Item>::setCapacity(unsigned newCapacity){
	if( newCapacity < myCapacity){
		throw StackException("setCapacity()", "newCapacity is limit!");
	}
	Item * newArray = new Item [newCapacity];
	for (unsigned i=0; i < mySize; i++){
		newArray[i] = myArray[i];
	}
	delete[]myArray;
	myArray = newArray;
	myCapacity = newCapacity;
}
#endif

