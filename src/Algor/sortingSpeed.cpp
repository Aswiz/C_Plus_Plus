#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {
	int t[2]; 

	int size_Array = atoi(argv[1]),
			min_Array = 0,
			max_Array = 100;
	float array[size_Array];


	randDigits(array, size_Array, max_Array, min_Array);

	coutArray(array, size_Array, " ", 20, 2);

	t[0] = clock();
	insertionSort(array,size_Array,0);
	t[1] = clock();

	coutArray(array, size_Array, " ", 20, 2);
	usleep(1000000);
	system("clear");
	std::cout << "t[0] = " << t[0] << '\n';
	std::cout << "t[1] = " << t[1] << '\n';
	std::cout << "t = " << t[1] - t[0] << '\n';
	std::cout << "t(sec) = " << (float(t[1] - t[0])) / CLOCKS_PER_SEC<< '\n';

	return 0;
}
