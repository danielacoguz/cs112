
#include "BST_Tester.h"
#include <cassert>
#include <fstream>
#include <string>
int main() {
	BST_Tester bstt;
	bstt.runTests();	

	ifstream fin("File.txt");
	assert( fin.is_open() );



	unsigned doubled = 0; //starts at zero and counting
	while(fin){
		string filesOpen = "";
		getline(fin, filesOpen);
		if(filesOpen == "") break;	 //if line is blank it breaks
		ifstream file1(filesOpen);
		assert( file1.is_open()) ; //read files from the .txt

		doubled = 0;
		long String = 0;
		BST<long> s1;
		s1.~BST();

		while(file1){
			file1 >> String;
			try{
				s1.insert(String);
			}catch (Exception& je){
				doubled++;
			}
		}
		cout << "Height" << filesOpen << " is "
				<< s1.getHeight() << " holds "
				<< doubled << " doubles" << endl;
		file1.close();
	}
	fin.close();




}
