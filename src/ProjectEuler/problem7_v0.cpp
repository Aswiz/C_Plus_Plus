#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {

    int number=2,
        index_number=0;

        while (index_number!=10001)
        {
            if(primeNumber(number)==true)
            {
                index_number++;
                //std::cout << "number - " <<number<<" index - "<<index_number<< '\n';
            }
            number++;
        }

    std::cout << "number - " <<number<<" index - "<<index_number<< '\n';

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem7_v0.cpp -o Vlad
