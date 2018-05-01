#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

    int x;


    std::cout << "Input number" << '\n';
    //std::cin >> x;
    x=45;
    unsigned long long int array_fib[x];
        array_fib[0]=0;
        array_fib[1]=1;
        array_fib[2]=1;
    for(int i=2;i<x;i++)
    {
        array_fib[i]=array_fib[i-1]+array_fib[i-2];
        //std::cout << array_fib[i] << '\n';
    }
    std::cout << array_fib[x-1] << '\n';
    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
