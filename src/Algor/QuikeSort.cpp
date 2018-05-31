#include <iostream>
#include <ctime>

#include "../ami/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

	int t[2],
			time_Insertion;

	float time_Insertion_sec;


	int size_array=10,
			min_Array=0,
			max_Array=1000;
	int array[size_array];

	// sortingDigits(array, size_array);
	randDigits(array, size_array, max_Array, min_Array);
	coutArray(array, size_array, " ", 10, 2);

	t[0] = clock();
	// quickSort(array, 0, size_array-1);
	// BubbleSortFlag(array, size_array-1, 0);
	BubbleSort(array, size_array-1, 0);
	t[1] = clock();

	coutArray(array, size_array, " ", 10, 2);


	time_Insertion = t[1] - t[0];
	time_Insertion_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	cout << "time_Insertion: " << time_Insertion << endl;
	


		return 0;
}
//
// g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
