/* Vec.h provides a simple vector class named Vec.
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 9/28/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;

//typedef double Item;
template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec &original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec &v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in) const;
	virtual ~Vec();
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec<Item> &v2) const;
	Vec operator+(const Vec& v2);
	Vec operator-(const Vec& v2);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;

}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;

	if (mySize > 0) {
		myArray = new Item[mySize];
		for(unsigned i = 0; i < mySize; ++i ) {
			myArray[i] = 0;
		}
	} else { myArray = nullptr; }

}

template<class Item>
Vec<Item>::Vec(const Vec<Item> &original) {
	mySize = original.mySize;
	myArray = new Item[mySize];

	if (original.mySize > 0) {
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	else { myArray = nullptr; }
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (myArray == original.myArray) {
		return *this;
	}
	else if (original.mySize == 0) {
		mySize = 0;
		delete[] myArray;
		myArray = nullptr;
		return *this;
	}
	else {
		mySize = original.mySize;
		delete[] myArray;
		myArray = new Item[mySize];

		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
		return *this;
	}
}

template<class Item>
Vec<Item>::~Vec() {
	if (mySize > 0) {
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = 0;
		}
	} else { myArray = nullptr; }
	mySize = 0;
	delete[] myArray;
	myArray = nullptr;
}

template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index >= mySize || index < 0 || mySize == 0) {
		throw range_error("Selected index is outside of Vec Range.");
	}
	else {
		myArray[index] = it;
	}
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index >= mySize || index < 0 || mySize == 0) {
		throw range_error("Selected index is outside of Vec Range.");
	}
	else {
		return myArray[index];
	}
}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize == 0) {
		mySize = newSize;
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = 0;
		}
	}
	else if (newSize == 0) {
		mySize = 0;
		delete[] myArray;
		myArray = nullptr;
	}
	else  if (newSize == mySize) {

	}
	else {
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
		}
		else {
			for (unsigned i = 0; i < newSize; ++i) {
				myArray[i] = temp[i];
			}
		}
		delete[] temp;
	}
}

template<class Item>
bool Vec<Item>::operator==(const Vec<Item> &v2) const{
	if (this->mySize != v2.mySize) return false;
	for (unsigned i = 0; i < mySize; ++i) {
		if (this->myArray[i] != v2.myArray[i]) return false;
	}
	return true;
}

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << endl;

	}
}

template<class Item>
void Vec<Item>::readFrom(istream& in) const {
	for (unsigned i = 0; i < mySize; ++i) {
		in >> myArray[i];
	}
}

template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const{
	if (index >= mySize) {
		throw range_error("bad");
	}
	return myArray[index];
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("bad");
	}
	return myArray[index];
}

template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("Vec objects must be of equal size to add.");
	} else {
		Vec<Item> v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
		}
		return v3;
	}
}

template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2){
	if (mySize != v2.mySize) {
		throw invalid_argument("Vec objects must be of equal size to subtract.");
	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] - v2.myArray[i];
		}
		return v3;
	}
}

template<class Item>
bool Vec<Item>::operator!=(const Vec<Item> &v2) const {
	if (myArray == NULL and v2.myArray == NULL) {
		return false;
	} else if (mySize != v2.mySize) {
		return true;
	} else if (mySize == v2.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}

	}
	return false;
}

#endif /*VEC_H_*/
