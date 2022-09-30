///* Matrix.cpp defines Matrix class methods.
// * Student Name: John Cho
// * Student Name: Daniela Contreras ldc6
// * Date: 9/28/21
// * Begun by: Joel C. Adams, for CS 112 at Calvin University.
// */
//
//#include "Matrix.h"
//
////Default Constructor
//Matrix::Matrix() {
//	myRows = myColumns = 0;
//}
//
////Explicit Constructor
//Matrix::Matrix(unsigned rows, unsigned columns) {
//	myRows = rows;
//	myColumns = columns;
//	myVec.setSize(rows);
//	for (unsigned i = 0; i < rows; i++) {
//		myVec[i].setSize(columns);
//	}
//}
//
//const unsigned Matrix::getRows() const {
//	return myRows;
//}
//
//const unsigned Matrix::getColumns() const {
//	return myColumns;
//}
//
//
//Vec<Item>& Matrix::operator[](unsigned index) {
//	if ( index >= myRows ) {
//		throw range_error("receives bad index value");
//	}
//	return myVec[index];
//
//}
//const Vec<Item>& Matrix::operator[](unsigned index) const {
//	if ( index >= myRows ) {
//		throw range_error("Invalid index.");
//	}
//	return myVec[index];
//}
//
//bool Matrix::operator==(const Matrix& m2) const {
//      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//           return false;
//      } else {
//           return myVec == m2.myVec;
//      }
//   }
//bool Matrix<Item>::operator !=(const Matrix<Item>& m2) const {
//      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//           return true;
//      } else {
//           return myVec != m2.myVec;
//      }
//   }
//void Matrix<Item>::readFrom (istream& fin){
//	for(unsigned i = 0 ; i <myRows; ++i) {
//		for(unsigned j=0; j <myColumns; ++j)
//			fin >> myVec [i][j];
//		return
//
//	}
//}
//
