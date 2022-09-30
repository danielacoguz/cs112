/*
 * PalindromeTester.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: ldc6
 */

#include "PalindromeTester.h"
#include <cassert>

void PalindromeTester::runTests() {
	cout << "Running Tester..." << endl;
	testIsPalindrome();
	testPalindromeDetector();
	cout << "Passed All Tests!" << endl;
}
/*
 * this tester checks for palindromes that could be written differently
 */
void PalindromeTester::testIsPalindrome(){
	cout << "Testing isPalindrome()..." << flush;
	palindrome q("FileIn.txt", "FileOut.txt");
	assert(!q.isPalindrome(""));
	cout << " 0 " << flush;
	string d1 = "madam";
	assert(q.isPalindrome(d1));
	cout << " 1 " << flush;
	string d2 = "m A Dam";
	assert(q.isPalindrome(d2));
	cout << " 2 " << flush;
	string d3 = "m ADam";
	assert(q.isPalindrome(d3));
	cout << " 3 " << flush;
	string d4 = "MADAM";
	assert(q.isPalindrome(d4));
	cout << " 4 " << flush;
	string d5 = "The learned men of Rome";
	assert(!q.isPalindrome(d5));
	cout << " 5" << flush;
	cout << " Passed! " << endl;
}
/*
 * This tester adds *** on the palindromes and detects them in the tile
 */
void PalindromeTester::testPalindromeDetector(){
	cout << "Testing PalindromeDetector()..." << endl;
	palindrome r("charactersIn.txt", "charactersOut.txt");
	ifstream fin("charactersIn.txt");
	ifstream fout("charactersOut.txt");
	string tempIn, tempOut;
		while(fin){
			getline(fin, tempIn);
			getline(fout, tempOut);
			if(r.isPalindrome (tempIn)){
				assert(tempOut == tempIn + " ***");
			}else if (!r.isPalindrome(tempIn)){
				assert(tempOut == tempIn + "");
			}else{
				assert(false);
			}

	}
		fin.close();
		fout.close();
		cout << "Tests Passed" << endl;

}
