#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {
// 
// typeSorting: 1 - InsertionSort
// 							2 - SelectionSort
// 							3 - BubbleSort
// 							4 - QuickSort
// 
// typeData:    1 - randDigits
// 							2 - 0,1,2
// 							3 - sortingDigits
// 
	int	typeSorting = atoi(argv[1]);


	if (typeSorting==1)
	{
		cout << "InsertionSort" << endl;
	}
	else if (typeSorting==2)
	{
		cout << "SelectionSort" << endl;
	}
	else if (typeSorting==3)
	{
		cout << "BubbleSort" << endl;
	}
	else if (typeSorting==4)
	{
		cout << "QuickSort" << endl;
	}

	cout << "Numbers\t" << "RandomDigits\t" << "Random012\t" << "SortingDigits";

	return 0;
}
