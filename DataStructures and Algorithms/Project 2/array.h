/* array.h declares "C style" array operations.
 * Name: Daniela
 * Date: 09/20/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include <iostream>
#include <cassert>
using namespace std;

void initialize(double *a, unsigned size);

void print(double *a, unsigned size);

double average(double *a, unsigned size);

double sum(double *a, unsigned size);

void read(istream& in, double *a, unsigned size);

void fill(const string& fileName, double *&a, unsigned &numValues); //fill method added

void resize(double *&a, unsigned oldSize, unsigned newSize);  //new size is made with resize

void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3);
