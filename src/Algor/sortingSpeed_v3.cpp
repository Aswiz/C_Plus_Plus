#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {

	int t[2]; 

// typeSorting: 1 - InsertionSort
// 							2 - SelectionSort
// 							3 - BubbleSort
// 							4 - QuickSort
// 							5 - BubbleSortFlag
// 
// typeData:    1 - randDigits
// 							2 - 0,1,2
// 							3 - sortingDigits

	int size_array  = atoi(argv[1]),
			typeSorting = atoi(argv[2]),
			typeData    = atoi(argv[3]),
			min_Array = 0,
			max_Array = 32000,
			time_Insertion,
			time_Selection,
			time_Bubble,
			time_Quick,
			time_BubbleFlag,
			array_Quick[size_array];
	float array_Insertion[size_array],
				array_Selection[size_array],
				array_Bubble[size_array],
				array_BubbleFlag[size_array],
				time_Insertion_sec,
				time_Selection_sec,
				time_Bubble_sec,
				time_BubbleFlag_sec,
				time_Quick_sec;

if (typeData==1)
{
	randDigits(array_Insertion, size_array, max_Array, min_Array);
}
else if (typeData==2)
{
	randDigits(array_Insertion, size_array, 2, 0);
}
else if (typeData==3)
{
	sortingDigits(array_Insertion, size_array);
}

for (int i = 0; i < size_array; ++i)
{
	array_Selection[i] = array_Insertion[i];
	array_Bubble[i] = array_Insertion[i];
	array_BubbleFlag[i] = array_Insertion[i];
	array_Quick[i] = array_Insertion[i];
}
if (typeSorting==1)
{
	t[0] = clock();
	insertionSort(array_Insertion,size_array,0);
	t[1] = clock();
	time_Insertion = t[1] - t[0];
	time_Insertion_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("InsertionSort","Random",size_array,time_Insertion,time_Insertion_sec);
}
else if (typeSorting==2)
{
	t[0] = clock();
	SelectionSort(array_Selection,size_array,0);
	t[1] = clock();
	time_Selection = t[1] - t[0];
	time_Selection_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("SelectionSort","Random",size_array,time_Selection,time_Selection_sec);
}
else if (typeSorting==3)
{
	t[0] = clock();
	BubbleSort(array_Bubble,size_array,0);
	t[1] = clock();
	time_Bubble = t[1] - t[0];
	time_Bubble_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("BubbleSort","Random",size_array,time_Bubble,time_Bubble_sec);
}
else if (typeSorting==4)
{
	t[0] = clock();
	quickSort(array_Quick,0,size_array);
	t[1] = clock();
	time_Quick = t[1] - t[0];
	time_Quick_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("QuickSort","Random",size_array,time_Quick,time_Quick_sec);
}
else if (typeSorting==5)
{
	t[0] = clock();
	BubbleSortFlag(array_BubbleFlag,size_array,0);
	t[1] = clock();
	time_BubbleFlag = t[1] - t[0];
	time_BubbleFlag_sec = (float(t[1] - t[0])) / CLOCKS_PER_SEC;
	coutSortingSpeed("BubbleSortFlag","Random",size_array,time_BubbleFlag,time_BubbleFlag_sec);}


	return 0;
}
