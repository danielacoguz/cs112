/* ListTester.cpp defines the test methods for class List.
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 10/7/2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testInequality();
	testReadFromStream();
	testWriteToStream();
	testReadFromFile();
	testWriteToString();
	testPrepend();
	testInsert();
	testgetIndexOf();
	testRemove();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == 0 );
	assert( aNode.myNext == nullptr );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, nullptr );
	assert( n1.myItem == 11 );
	assert( n1.myNext == nullptr );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, nullptr);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == nullptr );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast != nullptr );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != nullptr );
	assert( aList.myLast->myNext == nullptr );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast != nullptr );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == nullptr );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == nullptr );
	assert( list2.myLast == nullptr );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == nullptr );
	assert( list2.myLast == nullptr );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == nullptr );
	assert( list6.myLast == nullptr );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}
// Project 5 //

/*Done by: John Cho
 * equality test
 */
void ListTester::testEquality(){
	cout <<"Testing equality ..." << flush;
	List<double> list0;
	List<double> list1;
	List<double> list3;

	//case when both are empty
	assert(list0 == list1);
	cout << " 0 " << flush;
	for (unsigned i = 0; i <3; ++i){
		list0.append(i+1);
	}

	//one empty list with one that has items
	assert(!(list0 == list1));
	cout << " 1 " << flush;

	//both with items and equal :)
	for (unsigned i = 0; i<3; ++i){
		list1.append(i+1);
	}
	assert (list0==list1);
	cout << " 2 " << flush;

	//equal size BUT not the same values
	for (unsigned i= 0 ; i<3; ++i){
		list3.append(i+10);
	}
	assert(!(list1==list3));
	cout << " 3 " << flush;

	//finished all tests
	cout<< "Passed!" << endl;

}
/*Done By: Daniela C
 *Inequality test
 */
void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	// empty
	List<double> list1;
	List<double> list2;
	assert(!(list1!=list2));
	cout << " 1 " << flush;

	//non-empty same size
	List<double> list3;
	List<double> list4;
	for (unsigned i=0; i<3 ; i++){
		list3.append(i+1);
	}
	for (unsigned i=0; i<3 ; i++){
		list4.append(i+2);
	}
	assert(list3!=list4);
	cout << " 2 " << flush;

	//different size
	List<double> list5;
	List<double> list6;
	list6.append(5);
	assert(list5!=list6);
	cout << " 3 " << flush;

	//non-empty same size
	List<double> list7;
	List<double> list8;
	for (unsigned i=0; i<3 ; i++){
		list7.append(i+1);
	}
	for (unsigned i=0; i<3 ; i++){
		list8.append(i+1);
	}
	assert(!(list7!=list8));
	cout << " 4 " << flush;
	cout << "Passed!" << endl;
}
/*Done by: John Cho
 * ReadFromStream test
 */
void ListTester::testReadFromStream(){
	cout << "Testing readFrom(istream) ... " << flush;
	ifstream cin("ListTest1.txt");
	assert (cin.is_open());


	List<double> list1;
	assert (list1.getSize() == 0);
	list1.readFrom(cin);
	assert(list1.getSize() == 5);
	cout << "1" << flush;

	assert (list1.myFirst->myItem == 11);
	assert (list1.myFirst->myNext->myItem == 22);
	cout << "2" << flush;

	for (unsigned i; i < list1.getSize();i++){
		assert (list1.myFirst->myItem == i+10);

	}
	cin.close();
	cout << "3" << flush;
	cout << "passed!" <<  endl;


}
/* John Cho
 * Read from File test
 */
void ListTester::testReadFromFile(){
	cout << "Testing readFrom(string)... " << flush;
	List<double> list1;
	list1.readFrom("ListTest1.txt");
	assert(list1.getSize() == 5);
	assert(list1.myFirst->myItem == 11);
	assert(list1.myFirst->myNext ->myItem  == 22);
	assert(list1.myFirst->myNext-> myNext ->myItem  == 33);
	assert(list1.myFirst->myNext-> myNext -> myNext ->myItem  == 44);
	assert(list1.myLast->myItem  == 55);

	List<double> list2;
	list2.append(10);
	list2.readFrom("ListTest2.txt");
	assert(list2.getSize() == 5);
	assert(list2.myFirst->myItem == 10);
	assert(list2.myFirst->myNext-> myNext ->myItem  == 30);
	assert(list2.myFirst->myNext-> myNext -> myNext ->myItem  == 40);
	assert(list2.myLast->myItem  == 50);

	assert(list1.myFirst!=list2.myFirst);

	cout << "Passed!" << endl;
}
/*John Cho
 *WriteToStream test
 */
