/*
 * ReversePoem.h
 *
 *  Created on: Nov 1, 2021
 *      Author: ldc6
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_
#include <string>
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

class ReversePoem {
public:
	ReversePoem(const string& poemfile);
//	virtual ~ReversePoem();
	const string getTitle()const {return myTitle;}
	const string getAuthor()const {return myAuthor;}
	const string getBody()const {return myBody;}
	const string getBodyReverse()const{return myBodyReverse;}
private:
	string myTitle = "";
	string myAuthor = "";
	string myBody = "";
	string myBodyReverse = "" ;
	friend class ReversePoemTester;

};

#endif /* REVERSEPOEM_H_ */
