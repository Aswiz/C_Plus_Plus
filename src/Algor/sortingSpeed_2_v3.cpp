#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {

	int size_array = atoi(argv[1]);
	std::cout << endl << size_array << "\t";

	return 0;
}
