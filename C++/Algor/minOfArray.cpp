#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

    // int sizeMass=5,
    //     mass[]={5,123,2321,1,99};
    //
    //     coutArray(mass, 5, " ");
    //     std::cout << endl << minOfArray(mass,5)+1 << '\n';

    int size_array=1000,
        array[size_array],
        maxArray=100,
        minArray=50;

    randDigits(array, size_array, maxArray,minArray);
    coutArray(array, size_array);







    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