void ListTester::testWriteToStream(){
	cout << "Testing writeTo(ostream)... " << flush;
	List<double> l1;
	l1.readFrom("ListTest1.txt");
	ofstream fout("ListTest1Copy.txt");
	assert(fout.is_open());

	l1.writeTo(fout);
	fout.close();

	List<double> l2;
	l2.readFrom("ListTest1Copy.txt");

	assert(l2.getSize() == 5);
	assert(l1.myFirst->myItem == l2.myFirst->myItem);
	assert(l1.myFirst->myNext->myItem == l2.myFirst->myNext->myItem);
	assert(l1.myFirst->myNext->myNext->myItem == l2.myFirst->myNext->myNext->myItem);
	assert(l1.myLast->myItem == l2.myLast->myItem);

	cout << "Passed!" << endl;

}
/*Done by: Daniela C
 *Write To String tester
 */
void ListTester::testWriteToString(){
	cout<< "Testing writeTo(string) ..." << flush;
	List<double> list0;
	List<double> list1;
	for (unsigned i = 1; i<6; i++){
		list0.append(i);
		list1.append(i*2);
	}
	list0.writeTo("ListTestWrite1.txt");
	list1.writeTo("ListTestWrite2.txt");

	ifstream fin1("ListTestWrite1.txt");
	ifstream fin2("ListTestWrite2.txt");

	double list1Item, list2Item;
	for (unsigned i = 1; i<6; ++i){
		fin1 >> list1Item;
		fin2 >> list2Item;
		assert( list1Item == i);
		assert (list2Item ==i*2);
	}
	fin1.close();
	fin2.close();
	cout<< " Passed!" <<endl;

}
/*Done by: John Cho
 * Prepend method test
 */
void ListTester::testPrepend(){
	cout << "Testing prepend()..." <<flush;
	//empty case
	List<double> list0;
	list0.prepend(1);
	assert (list0.myFirst != nullptr);
	assert (list0.myLast != nullptr);
	assert (list0.myFirst == list0.myLast);
	assert (list0.myFirst->myItem ==1);
	assert( list0.myFirst->myNext == nullptr);
	cout << " 0 " << flush;

	//not empty
	list0.prepend(3);
	assert (list0.myFirst != nullptr);
	assert (list0.myLast != nullptr);
	assert (list0.myFirst != list0.myLast);
	assert (list0.myFirst->myItem ==3);
	assert( list0.myFirst->myNext == list0.myLast);
	assert (list0.myFirst->myNext->myItem == list0.myLast->myItem);
	assert (list0.myLast->myItem ==1);
	assert( list0.myLast == list0.myFirst->myNext);
	cout << " 1 " << flush;
	cout << " Passed! " << endl;
}
/*Done by:Daniela C
 * Insert method test
 */
void ListTester::testInsert(){
	cout <<"Testing Insert()... " <<flush;

	//empty case first
	List<double> list;
	list.insert(5, 0);
	assert( list.myFirst != NULL );
	assert( list.myLast != NULL );
	assert( list.myFirst == list.myLast );
	assert( list.myFirst->myItem == 5 );
	assert( list.myFirst->myNext == NULL);
	assert( list.mySize == 1);
	cout << " 0 " << flush;

	// Non-empty index too large
	list.insert(6, 2000);
	assert( list.myFirst != list.myLast );
	assert( list.myFirst->myItem == 5 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext == NULL );
	assert( list.mySize == 2);
	cout << " 1 " << flush;

	// Non-empty index negative
	list.insert(4, -1000);
	assert( list.myFirst->myItem == 4 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext == NULL );
	assert( list.mySize == 3);
	cout << " 2 " << flush;

	// Non-empty index 0
	list.insert(3,0);
	assert( list.myFirst->myItem == 3 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 4 );
	assert( list.myFirst->myNext->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext == NULL );
	assert( list.mySize == 4);
	cout << " 3 " << flush;

	// Non-empty in range index
	list.insert(20, 2);
	assert( list.myFirst->myItem == 3 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 4 );
	assert( list.myFirst->myNext->myNext->myItem == 20 );
	assert( list.myFirst->myNext->myNext->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext->myNext == NULL );
	assert( list.mySize == 5);
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}

