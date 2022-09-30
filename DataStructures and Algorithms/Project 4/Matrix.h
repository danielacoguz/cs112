/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 9/28/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vec.h"

typedef double Item;
template<class Item>

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	const unsigned getRows() const;
	const unsigned getColumns() const;
	const Vec<Item>& operator[](unsigned row) const;
	Vec<Item>& operator[](unsigned row);
	bool operator==(const Matrix& m2) const;
	bool  operator !=(const Matrix& m2) const;
	void  readFrom (istream& fin);
	void  writeTo(const string& fileName);

private:
    unsigned         myRows;
    unsigned         myColumns;
    Vec< Vec<Item> > myVec;
    friend class MatrixTester;
};
//Default Constructor
template<class Item>
Matrix<Item::Matrix()
	myRows = myColumns = 0;
}

//Explicit Constructor
template<class Item>
Matrix <Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}
template<class Item>
const unsigned Matrix<Item>::getRows() const {
	return myRows;
}
template<class Item>
const unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

template<class Item>
Vec<Item>& Matrix::operator[](unsigned index) {
	if ( index >= myRows ) {
		throw range_error("receives bad index value");
	}
	return myVec[index];

}
template<class Item>
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if ( index >= myRows ) {
		throw range_error("Invalid index.");
	}
	return myVec[index];
}
template<class Item>
bool Matrix::operator==(const Matrix<Item>& m2) const {
      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
           return false;
      } else {
           return myVec == m2.myVec;
      }
   }
template<class Item>
bool Matrix<Item>::operator !=(const Matrix<Item>& m2) const {
      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
           return true;
      } else {
           return myVec != m2.myVec;
      }
   }
void Matrix<Item>::readFrom (istream& fin){
	for(unsigned i = 0 ; i <myRows; ++i) {
		for(unsigned j=0; j <myColumns; ++j)
			fin >> myVec [i][j];
	}
}
template<class Item>
void Matrix<Item::writeTo(const string& fileName) {
	ofstream fout(fileName);
	assert(fout.is_open());
	fout << myRows << "\t" << myColumns << flush;
	for (unsigned i=0; i< myRows; i++) {
		fout <<"\n";
		for (unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << "\t";
		}
	}
	fout.close();
}
	}
}
#endif
