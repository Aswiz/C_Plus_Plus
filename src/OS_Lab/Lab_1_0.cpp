#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "labOS.h"

using namespace std;

int main(int argc, char *argv[]) {
	system("clear");

	char nameCopiedFile[] = "NewYearTree.txt";
	char nameCopy[] = "NewYearTree2.txt";

	copyingFile(nameCopiedFile, nameCopy);

	coutFile(nameCopy);

	return 0;
}
