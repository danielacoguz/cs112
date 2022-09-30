/*
 * ReversePoem.cpp
 *
 *  Created on: Nov 1, 2021
 *      Author: ldc6
 */

#include "ReversePoem.h"
/*Constructor to make a reverse poem
 * the parameters hold the string filename with poem
 * Lines are read into a stack
 * Then stack is read form top to bottom in the MybodyReversed to reverse the poem and if the poem is empty it deletes it.
 */

ReversePoem::ReversePoem(const string& poemfile){
	ifstream fin(poemfile);
	assert (fin.is_open());
	string currentline;
//	string emptyline;
	getline (fin, myTitle);
	getline (fin, myAuthor);
	getline(fin, currentline);
	//	Stack<string> poem(1);
	//	string temporary;
	Stack<string> poem(1);
	while(true) {
				if (fin.peek() == EOF) {
					break;
				}
		getline(fin, currentline);
		try {
			poem.push(currentline);
		} catch (const StackException& se){
			poem.setCapacity(2 * poem.getCapacity());
			poem.push(currentline);
		}
		myBody = myBody + currentline + "\n";
//		unsigned tempsize = poem.getSize();
	}
	while (!poem.isEmpty()){
		myBodyReverse = myBodyReverse + poem.pop() + "\n";
	}
	fin.close();
			//		while (!poem.isEmpty() ){

//			//	for (unsigned i=0; i< poem.getSize(); i++){
//			//		myBodyReverse = myBodyReverse + poem.pop() + '\n';

}



