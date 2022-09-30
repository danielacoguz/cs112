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

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	const unsigned getRows() const;
	const unsigned getColumns() const;
	const Vec<Item>& operator[](unsigned row) const;
	Vec<Item>& operator[](unsigned row);
	bool operator==(const Matrix& m2) const;

private:
    unsigned         myRows;
    unsigned         myColumns;
    Vec< Vec<Item> > myVec;
    friend class MatrixTester;
};

#endif
