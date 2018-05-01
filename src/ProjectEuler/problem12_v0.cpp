#include <iostream>
#include <iomanip>      // std::setw

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {

    int number=0,
        quantity_divisors=0,
        i=1;

    while (quantity_divisors<=500)
    {
        number+=i;
        quantity_divisors=divisors(number,1000);
        std::cout << number << " - " <<" number2 = "<< quantity_divisors;
        std::cout << "" << '\n';
        i++;
    }








    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem12_v0.cpp -o Vlad
