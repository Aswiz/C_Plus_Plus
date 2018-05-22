#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include "../ami/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {
	int size_Array=100,
		min_Array=0,
		max_Array=100;
	float array[size_Array];


	randDigits(array, size_Array, max_Array, min_Array);

	coutArray(array, size_Array, " ", 10, 2);

	//bubbleSort(array, size_Array,0);
	insertionSort(array,size_Array,0);

	coutArray(array, size_Array, " ", 10, 2);

	return 0;
}
