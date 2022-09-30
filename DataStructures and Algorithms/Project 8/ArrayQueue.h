/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name:Daniela Contreras
 * Partner: John Cho
 * Date:11/11/2021
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_
#include <cstring>

#include "QueueException.h"

//typedef int Item;
template <class Item>
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue& original);
	ArrayQueue(unsigned capacity);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	void append(const Item& it);
	Item remove();
	Item getFirst() const;
	Item getLast() const;
	void setCapacity(unsigned updatedCapacity);

protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of itemsThe Problem
	friend class ArrayQueueTester;
};
template <class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
	if ( capacity <= 0){
			throw EmptyQueueException( "Capacity can not be less than or equal to zero!");
	} else {
			myArrayPtr = new Item[capacity];
	}
	myCapacity = capacity;
	mySize = myFirstIndex = 0;
	myLastIndex = capacity -1;
}
/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template <class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template <class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}
/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
template <class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = nullptr;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template <class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template <class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template <class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template <class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template <class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}
template <class Item>
Item ArrayQueue<Item>::getFirst() const{
	if ( isEmpty()){
			throw EmptyQueueException( "The Queue is empty");
	}
	return myArrayPtr [myFirstIndex];
}
template <class Item>
Item ArrayQueue<Item>::getLast() const{
	if ( isEmpty()){
			throw EmptyQueueException( " Nothing here, Queue is empty");
	}
	return myArrayPtr [myLastIndex];

}
template <class Item>
void ArrayQueue<Item>::append(const Item& it){
	if (isFull()){
			throw FullQueueException("The Queue has reached it's limit!");
	}
	myLastIndex =  (myLastIndex + 1) % myCapacity ;
	myArrayPtr[myLastIndex] = it;
	mySize ++;
}
template <class Item>
Item ArrayQueue<Item>::remove(){
	if (isEmpty()){
		throw EmptyQueueException("No more items to remove!! Queue is empty");
	}
	Item result = myArrayPtr [myFirstIndex];
	myFirstIndex = (myFirstIndex +1)%myCapacity;
	mySize--;
	return result;

}
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned updatedCapacity){
	if(updatedCapacity < mySize || updatedCapacity == 0){
		throw QueueException("setCapacity()", "Capacity must be greater than previous");
	}
	Item* Newptr = new Item[updatedCapacity]; //creates a new empty array
	unsigned index = myFirstIndex;
	for (unsigned i = 0; i <mySize; ++i){//takes care of copying previous indexes
		Newptr[i] = myArrayPtr[index]; //copy first item
		index = (index +1 ) % myCapacity; //% wraps around index
	}
	myCapacity = updatedCapacity;
	delete[] myArrayPtr; //delete items/indexes that my array pointer points to
	myArrayPtr= Newptr; //assigning new pointer
	myFirstIndex = 0; //starting index at zero
	myLastIndex= mySize -1;
}


#endif /*ARRAY_QUEUE_H_*/
