/*
 * pelindrome.h
 *
 *  Created on: Nov 19, 2021
 *      Author: ldc6
 */
#include "Stack.h"
#include "ArrayQueue.h"
#include <fstream>
#include <cassert>
#include <cstdlib>

#ifndef PALINDROME_H_
#define PALINDROME_H_
using namespace std;

class palindrome{

public:
	palindrome(const string& fileNameIn, const string& fileNameOut);
	bool isPalindrome( const string& palindrome);
	void palindromeDetector(const string& fileNameIn, const string& fileNameOut);

private:
	string fileIn;
	string fileOut;

};

#endif /* PALINDROME_H_ */
