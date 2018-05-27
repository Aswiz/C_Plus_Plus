#include <iostream>
#include <ctime>

#include "../ami/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {


		int size_array=10,
				min_Array=0,
				max_Array=100;
		float array[size_array];

		randDigits(array, size_array, max_Array, min_Array);
		coutArray(array, size_array, " ", 10, 2);

		QuickSorting(array, 0, size_array-1);

		coutArray(array, size_array, " ", 10, 2);


		return 0;
}
//
// g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
