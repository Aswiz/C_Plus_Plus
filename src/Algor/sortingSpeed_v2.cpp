#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {
	int t[2]; 

	int size_array = atoi(argv[1]),
			min_Array = 0,
			max_Array = 1000,
			time_Insertion,
			time_Selection,
			time_Bubble,
			time_Quick;
	float array_Insertion[size_array],
				array_Selection[size_array],
				array_Bubble[size_array],
				array_Quick[size_array],
				time_Insertion_sec,
				time_Selection_sec,
				time_Bubble_sec,
				time_Quick_sec;


	randDigits(array_Insertion, size_array, max_Array, min_Array);
	for (int i = 0; i < size_array; ++i)
	{
		array_Selection[i] = array_Insertion[i];
		array_Bubble[i] = array_Insertion[i];
		array_Quick[i] = array_Insertion[i];
	}

	t[0] = clock();
	insertionSort(array_Insertion,size_array,0);
	t[1] = clock();
	time_Insertion = t[1] - t[0];
	time_Insertion_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("InsertionSort","Random",size_array,time_Insertion,time_Insertion_sec);

	t[0] = clock();
	SelectionSort(array_Selection,size_array,0);
	t[1] = clock();
	time_Selection = t[1] - t[0];
	time_Selection_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("SelectionSort","Random",size_array,time_Selection,time_Selection_sec);

	t[0] = clock();
	BubbleSort(array_Bubble,size_array,0);
	t[1] = clock();
	time_Bubble = t[1] - t[0];
	time_Bubble_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("BubbleSort","Random",size_array,time_Bubble,time_Bubble_sec);

	return 0;
}
