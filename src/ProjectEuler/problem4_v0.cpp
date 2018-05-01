#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {

    int x;
    int size_x;
    int max_x,
        max_x_i,
        max_x_j;
    int size_arr_min_i=100,
        size_arr_max_i=999,
        size_arr_min_j=size_arr_min_i,
        size_arr_max_j=size_arr_max_i;

    for(int i=size_arr_min_i;i<=size_arr_max_i;i++)
    {
        for(int j=size_arr_min_j;j<=size_arr_max_j;j++)
        {
            x=i*j;
            size_x=discharge(x);
            //std::cout << "x = " << x <<";  ";
            //std::cout << size_x << '\n';

            if(discharge(x)==6)
            {
                if(
                  (getDigitWhithNumber(x,1)==getDigitWhithNumber(x,6))
                &&(getDigitWhithNumber(x,2)==getDigitWhithNumber(x,5))
                &&(getDigitWhithNumber(x,3)==getDigitWhithNumber(x,4))
                  )
                {
                    //std::cout << i<<" * "<<j<<" = " << x << "        size_x = "<<size_x<<'\n';
                    if (max_x<x) {
                        max_x=x;
                        max_x_i=i;
                        max_x_j=j;
                    }
                }
            }
            if(discharge(x)==5)
            {
                if(
                  (getDigitWhithNumber(x,1)==getDigitWhithNumber(x,5))
                &&(getDigitWhithNumber(x,2)==getDigitWhithNumber(x,4))
                  )
                {
                    //std::cout << i<<" * "<<j<<" = " << x << "        size_x = "<<size_x<<'\n';
                    if (max_x<x) {
                        max_x=x;
                        max_x_i=i;
                        max_x_j=j;
                    }
                }
            }
        }
    }

    cout<<"Max x = "<<max_x<<"  ("<<max_x_i<<"*"<<max_x_j<<")"<<endl;

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem4_v0.cpp -o Vlad
