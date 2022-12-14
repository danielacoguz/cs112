/* MatrixTester.h declares test-methods for class Matrix.
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 9/28/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"

class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};



#endif /*MATRIXTESTER_H_*/
