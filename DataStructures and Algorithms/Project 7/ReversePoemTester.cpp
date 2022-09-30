/*
 * ReversePoemTester.cpp
 *
 *  Created on: Nov 1, 2021
 *      Author: ldc6
 */

#include "ReversePoemTester.h"
#include "ReversePoem.h"

void ReversePoemTester::runTests(){
	cout <<"\nTesting ReversePoem..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!"<< endl;
}
/*
 * introduction to each poem is introduced
 */
void ReversePoemTester::testConstructor(){
	cout<< "Constructor is being tested..." <<flush;

	//first filename
	ReversePoem r("poems/poem1.txt");
	cout << " 0 " << flush;

	//second file
	ReversePoem r1("poems/poem2.txt");
	cout << " 1 " << flush;

	//third file
	ReversePoem r2("poems/poem3.txt");
	cout << " 2 " << flush;

	//fourth file
	ReversePoem r3("poems/poem4.txt");
	cout << " 3 " << flush;
	cout <<" Passed! " << endl;

}
/*
 * This Tester assures that the individual poem return the correct title accordingly
 */
void ReversePoemTester::testGetTitle(){
	cout<< "-Testing getTitle..." <<flush;
	//testing title 1
	ReversePoem r("poems/poem1.txt");
	assert(r.getTitle() == "Cats");
	cout << " 0 "  << flush;

	//testing title 2
	ReversePoem r1("poems/poem2.txt");
	assert(r1.getTitle() == "Anorexia");
		cout << " 1 " << flush;
	//testing title 3
	ReversePoem r2("poems/poem3.txt");
	assert(r2.getTitle() == "Keep The Faith");
		cout << " 2 " << flush;
		cout <<" Passed! " << endl;
}
/*
 * returns author by poem according to correct file name
 */
void ReversePoemTester::testGetAuthor(){
	cout<< "-Testing getAuthor..." <<flush;
	//testing author 1
	ReversePoem r("poems/poem1.txt");
	assert(r.getAuthor()=="Leo J. Smada");
	cout <<" 0 " << flush;

	//testing author 2
	ReversePoem r1("poems/poem2.txt");
	assert(r1.getAuthor()== "Anonymous");
	cout<<" 1 " << flush;

	//testing author 3
	ReversePoem r2("poems/poem3.txt");
	assert(r2.getAuthor()== "Tiffany Cheung");
	cout<<" 2 " << flush;
	cout <<" Passed! " << endl;

}
/*
 * obtains actual body from top to bottom of the poem depending on the poem chosen
 */
void ReversePoemTester:: testGetBody(){
	cout<< "-Testing Body..." <<flush;
	//testing Body 1
	ReversePoem b("poems/poem1.txt");
	assert(b.getBody()=="I love it when cats rub against me.\nI could never say\nI hate those purring felines.");
	cout <<" 0 " << endl;

	//testing author 2
	ReversePoem b1("poems/poem2.txt");
	assert(b1.getBody()== "I hate the girl in the mirror\n"
			"so you'll never hear me say that\n"
			"I'm good enough\n"
			"I know in my heart that\n"
			"the number on the scale defines my worth\n"
			"and that\nbeing thin will make me happy\n"
			"I refuse to believe that there is hope I'm ashamed of my body\n"
			"No longer can I say\nI am worth fighting for");
	cout<<" 1 " << endl;
}
/*
 * Reverses poem body testing individual poems
 */
void ReversePoemTester::testGetBodyReversed(){
	cout << "Testing reversed poem..." <<flush;
	//testing BodyReversed 1
		ReversePoem bd("poems/poem1.txt");
		assert(bd.getBodyReverse()=="I could never say\n"
				"I hate those purring felines.\n"
				"I love it when cats rub against me.");
		cout <<" 0 " << endl;


}
