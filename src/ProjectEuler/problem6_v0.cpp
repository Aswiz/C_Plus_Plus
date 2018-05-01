#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {

    int size=100,
        sumOfSquares=0, //sum of the squares
        squareOfSum=0, //square of the sum
        difference=0; //= squareOfSum - sumOfSquares

    for(int i=1;i<=size;i++)
    {
        sumOfSquares+=i*i;
        squareOfSum+=i;
    }
    squareOfSum=squareOfSum*squareOfSum;
    difference=squareOfSum-sumOfSquares;

    cout<<squareOfSum<<" - "<<sumOfSquares<<" = "<<difference<<endl;

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem6_v0.cpp -o Vlad
