/*
 * pelindrome.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: ldc6
 */
#include "PalindromeTester.h"

//#include "palindrometester.h"
#include <cctype>

palindrome::palindrome(const string& fileNameIn, const string& fileNameOut) {
	fileIn = fileNameIn;
	fileOut = fileNameOut;
	palindromeDetector(fileIn, fileOut);
}
/*
 * string palindrome is the parameter
 * Here, this method turns strings into lower cases then pushes them into a stack
 * Then they are appended on the Queue.Then we use pop and remove to remove from the queue into chracter2
 * finally if character1 and character2 are different then we break
 */
bool palindrome::isPalindrome( const string& palindrome){
	if(palindrome.length() == 0){
		return false;
	}
	Stack<char>ch1(1);
	ArrayQueue<char>sh1(1);
	for (unsigned i=0; i <palindrome.length(); i++){
		if(isalpha(palindrome[i])){
			try{
				sh1.append(tolower(palindrome[i]));
			}catch (FullQueueException& se){
				sh1.setCapacity(sh1.getCapacity() * 2);
				sh1.append(tolower(palindrome[i]));
			}
			try{
				ch1.push(tolower(palindrome[i]));
			}catch (StackException& se){
				ch1.setCapacity(sh1.getCapacity() * 2);
				ch1.push(tolower(palindrome[i]));
			}
		}

	}
	char character1;
	char character2;
	unsigned lenght = sh1.getSize();
	for(unsigned i=0; i < lenght; i++){
		character1 = ch1.pop();
		character2 = sh1.remove();
		if( character1 != character2){
			return false;
		}
	}
	return true;
}
/*
 * pelindromeDetector
 * Param: string FileNameIn, fileNameOut
 * The palindromeDetector reads lines
 * The *** are written on these
 * When a palindrome is spotted they are written in the FileOut
 */
void palindrome::palindromeDetector(const string& fileNameIn, const string& fileNameOut){
	ifstream fin(fileNameIn);
		ofstream fout(fileNameOut);
		string currentString;
		while(fin){
			getline(fin, currentString);

			if(isPalindrome(currentString)){//detects if line is a palindrome
				fout << currentString + " ***" << endl;
			}else{
				fout<< currentString <<endl;//leaves line alone
			}
		}
		fin.close();
		fout.close();
}