/*Done by: John Cho
 * get index of test
 */
void ListTester::testgetIndexOf(){
	cout << "Testing getIndexOf()... " << flush;
	//empty list
	List<double> l1;
	assert(l1.getIndexOf(5)==-1);
	cout<< " 1 " <<flush;

	//non-empty, valid element
	List<double> l2;
	for (unsigned i=0; i<3 ; i++){
		l2.append(i+1);
	}

	assert(l2.getIndexOf(1)==0);
	assert(l2.getIndexOf(2)==1);
	assert(l2.getIndexOf(3)==2);
	cout<< " 2 " <<flush;
	//non-empty, invalid element
	assert(l2.getIndexOf(4)==-1);
	cout<< " 3 " <<flush;

	List<double> l3;
	l3.append(12);
	l3.append(5);
	l3.append(9);
	l3.append(0);

	assert(l3.getIndexOf(12)==0);
	assert(l3.getIndexOf(9)==2);
	assert(l3.getIndexOf(5)==1);
	assert(l3.getIndexOf(0)==3);
	cout<< " 4 " <<flush;

	//non-empty, invalid element
	assert(l3.getIndexOf(4)==-1);
	cout<< " 5 " <<flush;
	cout<<"Passed!" << endl;
}
/*Done by: John Cho
 *remove test
 */
void ListTester::testRemove(){
	cout << "Testing remove()..." << flush;

	// empty list
	List<double> l1;
	try{
		l1.remove(0);
		cerr << "Index worked with empty list" << flush;
		exit(1);
	}
	catch(range_error&){
		cout << " 1 " << flush;
	}

	//negative index
	List<double> l2;
	for (unsigned i=0; i<3 ; i++){
		l2.append(i+1);
	}
	assert(l2.remove(-4) == 1);
	assert(l2.myFirst->myItem ==2);
	assert(l2.getSize() == 2);
	cout << " 2 " << flush;

	// 0 index
	List<double> l3;
	for (unsigned i=0; i<3 ; i++){
		l3.append(i+1);
	}
	assert(l3.remove(0) == 1);
	assert(l3.myFirst->myItem == 2);
	assert(l3.getSize() == 2);
	assert(l3.myFirst!=NULL);
	assert(l3.myFirst->myNext->myItem ==3);
	cout << " 3 " << flush;

	// index between 0 and mySize-1
	List<double> l4;
	for (unsigned i=0; i<5 ; i++){
		l4.append(i+1);
	}
	assert(l4.remove(1)==2);
	assert(l4.getSize()==4);
	assert(l4.myFirst!=NULL);
	assert(l4.myFirst->myItem == 1);
	assert(l4.myFirst->myNext->myItem ==3);
	//remove the element at index 1 again
	assert(l4.remove(1)==3);
	assert(l4.getSize()==3);
	assert(l4.myFirst!=NULL);
	assert(l4.myFirst->myItem == 1);
	assert(l4.myFirst->myNext->myItem ==4);
	cout << " 4 " << flush;

	// index= mySize
	List<double> l5;
	for (unsigned i=0; i<5 ; i++){
		l5.append(i+1);
	}
	assert(l5.remove(5)==5);
	assert(l5.getSize()==4);
	assert(l5.myFirst->myItem==1);
	assert(l5.myLast->myItem==4);
	assert(l5.myFirst->myNext->myItem == 2);

	//index > mySize
	List<double> l6;
	for (unsigned i=0; i<5 ; i++){
		l6.append(i+1);
	}
	assert(l6.remove(10)==5);
	assert(l6.getSize()==4);
	assert(l6.myFirst->myItem==1);
	assert(l6.myLast->myItem==4);
	assert(l6.myFirst->myNext->myItem == 2);

	// check equality with another list after removing
	List<double> l7;
	List<double> l8;
	l7.append(5);
	l7.append(5);
	l8.append(5);
	l7.remove(5);
	assert(!(l7!=l8));
	cout << " 5 " << flush;
	cout<<"Passed!" << endl;
}
