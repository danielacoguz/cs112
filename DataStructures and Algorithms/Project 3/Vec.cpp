/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Daniela Contreras
 * Date: 09/23/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"

/* default constructor
 * provides default variables
 */
Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}
/* initializes an object
 * using values provided by the user
 */

Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size]();
	} else {
		myArray = nullptr;
	}
}
/*Copy constructor
 * sets mySize to size of the original
 * allocates array of mySize values and stores them in myArray
 */

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];}
	}
	else {
		myArray = nullptr;
	}
}
/*assigment operator
 * checks to see if original and I are different
 * checks if my size is different from original
 * checks to see if original is positive
 * sets mysize to size of original
 */
Vec& Vec::operator=(const Vec& original) {
	if (mySize != original.mySize){
		if (mySize > 0 ){
			delete [] myArray;
			mySize = 0;
			myArray = nullptr;
		}
		if (original.mySize > 0 ){
			myArray = new Item[original.mySize]();
		}
		mySize = original.mySize;
	}
	for (unsigned i = 0; i < mySize; i++){
		myArray[i] = original.myArray[i];
	}
	return *this;
}
/* Vec Size method
 * retrives size
 */
unsigned Vec::getSize()const {
	return mySize;
}
/* Set item method
 * sets item into a particular item in vec
 */
void Vec::setItem(unsigned index, const Item& it) {
	if ( index >= mySize || index < 0 || mySize == 0) {
		throw range_error ("invalid Index");
	}else {
		myArray[index] = it;

	}
}
/* Get size method
 * allows us to change the size of a Vec to another new size
 */
Item Vec::getItem(unsigned index) const {
	if (mySize > index) {
		return myArray [index];
	} else {
		throw range_error ("invalid Index");
	}
}
/* set size method
 * this method lets us to change the size of an existing Vec to a new Size
 */
void Vec::setSize(unsigned newSize) {
	if (mySize == 0) {
		mySize = newSize;
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = 0;
		}
	} else if (newSize == 0) {
		mySize = 0;
		delete [] myArray;
		myArray = nullptr;
	} else  if (newSize == mySize) {

	} else {
		Item* temp = myArray;
		myArray = new Item[newSize];
		unsigned oldSize = mySize;
		mySize = newSize;

		if (oldSize < newSize) {
			for (unsigned i = 0; i < oldSize; ++i) {
				myArray[i] = temp[i];
			}
			for (unsigned i = oldSize; i < newSize; ++i) {
				myArray[i] = 0;
			}
		} else {
			for (unsigned i = 0; i < newSize; ++i) {
				myArray[i] = temp[i];
			}
		}
		delete [] temp;
	}
}


/* operator method
 * checks to see if mysize is the same as v2 if not return false
 * compares v1 and v2 items if they're not equal it returns false and vice versa
 * both arrays are equal in size and values so return true
 */
bool Vec::operator==(const Vec& v2) const {
	if (myArray == NULL and v2.myArray == NULL){
		return true;
	}
	else if (mySize != v2.mySize){
		return false;
	}
	else if(mySize ==v2.mySize){
		for(unsigned i=0; i<mySize; i++){
			if(myArray[i] != v2.myArray[i]){
				return false;
			}

		}
	}
	return true;
}
/* write to method
 * insert value in myArray
 */
void Vec::writeTo(ostream& out) const {
	for (unsigned i=0; i <mySize; ++i){
		out <<myArray[i] << "\n" <<flush;
	}
}
/* read from method
 * extracts value from  in , stores them in a different item from myArray
 */
void Vec::readFrom(istream& in) {
	for(unsigned i = 0; i <mySize; ++i){
		in >> myArray[i];
	}
}

Vec::~Vec() {
	mySize = 0;
	delete [] myArray;
	myArray = nullptr;

	//cerr << "I won't leak any more memory!! " << endl;
}
const Item Vec::operator[](unsigned index)const {
	if (mySize > index) {
		return myArray [index];
	} else {
		throw range_error ("invalid Index");
	}
}
Item& Vec::operator[](unsigned index) {
	if (mySize > index) {
		return myArray [index];
	} else {
		throw range_error ("invalid Index");
	}
}
/* vector addition
 * sets v3 to equal to 3,6,9
 */
Vec Vec:: operator+(const Vec& v2){
	Vec v3 = *this;
	if (v2.mySize != v3.mySize){
		throw invalid_argument ("invalid Index");
	} else {
		for (unsigned i = 0; i <mySize; ++i){
			v3[i] += v2[i];
		}
		return v3;
	}

}
/*Vector subtraction
 * sets v3 to equal to -1, -2 ,-3
 */

Vec Vec:: operator-(const Vec& v2){
	Vec v3 = *this;
	if (v2.mySize != v3.mySize){
		throw invalid_argument ("invalid Index");
	} else {
		for (unsigned i = 0; i <mySize; ++i){
			v3[i] -= v2[i];
		}
		return v3;
	}
}


