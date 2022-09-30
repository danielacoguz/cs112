/* ListTester.h declares the test-class for class List.
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 10/7/2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testReadFromStream();
	void testWriteToStream();
	void testReadFromFile();
	void testWriteToString();
	void testPrepend();
	void testInsert();
	void testgetIndexOf();
	void testRemove();
};

#endif /*LISTTESTER_H_*/
