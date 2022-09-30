/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin University.
 */
 
//#include "StackTester.h"
//
//int main() {
//	StackTester st;
//	st.runTests();
//}
//
#include "ReversePoem.h"
#include <iostream>
//#include "StackTester.h"
//#include "ReversePoemTester.h"
using namespace std;
int main() {
//	ReversePoemTester rpt;
//	rpt.runTests();
//	Stacktester st;
//	st.runTests();

	cout << "\nEnter the name of the poem file: ";
	string poemFile;
	cin >> poemFile;

	ReversePoem reversePoem(poemFile);
	cout << reversePoem.getTitle() << "\n"
			<< reversePoem.getAuthor() << "\n"
			<< "\n*** Top-To-Bottom ***\n\n"
			<< reversePoem.getBody()
			<< "\n*** Bottom-To-Top ***\n\n"
			<< reversePoem.getBodyReverse()
			<< endl;
}
