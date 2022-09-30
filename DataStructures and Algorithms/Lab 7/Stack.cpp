/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:Daniela Contreras
 * Partner: John Cho
 * Date:10/26/2021
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
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
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
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
Stack::~Stack() {
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
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}
/*
 *returns true or returns empty size if stack contains no items inside
 */
bool Stack::isEmpty()const{
	return mySize == 0;
//		return mySize == 0;
//
//		return true;

}
/* checks to see if Stack has no more room to store the items
 */
bool Stack::isFull() const{
	return mySize == myCapacity;
}
/*
 * Return the top item from the Stack without modifying the stack
 */
Item Stack:: peekTop() const{
    if ( isEmpty() ) {
       throw StackException("peekTop()", "stack is empty");
    }
	return myArray[mySize -1];

}
/*
 * places "it" on top of the Stack
 */
void Stack::push(const Item& it){
	if ( isFull()) {
	      throw StackException("push()", "stack is full!");
	   }
	myArray[mySize ++] = it;

}
/*
 * Operation that removes and returns the top item from the Stack
 */
Item Stack::pop(){
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

