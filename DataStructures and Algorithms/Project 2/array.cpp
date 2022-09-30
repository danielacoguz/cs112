/* array.cpp defines "C style" array operations
 * Name: Daniela Contreras
 * Date: 09/21/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include "array.h"
#include <fstream>

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; ++i) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i< size; ++i) {
		sum += *a ;
		a++;
	}
	return sum/size;
}
/* this is the method for sum
 * @param: double *a,
 * unsigned size
 * returns sum values
 */
double sum(double *a, unsigned size){
        //returns sum
        double sum = 0;
        for (int i = 0; i < size; i++) {
	                sum = sum + *a;
                        a++;
        }
	return sum;

}
/* Read method takes in size values from in and store them in a
  * @param:size
  * @param : double * a, an array
  * type address and size
  */
void read(istream& in, double *a, unsigned size){
        //reads size values from in and stores
        for (int i = 0; i < size; i++) {
                string value;
                getline(in, value);
                a[i] = atoi( value.c_str() );
        }
}
/* Fill method opens an ifstream to fileName, integer is read from the file into numValues
 * This finds the numValues double values by storing in a the address then reading values from the file
 * finally stores them then closes the ifstream
 * @param: const string, fileName,
 * @param: doubles*a, unsigned  &numValues
  * then returns void
  */

void fill(const string& fileName, double *&a, unsigned &numValues){
        ifstream fin(fileName.c_str());
        assert( fin.is_open() );

        string value;
        getline(fin, value);
        numValues = atoi( value.c_str() );
        delete[] a;
        a = new double[numValues];
        for (int i = 0; i < numValues; i++) {
        getline(fin, value);
        a[i] = atoi( value.c_str() );
                }
        fin.close();
}
/* resize method from old to new size
 * newSize must be > oldSize that way
 * deleting old array will prevent leak of memory
 * old size is included
 * then new size is introduced
 */
void resize(double *&a, unsigned oldSize, unsigned newSize){
        double *anArray = new double[newSize];
        if (newSize>oldSize){
           for (int i = 0; i < oldSize; i++){
                   anArray[i] = a[i];
           }
        }
        else if (oldSize > newSize){
                for (int i = 0; i < newSize; i++){
                    anArray[i] =a[i];
                           }
        }
        else if (oldSize==newSize){
		for (int i = 0; i < newSize; i++){
				anArray[i] =a[i];
	}
        }
        delete[] a;
	a = anArray;

}
/* concat method
 * parameter includes the array a1 and a2 with the sizes vice versa.
 * Then array a3 is passed back which contains values brought from a1
 * so technically whatever size 3 gets it is equal to size1 and size2
 * We can tell that an address is pointing at an old address if NULL is not included..
 * therefore memory leak can be avoided by adding NULL
 */
void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3){
        if (a3!=NULL){
                delete[] a3;
        }
        size3 = size1+size2;
         a3 = new double[size3];
         for (unsigned i = 0; i < size1; i++){
                 a3[i] = a1[i];
         }
         for (unsigned i = size1; i < size3; i++){
		 a3[i] = a2[i-size1];
	 }
}

