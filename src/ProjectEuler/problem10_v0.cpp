#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {
    long long sum=0;
    int primeNumb=0,
        max_primeNumb=2000000;

    while (primeNumb<max_primeNumb)
    {
        if (primeNumber(primeNumb)==true)
        {
            sum+=primeNumb;
            //cout<<primeNumb<<", ";
        }
        primeNumb++;
    }

std::cout << "Sum = " << sum << '\n';

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem10_v0.cpp -o Vlad
