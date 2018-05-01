#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

unsigned long long int fib(int x)
{
    if (x<3)
        return 1;
    else
        return fib(x-1)+fib(x-2);
}

int main(int argc, char const *argv[]) {
    int x;
    std::cout << "Input number" << '\n';
    //std::cin >> x;
    x=45;
    std::cout << "wynik = " << fib(x) << '\n';
    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
